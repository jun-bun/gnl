/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 00:44:39 by juwong            #+#    #+#             */
/*   Updated: 2018/06/27 03:03:44 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char*)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	ptr = str;
	str = ft_memcpy_lp(str, s1, len_s1);
	str = ft_memcpy_lp(str, s2, len_s2);
	*str = '\0';
	return (ptr);
}
