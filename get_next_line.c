#include "get_next_line.h"

char 	*read_line(char **save, int *rsize, char **temp, int fd)
{
	while (!ft_strchr(*save,'\n') && *rsize > 0)
	{

		*temp = ft_strdup(*save);
		*save = (char *)malloc(BUFF_SIZE + ft_strlen(*temp));
		ft_strcpy(*save, *temp);
		*rsize = read(fd, (*save + ft_strlen(*temp)), BUFF_SIZE);
		*(*save + ft_strlen(*temp) + BUFF_SIZE) = '\0';
		free(*temp);
	}	
	return("yes");
}

int	check_save(char **save, char **temp, char ***line)
{
	char *temp2;

	if (ft_strchr(*save, '\n'))
	{
		if (ft_strlen(*save) == 1)
		{
			ft_strdel(save);
			return(0);
		}
		*temp = ft_strchr(*save, '\n') + 1;
		*(ft_strchr(*save, '\n')) = '\0';
		**line = ft_strdup(*save);
		if (**temp != '\0')
		{
			temp2 = *save;
			*save = ft_strdup(*temp);
			ft_strdel(&temp2);
		}
		else 
			ft_strdel(save);
		return (0);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char *save = NULL;
	char		*temp;
	int			rsize;

	rsize = 1;
	if (!save)
	{
		save = (char *)malloc(BUFF_SIZE + 1);
		rsize = read(fd, save, BUFF_SIZE);
		save[rsize] = '\0';
		if (rsize == 0 || (rsize == 1 && ft_strcmp(save, "\n")))
		{
			ft_strdel(&save);
			return(0);
		}
	}
	read_line(&save, &rsize, &temp, fd);
	if (rsize < 0)
	{
		if (*save)
			ft_strdel(&save);
		return(-1);
	}
	if (check_save(&save, &temp, &line) && *save && !(ft_strchr(save, '\n')) && rsize == 0)
	{
		*line = ft_strdup(save);
		ft_strdel(&save);
	}
	return(1);
}
/*
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

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
		ft_putstr("output: ");
		ft_putendl(line);
		free(line);
	}	
	if (argc == 2)
		close(fd);
	return (0);
}*/