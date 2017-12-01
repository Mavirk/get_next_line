#include "Libft/libft.h"

char *printtest(char *add)
{
	static char *test = NULL;
	char *temp;
	int old = 0;

	if (test)
	{
		old = ft_strlen(test);
		temp = ft_strdup(test);
		free(test);
	}
    test = (char*)malloc(ft_strlen(add) + old + 1);
    if (temp)
    {
    	ft_strcpy(test, temp);
    	free(temp);
    }
    ft_strcpy((test + old), add);
    return(test);
}

int main(void)
{
    ft_putendl(printtest("fee"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("fi"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("fo"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("\nfuem"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("\nfuem"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("1fudffm"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("2fudm"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("3fufsm"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("  dofug"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("  	erligbseirg\nawefyvasu"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("aewufbasduvb"));
    ft_putendl("\nBREAK\n");
    ft_putendl(printtest("fviubs"));
    ft_putendl("\nBREAK\n");
}

/*
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int             main(void)
{
    char        *line;
    int         fd;
    int         ret;
    int         count_lines;
    char        *filename;
    int         errors;

    filename = "test.txt";
    fd = open(filename, O_RDONLY);
    if (fd > 2)
    {
        count_lines = 0;
        errors = 0;
        line = NULL;
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            if (count_lines == 0 && strcmp(line, "1234567") != 0)
                errors++;
            if (count_lines == 1 && strcmp(line, "abcdefgh") != 0)
                errors++;
            count_lines++;
            if (count_lines > 50)
                break ;
        }
        close(fd);
        if (count_lines != 2)
            printf("-> must have returned '1' twice instead of %d time(s)\n", count_lines);
        if (errors > 0)
            printf("-> must have read \"1234567\" and \"abcdefgh\"\n");
        if (count_lines == 2 && errors == 0)
            printf("OK\n");
    }
    else
        printf("An error occured while opening file %s\n", filename);
    return (0);
}

#include <fcntl.h>
int     main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc == 1)
        fd = 0;
    else if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        return (2);
    while (get_next_line(fd, &line) == 1)
    {
        ft_putstr("output: ");
        ft_putendl(line);
        free(line);
    }   
    if (argc == 2)
        close(fd);
    return (0);
}*/

