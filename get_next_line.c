#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char 	*save = NULL;
	char			*tempadd;
	int 			readsize;

	if (!save)
	{
		save = malloc(BUFF_SIZE);
		readsize = read(fd, save, BUFF_SIZE);
		if (readsize < 1)
			return (0);
		while (readsize > 0 && !(ft_strchr(save, '\n')))
		{
			tempadd = ft_strdup(save);
			free(save);
			save = (char*)malloc(BUFF_SIZE + ft_strlen(tempadd) + 1);
			save = ft_strcpy(save,tempadd);
			readsize = read(fd, (save + ft_strlen(tempadd)), BUFF_SIZE);
			free (tempadd);	
		}
	}
	else
	{
		readsize = 1;
		while (readsize > 0 && !(ft_strchr(save, '\n')))
		{
			tempadd = ft_strdup(save);
			save = (char*)malloc(BUFF_SIZE + ft_strlen(tempadd) + 1);
			save = ft_strcpy(save,tempadd);
			readsize = read(fd, (save + ft_strlen(tempadd)), BUFF_SIZE);
			free (tempadd);	
		}
	}
	tempadd = save;
	if (readsize != 0)
		*ft_strchr(tempadd, '\n') = '\0';
	*line = ft_strdup(save);
	save = (ft_strchr(save, '\0') + 1);
	if (readsize == 0)
		save = NULL;
	return (1);
}
/*	
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
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr("output ");
		ft_putendl(line);
		free(line);
	}	
	if (argc == 2)
		close(fd);
	return (0);
}*/