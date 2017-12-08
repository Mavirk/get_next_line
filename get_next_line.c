/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:40:32 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/12/01 18:40:41 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(char **sv, int *rsize, char **t, int fd)
{
	while (!ft_strchr(*sv, '\n') && *rsize > 0)
	{
		 *t = ft_strdup(*sv);
		 if (*sv)
		 	free(*sv);
		 *sv = (char *)malloc(BUFF_SIZE + ft_strlen(*t) + 1);
		 ft_strcpy(*sv, *t);
		 *rsize = read(fd, (*sv + ft_strlen(*t)), BUFF_SIZE);
		 *(*sv + ft_strlen(*t) + *rsize) = '\0';
		 free(*t);
	}
}

int		chk_sv(char **sv, char **t, char ***line)
{
	char *t2;

	if (ft_strchr(*sv, '\n'))
	{
		if (ft_strlen(*sv) == 1)
		{
			ft_strdel(sv);
			return (0);
		}
		*t = ft_strchr(*sv, '\n') + 1;
		*(ft_strchr(*sv, '\n')) = '\0';
		**line = ft_strdup(*sv);
		if (**t != '\0')
		{
			t2 = *sv;
			*sv = ft_strdup(*t);
			ft_strdel(&t2);
		}
		else
			ft_strdel(sv);
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *sv = NULL;
	char		*t;
	int			rsize;

	ft_putendl("1");
	if (!line)
		return(-1);
	ft_putendl("2");
	rsize = 1;
	if (!sv)
	{
		ft_putendl("3");
		sv = (char *)malloc(BUFF_SIZE + 1);
		rsize = read(fd, sv, BUFF_SIZE);
		ft_putnbr(rsize);
		ft_putendl(" == rsize");
		sv[rsize] = '\0';
		if (rsize == 0 || (rsize == 1 && ft_strcmp(sv, "\n")))
		{
			ft_putendl("error");
			ft_strdel(&sv);
			return (0);
		}
		ft_putendl("4");
	}
	read_line(&sv, &rsize, &t, fd);
	if (rsize < 0)
	{
		ft_putendl("5");
		if (*sv)
			ft_strdel(&sv);
		return (-1);
	}
	if (chk_sv(&sv, &t, &line) && *sv && !(ft_strchr(sv, '\n')) && rsize == 0)
	{
		ft_putendl("6");
		*line = ft_strdup(sv);
		ft_strdel(&sv);
	}
	ft_putendl("7");
	return (1);
}

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
**  1 line with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	char		*filename;


	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr("output :");
		ft_putendl(line);
	}
	if (line)
		ft_strdel(&line);
	ft_putendl("return");
	return (1);
}






















