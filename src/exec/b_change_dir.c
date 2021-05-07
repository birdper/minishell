#include "executor.h"

static int	print_err_cd(const char *msg_err)
{
	print_err("minishell", "cd", NULL, msg_err);
	return (EXIT_FAILURE);
}

static int	change_dir(const char *dst_path)
{
	if (dst_path)
	{
		if (ft_isempty_str(dst_path))
			return (EXIT_SUCCESS);
		errno = 0;
		if (chdir(dst_path))
		{
			print_err_cd(strerror(errno));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	cd_to_home(const char *arg, char ***envp)
{
	char	*path_home;

	if (arg == NULL)
	{
		path_home = get_value_by_key("HOME", *envp);
		if (path_home == NULL)
		{
			print_err_cd("HOME not set");
			return (EXIT_FAILURE);
		}
		change_dir(path_home);
		free(path_home);
	}
	return (EXIT_SUCCESS);
}

int	b_cd(const char *args[], char **envp[])
{
	if (change_dir(args[1]))
		return (EXIT_FAILURE);
	if (cd_to_home(args[1], envp))
		return (EXIT_FAILURE);
	update_pwd(args[1], envp);
	return (EXIT_SUCCESS);
}
