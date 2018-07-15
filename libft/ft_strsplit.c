/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 01:50:54 by juwong            #+#    #+#             */
/*   Updated: 2018/06/29 18:37:43 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**str_array;
	t_string_var	t_str;
	char			**ptr;

	if (!s)
		return (NULL);
	t_str = ft_string_var(s, c);
	if (!(str_array = (char**)malloc(sizeof(char*) * (t_str.words + 1))))
		return (NULL);
	ptr = str_array;
	while (t_str.words > 0)
	{
		if (*s != c)
		{
			t_str.size = ft_strclen(s, c);
			if (!(*str_array = ft_strnew(t_str.size)))
				return (NULL);
			*str_array = ft_memcpy(*str_array, s, t_str.size);
			s = s + t_str.size;
			str_array++;
			t_str.words--;
		}
		t_str.words == 0 ? *str_array = NULL : s++;
	}
	return (ptr);
}
