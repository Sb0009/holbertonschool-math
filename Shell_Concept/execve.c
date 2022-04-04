#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
* main - fonction
* @ac: counter
* @av: vector array
* Return: 0
*/

int main(void)
{
	char *argv[] = {"/bin/ls", "-lha", NULL};

	if (execve(argv[0], argv, NULL) == -1)

	  perror("Error:");
}
