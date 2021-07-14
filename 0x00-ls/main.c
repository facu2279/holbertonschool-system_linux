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

	if (argc == 1)
		print_dir(".");
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (dir_check(argv[i]) == 0)
			{
				/**
				* fprintf(stderr, "./hls: cannot access %s:
				* No such file or directory\n", argv[i]);
				* exit(2);
				*/
				printf("agregar errores\n");
			}
			else
			{
				printf("%s:\n", argv[i]);
				print_dir(argv[i]);
				if (i != argc - 1)
					printf("\n");
			}
		}
	}
	return (0);
}

/**
* print_dir - print_dir
* @path: aaa
*/
void print_dir(char *path)
{
	struct dirent *read;
	DIR *dir;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			printf("%s ", read->d_name);
	printf("\n");
	closedir(dir);

}

/**
* print_dir_vertical - print_dir
* @path: aaa
*/
void print_dir_vertical(char *path)
{
	struct dirent *read;
	DIR *dir;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			printf("%s\n", read->d_name);
	closedir(dir);

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
