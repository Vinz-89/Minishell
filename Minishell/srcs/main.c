#include "../include/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	// ft_putstr_fd("Hello Worlds\n", 1);

	char *line = readline(">");

	if (line == NULL)
    {
        printf("EOF detected. Exiting...\n");
        return (0);
    }

	printf("line: %s\n", line);

	free(line);
	return (0);
}
