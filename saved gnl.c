int get_next_line(const int fd, char **line)
{
	static char 	*save;
	void 			*buf;
	char			*pbuf;
	char			*string;
	void 			*tmp;
	char			*ret;
	size_t 			size;
	int				exit;
	int 			i;
	int 			strsize;

	exit = 1;
	i = 1;
	buf = malloc(BUFF_SIZE);
	while (exit > 0)
	{ 
		size = read(fd, buf, BUFF_SIZE);//saving the size of the read so that i can see if the read is done
		pbuf = ft_strchr(buf, '\n');
		if (*pbuf == '\n')
		{
			*pbuf = '\0';
			strsize = ft_strlen((const char *)buf);
			if (strsize < size)
			{
				save = malloc(size - strsize);
				save = (pbuf + 1);
				ret = ft_strcat(save, buf);
			}
			*line = ft_strdup(t);
			return (1);
		}
		ft_putstr("testgetnext\n");
	}
	if (size == 0)
		return (0);
	else
		return (-1);
}