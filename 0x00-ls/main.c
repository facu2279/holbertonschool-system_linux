#include "holberton.h"
/**
 * main - main function
 * Return: returns 0 when run correctly
 */
int main()
{

	DIR *dir;
	unsigned int size = 0;
	int i = 0;
	char **array = NULL;

	dir = opendir(".");
	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			size++;

	closedir(dir);

	array = malloc(size * sizeof(char *);
	if (array == NULL)
		exit(98);

	dir = opendir(".");
	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
		{
			array[i] = read->d_name;
			i++;
		}
	array[i] = '\0';

	closedir(dir);

	printarr(array);
	free(array);
	return (0);
}

/**
 * printarr - prints an array
 * @array: array to be printed
 */
void printarr(char **array)
{
	int i = 0;

	for (i = 0; array[i] != '\0'; i++)
		printf("%s  ", array[i]);
	printf("\n");
}
