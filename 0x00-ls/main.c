	#include <stdio.h>
	#include <dirent.h>
	struct dirent *read;
	/**
	* main - main function
	* Return: returns 0 when run correctly
	*/
	int main()
	{
	DIR *dir;

	dir = opendir(".");

	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			printf("%s ", read->d_name);
	printf("\n");
	closedir(dir);

	return (0);
}
