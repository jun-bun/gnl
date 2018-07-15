/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 15:10:00 by juwong            #+#    #+#             */
/*   Updated: 2018/06/19 16:09:08 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	l;
	char	*s2;
	char	*origin;

	l = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(*s1) * l + 1);
	if (s2 == NULL)
		return (NULL);
	else
	{
		origin = s2;
		while (*s1)
		{
			*s2 = *s1;
			s1++;
			s2++;
		}
		*s2 = '\0';
		return (origin);
	}
}
