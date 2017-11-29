#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	char		*temp;
	char 		*temp2;
	int			rsize;


	rsize = 0;
	if (!save)
	{
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

	if (rsize < 0)
		return(-1);
	if (ft_strchr(save, '\n') && rsize > 0)
	{
		*(ft_strchr(save, '\n')) = '\0';
		*line = ft_strdup(save);
		temp = ft_strchr(save, '\0') + 1;
		if (temp)
		{
			temp2 = save;
			save = ft_strdup(temp);
			free(temp2);
			//ft_putstr("1");
			return (1);
		}
	}
	else if (ft_strchr(save, '\n') && rsize == 0)
	{
		*(ft_strchr(save, '\n')) = '\0';
		*line = ft_strdup(save);
		temp = ft_strchr(save, '\0') + 1;
		if (temp)
		{
			temp2 = save;
			save = ft_strdup(temp);
			free(temp2);
			//ft_putstr("2");
			return (1);
		}
	}
	else if (!(ft_strchr(save, '\n')) && rsize == 0 )
	{
		if (ft_strlen(save) > 0)
		{
			save[ft_strlen(save)] = '\0';
			//ft_putstr("3");
			*line = ft_strdup(save);
			free (save);
			return(1);
		}
		else
		{
			free (save);
			//ft_putstr("exit");
			return(0);
		}
	}
	free(save);
	return(0);
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
		//ft_putstr("output ");
		ft_putendl(line);
		free(line);
	}	
	if (argc == 2)
		close(fd);
	return (0);
}