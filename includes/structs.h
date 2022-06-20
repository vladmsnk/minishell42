#ifndef STRUCTS_H
# define STRUCTS_H

# define SPACE 0
# define WORD 1
# define FIELD 2
# define EXPFIELD 3
# define REDOUT 4
# define REDIN 5
# define REDAPP 6
# define HERED 7 // >>
# define PIPE 8 // <<


typedef struct s_token
{
	void			*content;
	t_token			*next;
    int             group;
}	t_token;

typedef struct s_info
{	
	char		**envp;
	int			exit_t;
}	t_info;


#endif