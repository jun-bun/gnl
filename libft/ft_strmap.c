/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 22:21:54 by juwong            #+#    #+#             */
/*   Updated: 2018/06/26 21:41:31 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description Applies the function f to each character of the string given as
** argument to create a “fresh” new string (with malloc(3)) resulting from the
** successive applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s.
** Return : The “fresh” string created from the successive applications of f.
** ft_strmap("Hello", ft_toupper) -> "HELLO"
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ptr_s;

	if (!s || !f)
		return (NULL);
	str = ft_memalloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	ptr_s = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (ptr_s);
}
