#include "executor.h"
#include <sys/stat.h>

static char	*search_exec(char **paths, char *filename)
{
	DIR				*dir;
	struct dirent	*file;
	int32_t			i;

	i = 0;
	while (paths[i])
	{
		dir = opendir(paths[i]);
		while (1)
		{
			file = readdir(dir);
			if (file == NULL)
				break ;
			if (ft_strcmp(file->d_name, filename) == 0)
				return (concat_path(paths[i], filename));
		}
		i++;
	}
	closedir(dir);
	return (NULL);
}

static int	check_file(char *pathname, char *command_name)
{
	struct stat		st;

	stat(pathname, &st);
	if (S_ISDIR(st.st_mode))
	{
		print_err("minishell", command_name, NULL, "is a directory");
		exit(126);
	}
	if (S_ISREG(st.st_mode))
	{
		if (!(st.st_mode & S_IXUSR))
		{
			print_err("minishell", command_name, NULL, "Permission denied");
			exit(126);
		}
	}
	return (EXIT_SUCCESS);
}

static int	is_not_pathname(char *filename, char *args[])
{
	int		index;
	int		diff;

	index = ft_last_indexof(filename, '/');
	diff = ft_strlen(filename) - 1 - index;
	if (index >= 0 && diff >= 0)
	{
		check_file(filename, args[0]);
		return (0);
	}
	return (1);
}

int	outer_exec(char *filename, char *args[], char **envp)
{
	char	**paths;
	int		status;

	errno = 0;
	if (is_not_pathname(filename, args))
	{
		paths = get_paths(envp);
		filename = search_exec(paths, filename);
	}
	if (filename == NULL)
	{
		print_err("minishell", args[0], NULL, "command not found");
		exit(127);
	}
	check_file(filename, args[0]);
	status = execve(filename, args, export_envp(envp));
	if (errno)
	{
		print_err("minishell", args[0], NULL, strerror(errno));
		exit(127);
	}
	exit(status & 0377);
}
