#include "includes/headers.h"
#include "includes/structs.h"

int main(int argc, char **argv)
{
	char	*str;
	int		flag;

	flag = 0;
	while (1)
	{
		str = readline("Shell: ");
		printf("%s\n", str);
		free(str);
	}
	printf("%p\n", argv);
	printf("%d\n", argc);
	return (0);
}