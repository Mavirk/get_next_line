#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char 	*save = NULL;
	char			*tempadd;
	char			*ret;
	char			*test;
	char			*leftp;
	char			*carryp;
	int 			readsize;

if (!save)
{
	save = malloc(BUFF_SIZE);
	readsize = read(fd, save, BUFF_SIZE);
	if ((leftp = ft_strchr(save, '\n')))
	{ 
		*(save + BUFF_SIZE + 1) = '\0'; 
		*leftp = '\0'; 
		*line = strdup(save);
		leftp++;
		carryp = strdup(leftp); 
		free(save);
		save = strcpy(save, carryp);
	}
	else 
	{	
		while (readsize > 0 && !(ft_strchr(save, '\n')))
		{
			tempadd = ft_strdup(save);
		//	ft_putstr("save ");			
		//	ft_putendl(save);
		//	ft_putstr("tempadd ");
		//	ft_putendl(tempadd);
			free(save);
			save = (char*)malloc(BUFF_SIZE + strlen(tempadd) + 1);
			save = ft_strcpy(save,tempadd);
			test = (save + ft_strlen(tempadd));
			readsize = read(fd, test, BUFF_SIZE);	
		//	ft_putendl(tempadd);
			//ft_putendl(" : tempadd after read");
			ret = ft_strdup(tempadd);
			ret[ft_strlen(tempadd)] = '\0';
		//	ft_putstr("save ");			
		//	ft_putendl(save);
		//	ft_putstr("tempadd ");
		//	ft_putendl(tempadd);
		//	ft_putstr("ret ");
		//	ft_putendl(ret);
			free (tempadd);	
		} 
	}
	*ft_strchr(save, '\n') = '\0';
	ret = save;
	*line = ft_strdup(ret);
return(1);
}
return(1);
}	

#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	if(get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);	
	}
	if (argc == 2)
		close(fd);
	return (0);
}