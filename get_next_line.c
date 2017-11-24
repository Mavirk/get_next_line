#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char 	*save = NULL;
	char			*tempadd;
	char			*ret;
	char			*test;
	int 			readsize;

	if (!save)
	{
		ft_putstr("first iteration");
		save = malloc(BUFF_SIZE);
		readsize = read(fd, save, BUFF_SIZE);
		while (readsize > 0 && !(ft_strchr(save, '\n')))
			{
				tempadd = ft_strdup(save);
				free(save);
				save = (char*)malloc(BUFF_SIZE + strlen(tempadd) + 1);
				save = ft_strcpy(save,tempadd);
				test = (save + ft_strlen(tempadd));
				readsize = read(fd, test, BUFF_SIZE);		
				ret = ft_strdup(tempadd);
				ret[ft_strlen(tempadd)] = '\0';
				free (tempadd);	
			} 
		*ft_strchr(save, '\n') = '\0';
		tempadd = ft_strchr(save, '\0');
		tempadd++;
		ret = save;
		*line = ft_strdup(ret);
		free (save);
		save = malloc(BUFF_SIZE - ft_strlen(ret));
		save = (tempadd);
		ft_putnbr(ft_strlen(save));
		ft_putstr(save);
		ft_putstr(tempadd);
		ft_putstr("2");
		free(ret);
		return (1);
	}
	else
	{
		ft_putstr("second iteration");
		ft_putnbr(ft_strlen(save));
		readsize = 1;
		if (readsize > 0 && !(ft_strchr(save, '\n')))
			{
				ft_putstr(save);
			} 
		*line = ft_strdup("test");
		return (1);
	}
	return (1);
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
	if (get_next_line(fd, &line) == 1)
		ft_putstr(" output : ");
		ft_putendl(line);
		free(line);
	if (get_next_line(fd, &line) == 1)
		ft_putstr(" output : ");
		ft_putendl(line);
		//free(line);		
	if (argc == 2)
		close(fd);
	return (0);
}