#include "executor.h"

static void	init_returncode(char **envp[])
{
	if (envp)
		*envp = insert_env(*envp, ft_strdup("?=0"));
}

static int	init_pwd(const char *args[], char **envp[])
{
	char	*cwd;
	char	*msg_err;

	msg_err = "error retrieving current directory: "
		"getcwd: cannot access parent directories: "
		"No such file or directory";
	cwd = get_cwd(args[0], NULL);
	if (cwd)
	{
		insert_key_value("?PWD", cwd, envp);
		if (set_value_by_key("PWD", cwd, *envp))
			insert_key_value("PWD", cwd, envp);
		free(cwd);
		return (EXIT_SUCCESS);
	}
	ft_putstr_fd("shell-init: ", 2);
	ft_putendl_fd(msg_err, 2);
	ft_putstr_fd("sh_makepath: ", 2);
	ft_putendl_fd(msg_err, 2);
	return (EXIT_FAILURE);
}

static void	reset_oldpwd(char **envp[])
{
	char	**var_env;
	char	*new_var;

	var_env = get_ptr_env("OLDPWD", *envp);
	new_var = ft_strdup("OLDPWD");
	if (var_env)
		set_var_env(var_env, new_var);
	else
		*envp = insert_env(*envp, new_var);
}

char	**init_subshell(const char *args[], char *in_envp[])
{
	char	**envp;

	envp = ft_2arr_dup((const char **)in_envp);
	init_returncode(&envp);
	init_pwd(args, &envp);
	reset_oldpwd(&envp);
	update_shlvl(&envp);
	return (envp);
}
