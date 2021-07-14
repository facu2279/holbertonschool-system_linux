#include "holberton.h"
/**
* main - main function
* @argc: asda
* @argv: asdas
* Return: returns 0 when run correctly
*/

int main(int argc, char *argv[])
{
	int i;
	char *array = NULL, *options = NULL;

	options = option_finder(argc, argv);
	if (argc == 1)
	{
		array = bring_dir(".");
		printf("%s\n", array);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (dir_check(argv[i]) == 0)
			{
				printf("agregar errores\n");
			}
			else
			{
				array = bring_dir(argv[i]);
				printf("%s:\n", argv[i]);
				printf("%s", array);
				printf("\n");
				if (i != argc - 1)
					printf("\n");
			}
		}
	}

	free(array);
	if (options)
		free(options);
	return (0);
}


/**
* bring_dir - fetch and prints a certain directorys content
* @path: pwd to directory
* Return: x
*/
char *bring_dir(char *path)
{
	struct dirent *read;
	DIR *dir;
	int count = 0, i;
	char *array2 = NULL;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.')
		{
			count = count + _strlen(read->d_name);
			count++;
		}
	}

	array2 = malloc(count);
	closedir(dir);

	count = 0;
	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.')
		{
			for (i = 0; read->d_name[i] != '\0'; i++, count++)
				array2[count] = read->d_name[i];
			array2[count] = ' ';
			count++;
		}
	}
	array2[count - 1] = '\0';
	closedir(dir);

	return (array2);
}

/**
 * _strlen - fdfdf
 * @s: sksksks
 * Return: sassassass
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}

/**
* dir_check - function to check if directory exists.
* @dir_name: command or file name.
*
* Return: 1 on succes, 0 on failure.
*/
int dir_check(char *dir_name)
{
	DIR *dir = NULL;

	dir = opendir(dir_name);
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}
