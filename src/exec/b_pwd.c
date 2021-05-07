#include "executor.h"

char	*get_cwd(const char *command_name, const char *arg)
{
	char	*dir;

	errno = 0;
	dir = getcwd(NULL, 0);
	if (errno)
	{
		print_err("minishell", command_name, arg, strerror(errno));
		return (NULL);
	}
	return (dir);
}

char	*get_cwd_pwd(char **envp)
{
	char	**var_env;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		var_env = get_ptr_env("?PWD", envp);
		if (var_env)
			return (get_value_by_varenv(*var_env));
		return (NULL);
	}
	return (cwd);
}

int	b_pwd(char *envp[])
{
	char	*cwd;

	errno = 0;
	cwd = get_cwd_pwd(envp);
	if (cwd == NULL)
	{
		ft_putendl_fd("pwd: error retrieving current directory: "
			"getcwd: cannot access parent directories: "
			"No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(cwd, 1);
	free(cwd);
	return (EXIT_SUCCESS);
}
