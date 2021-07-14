#include "holberton.h"
/**
 * main - main function
 * Return: returns 0 when run correctly
 */
int main()
{

	DIR *dir;


	dir = opendir(".");

	while ((read = readdir(dir)) != NULL)
    	printf("%s ", read->d_name);
	printf("\n");
	closedir(dir);

	return (0);
}
