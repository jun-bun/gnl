/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:24:06 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:55:35 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;

	while (*s1 || *s2)
	{
		if (n-- == 0)
			return (0);
		diff = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (diff != 0)
			return (diff);
		s1++;
		s2++;
	}
	return (0);
}
