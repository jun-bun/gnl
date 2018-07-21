/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:29:52 by juwong            #+#    #+#             */
/*   Updated: 2018/07/18 18:37:45 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locates the first occurrence of c (converted to an unsigned char) 
** in string s.
** Return - The memchr() function returns a pointer to the byte located, 
** or NULL if no such byte exists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!s)
		return (NULL);
	while (n-- > 0)
	{
		if (*(unsigned char*)s == (unsigned char)c)
			return ((void*)s);
		s++;
	}
	return (NULL);
}
