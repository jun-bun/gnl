/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:50:34 by juwong            #+#    #+#             */
/*   Updated: 2018/06/22 00:44:22 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*ptr_first;
	char		*ptr_next;
	const char	*ptr_needle;
	size_t		l;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			ptr_first = ((char*)haystack);
			ptr_next = ptr_first;
			ptr_needle = needle;
			l = 0;
			while (*ptr_needle && *ptr_next++ == *ptr_needle++ && l++ < len)
			{
				if (*ptr_needle == '\0')
					return (ptr_first);
			}
		}
		len--;
		haystack++;
	}
	return (NULL);
}
