#include <stdio.h>
#include <string.h>

/**
* main - fonction
* @ac: counter
* @av: vector, array
* Return: 0
*/

int main(void)
{
	char str[] = "Hello, le Shell c'est cool .";
	/**
	* Ne pas remplacer par char * str = " "; 
	* la zone de mémoire pointée serait constante 
	* et la fonction strtok planterait systématiquement.
	*/
	char *retour;

	retour = strtok(str, " ");

	while (retour)
	{
		printf("%s\n", retour);
		retour = strtok(NULL, " ");
	}
	return (0);
}
