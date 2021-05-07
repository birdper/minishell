#include "executor.h"

static char	*get_cwd_relative(const char *dst_path, char **envp)
{
	char		*pwd_value;
	char		*cwd;
	char		*retrieving_path;
	int32_t		len;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL
		&& (!ft_strcmp(dst_path, "..") || !ft_strcmp(dst_path, ".")))
	{
		ft_putendl_fd("cd: error retrieving current directory: "
			  "getcwd: cannot access parent directories: "
			  "No such file or directory", 2);
		pwd_value = get_value_by_key("?PWD", envp);
		len = ft_strlen(pwd_value) + ft_strlen(dst_path) + 1;
		retrieving_path = ft_get_alloc_str(len);
		concat(retrieving_path, pwd_value, "/", len + 1);
		ft_strlcat(retrieving_path, dst_path, len + 1);
		free(pwd_value);
		return (retrieving_path);
	}
	return (cwd);
}

static void	set_pwd(const char *dst_path, char **envp)
{
	char	*cwd;

	errno = 0;
	cwd = get_cwd_relative(dst_path, envp);
	set_value_by_key("PWD", cwd, envp);
	set_value_by_key("?PWD", cwd, envp);
	free(cwd);
}

static void	set_oldpwd(char ***envp)
{
	char	*oldpwd_value;

	if (get_ptr_env("OLDPWD", *envp) == NULL)
		return ;
	oldpwd_value = get_value_by_key("PWD", *envp);
	if (oldpwd_value == NULL)
		oldpwd_value = ft_strdup("");
	set_value_by_key("OLDPWD", oldpwd_value, *envp);
	free(oldpwd_value);
}

void	update_pwd(const char *dst_path, char **envp[])
{
	set_oldpwd(envp);
	set_pwd(dst_path, *envp);
}
