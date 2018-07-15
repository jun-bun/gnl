/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 20:10:33 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:47:32 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description Applies the function f to each character of the string passed as
** argument. Each character is passed by address to f to be modified if necess
** Param. #1 The string to iterate.
** Param. #2 The function to apply to each character of s.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
	{
		f(s++);
	}
}
