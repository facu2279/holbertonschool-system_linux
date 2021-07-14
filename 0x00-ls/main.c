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
			printf("%s:\n", argv[i]);
			print_dir(argv[i]);
			if (i != argc - 1)
				printf("\n");
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
