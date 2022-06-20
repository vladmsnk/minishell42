#include "includes/headers.h"
#include "includes/structs.h"

t_token	*init_tkn_list(char *content, int group)
{
	t_token	*new_tkn;

	new_tkn = (t_token *)malloc(sizeof(t_token));
	if (!new_tkn)
		return (NULL);
	new_tkn->content = content;
	new_tkn->group = group;
	new_tkn->next = NULL;
	return (new_tkn);
}

t_token *get_last_tkn(t_token *tkn_list)
{
	if (tkn_list)
	{
		while (tkn_list->next != NULL)
			tkn_list = tkn_list->next;
		return (tkn_list);
	}
	return (NULL);
}

void add_tkn_back(t_token **tkn_list, t_token *new_tkn)
{
	t_token **head;

	if (*tkn_list == NULL)
		*tkn_list = new_tkn;
	else
	{
		head = tkn_list;
		get_last_tkn(tkn_list)->next = new_tkn;
	}
}