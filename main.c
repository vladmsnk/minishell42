#include "includes/headers.h"
#include "includes/structs.h"

int main(int argc, char **argv)
{	
	t_info 	info;
	char	*str;
	
	while (!info.exit_t)
	{
		str = readline("Shell: ");
		
	}	
	printf("%d\n", argc);
	printf("%p", argv);
	return (0);
}