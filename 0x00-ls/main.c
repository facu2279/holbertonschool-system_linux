#include "holberton.h"

int main()
{
    DIR *dir;
    int i = 0;
    char **array;

    dir = opendir(".");

    while ((read = readdir(dir)) != NULL)
        if (read->d_name[0] != '.')
            i++;


    dir = opendir(".");

    array = malloc(i * sizeof(char *) + 1);
    if (!array)
        printf("error malloc");
    i = 0;
    while ((read = readdir(dir)) != NULL)
        if (read->d_name[0] != '.')
        {
            array[i] = read->d_name;
            i++;
        }
    array[i] = '\0';
    print_array(array);
    closedir(dir);
    return(0);
}

void print_array(char **array)
{
    int i;

    for (i = 0; array[i] != '\0'; i++)
        printf("%s ", array[i]);
    printf("\n");
}