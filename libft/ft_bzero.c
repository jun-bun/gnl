/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 23:22:09 by juwong            #+#    #+#             */
/*   Updated: 2018/06/26 20:49:47 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The bzero() function erases the data in the n bytes of the memory
** starting at the location pointed to by s, by writing zeros (bytes
** containing '\0') to that area.
** example ft_bzero("string", 3) -> "\0\0\0\ing"
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
