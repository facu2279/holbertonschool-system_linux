#include "holberton.h"
/**
* main - main function
* Return: returns 0 when run correctly
*/

int main(void)
{

	print_dir(".");
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
