if (rsize < 0)
	return(-1);
if (ft_strchr(save, '\n') && rsize > 0)
{
	*(ft_strchr(save, '\n')) = '\0';
	*line = ft_strdup(save);
	temp = ft_strchr(save, '\0') + 1
	if (temp)
	{
		temp2 = save;
		save = ft_strdup(temp);
		free = temp2;
		return (1);
	}
}
else if (ft_strchr(save, '\n') && rsize == 0)
{
	*(ft_strchr(save, '\n')) = '\0';
	*line = ft_strdup(save);
	temp = ft_strchr(save, '\0') + 1
	if (temp)
	{
		temp2 = save;
		save = ft_strdup(temp);
		free = temp2;
		return (1);
	}
}
else if (!(ft_strchr(save, '\n')) && rsize == 0)
{
	save[ft_strlen(save)] = '\0';
	*line = ft_strdup(save);
	free(save);
}
else 
	return(0);








	if (read < 0)
		return(-1);
	if((ft_strchr(save, '\n')))
		*(ft_strchr(save, '\n')) = '\0';
	else if (rsize == 0  && ft_strlen(save))
		save[ft_strlen(save)] = '\0';
	*line = ft_strdup(save);
	if (rsize == 0  && ft_strlen(save))
		return (1);
	else if (rsize == 0)
		return (0);
	save = (ft_strchr(save, '\0') + 1);
	return(1);