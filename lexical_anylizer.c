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

int	is_word(const char *lex, int l, int r)
{
	if (ft_isalnum(lex[l])
		&& ft_isalnum(lex[r])
		&& is_space(lex[r + 1]))
		return (WORD);
	return (0);
}

int is_exp_field(const char *lex, int l, int r)
{
	if (lex[l] == '\"'
		&& lex[l] == lex[r]
		&& is_space(lex[r + 1]))
		return (EXPFIELD);
	return (0);
}

int	is_field(const char *lex, int l, int r)
{
	if (lex[l] == '\''
		&& lex[l] == lex[r]
		&& is_space(lex[r + 1]))
		return (FIELD);
	return (0);
}

int is_redirect_in(char *lex, int l, int r)
{
	if (!ft_strncmp(lex, "<", r - l + 1)
		&& is_space(lex[r + 1]))
		return (REDIN);
	return (0);
}

int is_redirect_out(char *lex, int l, int r)
{
	if (!ft_strncmp(lex, ">", r - l + 1)
		&& is_space(lex[r + 1]))
		return (REDOUT);
	return (0);
}

int is_here_doc(char *lex, int l, int r)
{
	if (!ft_strncmp(lex, "<<", r - l + 1)
		&& is_space(lex[r + 1]))
		return (HERED);
	return (0);
}

int is_redirect_app(char *lex, int l, int r)
{
	if (!ft_strncmp(lex, ">>", r - l + 1)
		&& is_space(lex[r + 1]))
		return (REDAPP);
	return (0);
}

int	is_pipe(char *lex, int l, int r)
{
	if (!ft_strncmp(lex, "|", r - l + 1)
	&& is_space(lex[r + 1]))
		return (1);
	return (0);
}

int is_valid(char *cmd, int l, int r)
{
	return (is_exp_field(cmd, l, r)
		+ is_field(cmd, l, r)
		+ is_word(cmd, l, r)
		+ is_pipe(cmd, l, r)
		+ is_redirect_in(cmd, l, r)
		+ is_redirect_out(cmd, l, r)
		+ is_redirect_app(cmd, l, r)
		+ is_here_doc(cmd, l, r));
}

t_token	*retrieve_tkn(char *cmd, int l, int r)
{
	char	*content;
	int		group;

	group = is_valid(cmd, l, r);
	if (group)
	{
		content = ft_substr(cmd, l, r - l + 1);
		return (init_tkn_list(content, group));
	}
	return (NULL);
}

t_token *get_tkn_list_from_cmd(char *cmd)
{
	t_token	*tkn_list;
	t_token *tkn;
	int		r;
	int		l;

	if (cmd)
	{
		r = 0;
		l = 0;
		while (cmd[r] != '\0')
		{
			tkn = retrieve_tkn(cmd, l, r);
			if (tkn)
			{
				add_tkn_back(&tkn_list, tkn);
				l = r + 1;
			}
			r++;
		}
		return (tkn_list);
	}
	return (NULL);
}