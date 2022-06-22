#include "includes/headers.h"
#include "includes/structs.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\n'
		|| c == '\t' || c == '\v'
		|| c == '\v' || c == '\r')
		return (1);
	return (0);
}

t_token *get_lexems(const char *cmd)
{
    int	lhs;
	int rhs;
	int	group;
	char	*content;
	t_token *lst;
	t_token	*tmp;

	lhs = 0;
	group = 0;
	lst = NULL;
	rhs = 0;
	while (cmd[rhs] != '\0')
	{
		if (!group)
		{
			if (cmd[rhs] == '\"')
				group = 1;
			else if (cmd[rhs] == '\'')
				group = 2;
			else if (ft_strchr(">|<", cmd[rhs]))
				group = 3;
			else if (ft_isalnum(cmd[rhs]))
				group = 4;
			else if (!is_space(cmd[rhs]))
				group = 5;
			lhs = rhs;
		}
		if (((group == 1 && cmd[rhs] == '\"') 
		|| (group == 2 && cmd[rhs] == '\'')
		|| (group == 3 && ft_strchr(">|<", cmd[rhs]))
		|| (group == 4 && ft_isalnum(cmd[rhs]))
		|| (group == 5 && !is_space(cmd[rhs])))
			&& (is_space(cmd[rhs + 1]) || cmd[rhs + 1] == '\0'))
		{
			content = ft_substr(cmd, lhs, rhs - lhs + 1);
			tmp = init_tkn_list(content, group);
			add_tkn_back(&lst, tmp);
			group = 0;
		}
		rhs++;
	}
	return (lst);
}
