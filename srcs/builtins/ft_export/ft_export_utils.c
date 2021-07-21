
#include "../../../includes/libminishell.h"

char	*get_name(char *var)
{
	char	*name;
	int	index;

	if (!ft_strchr(var, '='))
		return (ft_strdup(var));
	index = 0;
	while (var[index] != '=')
		index++;
	name = ft_strndup(var, index);
	return (name);
}

int	already_exist(t_list *lst, char *var)
{
	char	*tmp;
	char	*name;

	name = get_name(var);
	tmp = search_env(lst, name);
	if (!tmp[0])
	{
		free(name);
		free(tmp);
		return (0);
	}
	free(name);
	free(tmp);
	return (1);
}
