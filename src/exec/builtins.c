#include "executor.h"

int	builtins(enum e_cmd command, const char **args, char **envp[])
{
	if (command == e_echo)
		return (b_echo(args));
	if (command == e_pwd)
		return (b_pwd(*envp));
	if (command == e_cd)
		return (b_cd(args, envp));
	if (command == e_unset)
		return (b_unset(args, *envp));
	if (command == e_export)
		return (b_export(args, envp));
	if (command == e_env)
		return (b_env(*envp));
	if (command == e_exit)
		return (b_exit(args));
	return (1);
}
