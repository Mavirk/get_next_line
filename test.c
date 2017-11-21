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

