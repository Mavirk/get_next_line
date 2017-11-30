#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

# define BUFF_SIZE 2
int		get_next_line(const int fd, char **line);

#endif