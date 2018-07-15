/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:26:03 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:31:05 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the number of digits in an int
** ft_intlen(999) -> 3
*/

unsigned int	ft_intlen(int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}
