/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 00:55:04 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:27:29 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function shall return a pointer to the byte after the copy of
** c in s1, or a null pointer if c was not found in the first n bytes of s2
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	dst_uc = (unsigned char*)dst;
	src_uc = (unsigned char*)src;
	while (n-- > 0)
	{
		*dst_uc = *src_uc;
		if ((unsigned char)c == *src_uc)
			return (++dst_uc);
		dst_uc++;
		src_uc++;
	}
	return (NULL);
}
