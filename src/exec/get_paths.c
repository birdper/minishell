#include "executor.h"

char	**get_paths(char **envp)
{
	char		**env_var;
	char		**paths;
	char		*value;

	env_var = get_ptr_env("PATH", envp);
	if (env_var == NULL)
		return (ft_split("./", ':'));
	value = get_value_by_varenv(*env_var);
	paths = ft_split(value, ':');
	free(value);
	return (paths);
}

char	*concat_path(char *path, char *filename)
{
	char		*fullpath;
	size_t		size_fullpath;

	size_fullpath = ft_strlen(path) + ft_strlen(filename) + 2;
	fullpath = (char *)malloc(size_fullpath * sizeof(char));
	if (fullpath == NULL)
		return (NULL);
	*fullpath = '\0';
	ft_strlcat(fullpath, path, size_fullpath);
	ft_strlcat(fullpath, "/", size_fullpath);
	ft_strlcat(fullpath, filename, size_fullpath);
	return (fullpath);
}
