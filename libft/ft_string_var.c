/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 03:32:37 by juwong            #+#    #+#             */
/*   Updated: 2018/07/01 15:09:03 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns var of a string
** Words: number of words in a string delimited by c
** Size: number of letters
** Delimiter: the delimiting char
** Example : ft_string_var(split  ||this|for|me|||||!|", '|')
** t_string_var; words = 5; size = 17; delimiter = |;
*/

t_string_var	ft_string_var(const char *s, char c)
{
	t_string_var	t_str;

	t_str.words = 0;
	t_str.size = 0;
	t_str.delimiter = c;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			t_str.words++;
		while (*s != c && *s)
		{
			t_str.size++;
			s++;
		}
	}
	return (t_str);
}
