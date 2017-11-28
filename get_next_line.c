#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	char		*temp;
	int			rsize;

	rsize = 0;
	if (!save)
	{
		ft_putendl(save);
		save = (char *)malloc(BUFF_SIZE + 1);
		rsize = read(fd, save, BUFF_SIZE);
		while (!ft_strchr(save,'\n') && rsize > 0)
		{
			temp = ft_strdup(save);
			free(save);
			save = (char *)malloc(BUFF_SIZE + ft_strlen(temp));
			save = ft_strcpy(save, temp);
			rsize = read(fd, (save + ft_strlen(temp)), BUFF_SIZE);
			*(save + ft_strlen(temp) + BUFF_SIZE) = '\0';
			free(temp);
		}
	}
	else
	{
		rsize = 1;
		while (!ft_strchr(save,'\n') && rsize > 0)
		{
			temp = ft_strdup(save);
			save = (char *)malloc(BUFF_SIZE + ft_strlen(temp));
			save = ft_strcpy(save, temp);
			rsize = read(fd, (save + ft_strlen(temp)), BUFF_SIZE);
			*(save + ft_strlen(temp) + BUFF_SIZE) = '\0';
			free(temp);
		}
	}
	if((ft_strchr(save, '\n')))
		*(ft_strchr(save, '\n')) = '\0';
	else
		save[ft_strlen(save)] = '\0';
	*line = ft_strdup(save);
	if (rsize == 0  && ft_strlen(save))
	{
		ft_putnbr(ft_strlen(save));
		return (1);
	}
	else if (rsize == 0)
		return (0);
	save = (ft_strchr(save, '\0') + 1);
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
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr("output ");
		ft_putendl(line);
		free(line);
	}	
	if (argc == 2)
		close(fd);
	return (0);
}