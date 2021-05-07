#include "executor.h"

static int	check_exitcode(const char *arg, const char *command_name)
{
	int		nbr;

	if (is_notnumber(arg))
	{
		ft_putendl_fd(command_name, 2);
		print_err("minishell", command_name, arg, "numeric argument required");
		exit(255);
	}
	nbr = ft_atoi(arg);
	return (nbr);
}

int	b_exit(const char *args[])
{
	int32_t		size;
	int32_t		status;

	size = ft_2arr_get_rows(args);
	status = EXIT_SUCCESS;
	if (args[1])
	{
		status = check_exitcode(args[1], args[0]);
		if (size > 2)
		{
			print_err("minishell", args[0], NULL,
				"too many arguments");
			return (EXIT_FAILURE);
		}
	}
	ft_putendl_fd(args[0], 2);
	exit(status & 0377);
}
