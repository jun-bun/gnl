/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 13:44:02 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 00:33:51 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies the values of num bytes from the location pointed by source to the
** memory block pointed by destination. Copying takes place as if an
** intermediate buffer were used, allowing the destination and source to
** overlap.
** dst :Pointer to the destination array where the content is to be copied,
** src :Pointer to the source of data to be copied
** len : Number of bytes to copy.
** return : dst
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstc;
	unsigned char		*srcc;

	dstc = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	if (dstc > srcc)
	{
		dstc = dstc + len - 1;
		srcc = srcc + len - 1;
		while ((int)len-- > 0)
			*dstc-- = *srcc--;
	}
	else
	{
		while ((int)len-- > 0)
			*dstc++ = *srcc++;
	}
	return (dst);
}
