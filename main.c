#include "includes/headers.h"
#include "includes/structs.h"

int main(int __unused argc, char __unused **argv)
{	
	// t_info 	info;
	t_token	*tokens;
	int		repeat;
	char	*cmd;


	while (1)
	{
		repeat = 1;
		while (repeat)
		{
			repeat = 0;
			cmd = readline("Shell: ");
			if (!cmd)
				repeat = 1;
		}
		tokens = get_lexems(cmd);
		t_token *tmp;
		tmp = tokens;
		while (tmp)
		{
			printf("%s\n", tmp->content);
			tmp = tmp->next;
		}
		/*
		split cmd into lexems
		put them into likend list - list of tokens
		each node of the list contains corresponding lexem and it group id
		*/
		// tokens = get_tkn_list_from_cmd(cmd);
		// while (tokens)
		// {
		// 	printf("%s\n", tokens->content);
		// 	tokens = tokens->next;
		// }

	}	
	return (0);
}