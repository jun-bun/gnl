/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:48:04 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:15:19 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		diff;

	while (*s1 || *s2)
	{
		diff = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (diff != 0)
			return (diff);
	}
	return (0);
}
