/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:35:46 by juwong            #+#    #+#             */
/*   Updated: 2018/06/20 19:35:03 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*ptr_first;
	char		*ptr_next;
	const char	*ptr_needle;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			ptr_first = ((char*)haystack);
			ptr_next = ptr_first;
			ptr_needle = needle;
			while (*ptr_needle && *ptr_next++ == *ptr_needle++)
			{
				if (*ptr_needle == '\0')
					return (ptr_first);
			}
		}
		haystack++;
	}
	return (NULL);
}
