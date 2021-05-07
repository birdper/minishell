#include "executor.h"

static void	print_err_shlvl(char *lvl)
{
	int32_t		len;
	char		*msg_error;

	len = ft_strlen(lvl) + 60;
	msg_error = (char *)malloc(sizeof(char) * (len + 1));
	*msg_error = '\0';
	ft_strlcat(msg_error, "minishell: warning: shell level (", len + 1);
	ft_strlcat(msg_error, lvl, len + 1);
	ft_strlcat(msg_error, ") too high, resetting to 1\n\0", len + 1);
	write(2, msg_error, len + 1);
	free(msg_error);
}

static char	*check_shlvl(char *str_lvl)
{
	int32_t		lvl;

	if (ft_isempty_str(str_lvl) || is_notnumber(str_lvl))
		return (ft_strdup("1"));
	lvl = ft_atoi(str_lvl);
	if (lvl >= 1000)
	{
		print_err_shlvl(ft_itoa(++lvl));
		return (ft_strdup("1"));
	}
	else if (lvl < 0)
		return (ft_strdup("0"));
	else if (lvl == 999)
		return (ft_strdup(""));
	else
		return (ft_itoa(++lvl));
}

void	update_shlvl(char **envp[])
{
	char	**var_env;
	char	*old_value;
	char	*new_value;

	var_env = get_ptr_env("SHLVL", *envp);
	if (var_env)
	{
		old_value = get_value_by_varenv(*var_env);
		new_value = check_shlvl(old_value);
		free(old_value);
	}
	else
		new_value = ft_strdup("1");
	if (set_value_by_key("SHLVL", new_value, *envp))
		insert_key_value("SHLVL", new_value, envp);
	free(new_value);
}
