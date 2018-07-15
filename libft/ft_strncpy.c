/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 16:32:34 by juwong            #+#    #+#             */
/*   Updated: 2018/06/25 17:23:32 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*origin;

	origin = dst;
	while (len-- > 0)
	{
		if (*src == '\0')
			*dst++ = '\0';
		else
			*dst++ = *src++;
	}
	return (origin);
}
