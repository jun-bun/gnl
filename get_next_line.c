/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:40:16 by juwong            #+#    #+#             */
/*   Updated: 2018/07/14 22:02:08 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *make_str(char **content, t_list *l_content)
{
	if (l_content->next)
		*content = make_str(content, l_content->next);
	*content = ft_strncat(*content, l_content->content, l_content->content_size);
	ft_lstdelone(&l_content, ft_freecontent);
	return (*content);
}

/*
char	*ft_read_file(int fd, char buff[MAX_FILEDES][BUFF_SIZE])
{
	
}
*/

int		get_next_line(const int fd, char **line)
{
	static 	t_list	*buff;
	t_list			*l_content;
	char			*ptr_newline;
	char			*content;
	size_t			bytes_read;
	size_t			total_bytes_read;
	size_t			next_n;		

	l_content = NULL;
	total_bytes_read = 0;
	bytes_read = 1;
	content = ft_strnew(BUFF_SIZE);
	ptr_newline = NULL;
	if (buff[fd][0])
	{
		//ft_putendl(buff[fd]);
		l_content = ft_lstnew(buff[fd], ft_strlen(buff[fd]));
		ft_strclr(buff[fd]);
		ft_putendl("Catch segfault");

	}
	while (ptr_newline == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, content, BUFF_SIZE);
		next_n = 0;
		ptr_newline = (ft_memchr(content, '\n', bytes_read));
		if (ptr_newline)
		{
				next_n = ptr_newline - content;
				ft_putstr("newline not null");
				ft_putnbr((int)next_n);
		}
		if (ptr_newline)
		{
				



			ft_strcpy(buff[fd], ptr_newline + 1);
			ft_putendl("in the Buff");
			ft_putendl(buff[fd]);
			//bytes_read = ptr_newline - content;
			bytes_read = 10;
			ft_strclr(ptr_newline);
			*ptr_newline = '\0';
			ft_putendl("Content left over");
			ft_putendl(content);
		}
		ft_lst_pushfront(&l_content, content, bytes_read);
	//	ft_swap(content, l_content->content);
		ft_putstr("bytes_read :");
		ft_putnbr((int)bytes_read);
		ft_putchar('\n');
		ft_putendl(content);
		total_bytes_read += bytes_read;
		ft_bzero(content, BUFF_SIZE);
	}
	ft_strdel(&content);
	*line = ft_strnew(total_bytes_read);
	ptr_newline = NULL;
	make_str(line, l_content);
	if (bytes_read == 0)
	{
		ft_putendl("FREEING MEMORY");
		return -1;
	}
	return (1);

}

/*
char *make_str(char **content, t_list *l_content)
{
	if (l_content->next)
		*content = make_str(content, l_content->next);
	*content = ft_strncat(*content, l_content->content, l_content->content_size);
	ft_lstdelone(&l_content, ft_freecontent);
	return (*content);
}

char	*ft_read_file(int fd, char buff[MAX_FILEDES][BUFF_SIZE])
{
	t_list	*l_content;
	char	*ptr_newline;
	char	*content;
	char	*new_str;
	size_t	bytes_read;
	size_t	total_bytes_read;

	l_content = NULL;
	total_bytes_read = 0;
	bytes_read = 1;
	content = ft_strnew(BUFF_SIZE);
	ptr_newline = NULL;
	if (buff[fd][0])
	{
		//ft_putendl(buff[fd]);
		l_content = ft_lstnew(buff[fd], ft_strlen(buff[fd]));
		ft_strclr(buff[fd]);
		ft_putendl("Catch segfault");

	}
	while (ptr_newline == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, content, BUFF_SIZE);
		ptr_newline = ft_memchr(content, '\n', bytes_read);
		if (ptr_newline)
		{
			ft_strcpy(buff[fd], ptr_newline + 1);
			ft_putendl("in the Buff");
			ft_putendl(buff[fd]);
			//bytes_read = ptr_newline - content;
			bytes_read = 10;
			ft_strclr(ptr_newline);
			*ptr_newline = '\0';
			ft_putendl("Content left over");
			ft_putendl(content);
		}
		ft_lst_pushfront(&l_content, content, bytes_read);
	//	ft_swap(content, l_content->content);
		ft_putstr("bytes_read :");
		ft_putnbr((int)bytes_read);
		ft_putchar('\n');
		ft_putendl(content);
		total_bytes_read += bytes_read;
		ft_bzero(content, BUFF_SIZE);
	}
	ft_strdel(&content);
	content = ft_strnew(total_bytes_read);
	ptr_newline = NULL;
	make_str(&content, l_content);	
	if (bytes_read == 0)
	{
		ft_putendl("FREEING MEMORY");
		return NULL;
	}
	return (content);
}

int		get_next_line(const int fd, char **line)
{
	static char		buff[MAX_FILEDES][BUFF_SIZE];

		*line = ft_read_file(fd, &buff);

		if (*line)
		{
			ft_putendl("Return LINE");
			return (1);
		}
		else
		{
			ft_putendl("Returning 0 to main");
			return (0);
		}
}
*/