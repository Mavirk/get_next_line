/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmurdoch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 12:51:13 by rmurdoch          #+#    #+#             */
/*   Updated: 2017/09/15 15:55:41 by rmurdoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *ps1;
	char *ps2;

	ps1 = (char*)s1;
	ps2 = (char*)s2;
	while (*ps1)
		ps1++;
	while (*ps2)
		*(ps1++) = *(ps2++);
	*ps1 = '\0';
	return (s1);
}
