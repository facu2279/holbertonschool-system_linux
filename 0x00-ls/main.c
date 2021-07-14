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
	char opcion = 'x';

	if (argc == 1)
		print_dir(".");
	else if (argc == 2 && argv[1][1] == '1' && argv[1][0] == '-')
		print_dir_vertical(".");
	else
	{
		for (i = 0; i < argc; i++)
		{
			if (argv[i][0] == '-')
			{
				opcion = argv[i][1];
			}
		}
		if (opcion == 'x')
		{
			for (i = 1; i < argc; i++)
			{
				printf("%s:\n", argv[i]);
				print_dir(argv[i]);
				if (i != argc - 1)
					printf("\n");
			}
		}
		else if (opcion == '1')
		{
			for (i = 2; i < argc; i++)
			{
				printf("%s:\n", argv[i]);
				print_dir_vertical(argv[i]);
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
