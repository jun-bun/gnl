/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 18:22:09 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 20:43:50 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreverse(char *s)
{
	size_t	i;
	char	tmp;
	size_t	last;

	if (!s)
		return ;
	i = 0;
	last = ft_strlen(s) - 1;
	while (i < last / 2)
	{
		tmp = *(s + i);
		*(s + i) = *(s + last - i);
		*(s + last - i) = tmp;
		i++;
	}
}
