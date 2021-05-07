#include "executor.h"

int32_t	executor(t_list *list_commands, char **envp[])
{
	int		count_commands;
	int		status;

	status = 0;
	if (list_commands)
	{
		count_commands = ft_lstsize(list_commands);
		if (count_commands > 1)
			status = run_pipeline(list_commands, *envp, count_commands);
		else
			status = simple_command(list_commands->content, envp);
		set_status(*envp, status & 0377);
	}
	return (status);
}
