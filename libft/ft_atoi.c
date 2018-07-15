/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 20:31:17 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 01:54:55 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts the string argument str to an integer (type int).
** Parameter: str − This is the string representation of an integral number.
** Return: the converted integral number as an int value.
** If no valid conversion could be performed, it returns zero.
** Example : ft_atoi("  -234ABC") -> -234
*/

int		ft_atoi(const char *str)
{
	int				integer;
	int				sign;

	integer = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		integer = integer * 10 + (*str++ - 48);
	return (integer * sign);
}
