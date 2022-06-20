#include <stdio.h>
#include <stdlib.h>

#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char *line;

	line = readline("test");
    printf( "%c\n", line[1]);
    return 0;
}