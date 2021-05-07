#include "executor.h"

static int32_t	set_fd(t_redirect *redir, int32_t *fd)
{
	if (*fd > 0)
		close(*fd);
	errno = 0;
	if (ft_isempty_str(redir->rd_file))
	{
		errno = ENOENT;
		print_err("minishell", NULL, redir->rd_file, strerror(errno));
		return (EXIT_FAILURE);
	}
	if (redir->rd_symbol == input)
		*fd = open(redir->rd_file, O_RDONLY);
	else if (redir->rd_symbol == output_append)
		*fd = open(redir->rd_file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		*fd = open(redir->rd_file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (*fd < 0)
	{
		print_err("minishell", NULL, redir->rd_file, strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	find_redirections(t_list *list_redirections, t_redir_fds *redir_fds)
{
	t_redirect	*redir;
	int32_t		*fd;

	redir_fds->redir_in = 0;
	redir_fds->redir_out = 0;
	errno = 0;
	while (list_redirections)
	{
		redir = (t_redirect *)list_redirections->content;
		fd = &(redir_fds->redir_out);
		if (redir->rd_symbol == input)
			fd = &(redir_fds->redir_in);
		if (set_fd(redir, fd))
			return (EXIT_FAILURE);
		list_redirections = list_redirections->next;
	}
	return (EXIT_SUCCESS);
}

void	set_redirections(t_redir_fds *redir_fds)
{
	if (redir_fds->redir_in > 0)
		dup2close(redir_fds->redir_in, STDIN_FILENO);
	if (redir_fds->redir_out > 0)
		dup2close(redir_fds->redir_out, STDOUT_FILENO);
}
