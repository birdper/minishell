#include "executor.h"

void	dup2close(int32_t oldfd, int32_t newfd)
{
	dup2(oldfd, newfd);
	close(oldfd);
}
