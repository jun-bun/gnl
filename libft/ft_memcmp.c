/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:55:23 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:40:33 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		diff;

	while (n-- > 0)
	{
		diff = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (diff != 0)
			return (diff);
	}
	return (0);
}
