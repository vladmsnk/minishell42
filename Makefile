NAME =	minishell

CC =	gcc
CFLAGS = -g  -MMD

RM =	rm -rf

SRC =   main.c \
		lexical_anylizer.c	\
		token_list.c 

INC = 	-I libft	\
		-I includes 

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :	
		$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@make -C ./libft/
			@make bonus -C ./libft/
			$(CC) $(CFLAGS) $(LD_FLAGS) $(OBJS) ./libft/libft.a -o $(NAME) -lreadline

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)
			@make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			@make fclean -C libft/

re: 		fclean all

-include $(DEP)