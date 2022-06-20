#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <../libft/libft.h>


char    **ft_qsplit(const char *input_str, char c);
t_token	*init_tkn_list(char *content, int group);
void    add_tkn_back(t_token **tkn_list, t_token *new_tkn);

#endif