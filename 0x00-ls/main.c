#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
/**
* main - main function
* Return: returns 0 when run correctly
*/

int main(void)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(".");

	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			printf("%s ", read->d_name);
	printf("\n");
	closedir(dir);
	return (0);
}
