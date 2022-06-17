#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
    int             group;
}	t_list;

typedef struct s_info
{	
	t_builtin_ptr builtins[7];
	char		**envp;
	int			exit_t;
}	t_info;

typedef int(* t_builtin_ptr)(t_list *, t_info *);


#endif