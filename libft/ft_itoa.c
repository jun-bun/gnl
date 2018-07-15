/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 23:21:55 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:32:47 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_intlen(n);
	if (n < 0)
	{
		if (!(str = ft_strnew(++l)))
			return (NULL);
		*str = '-';
		n = -n;
	}
	else if (n >= 0)
	{
		if (!(str = ft_strnew(l)))
			return (NULL);
	}
	while (--l >= 0 && str[l] != '-')
	{
		str[l] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
