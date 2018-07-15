/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 22:58:33 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 02:54:21 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a “fresh” new
** string (with malloc(3)) resulting from the successive applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s and its index.
** Return The “fresh” string created from the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*ptr_s;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = ft_memalloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	ptr_s = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (ptr_s);
}
