/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juwong <juwong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:40:16 by juwong            #+#    #+#             */
/*   Updated: 2018/07/21 01:17:02 by juwong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char *make_str(char **content, t_list *l_content)
{
	if (!l_content)
		return (NULL);
	if (l_content->next)
		*content = make_str(content, l_content->next);
	*content = ft_strncat(*content, l_content->content, l_content->content_size);
	ft_lstdelone(&l_content, ft_freecontent);
	return (*content);
}


/*
static int	pop_fd_buffer(t_list **buff, int fd, char **content)
{
	t_list		*previous;
	t_list		*curr;
	
	curr = *buff;
	while (curr)
	{
		if ((int)curr->content_size == fd)
		{
			*content = ft_strcpy(*content, curr->content);
			if (curr == *buff)
			{
				(*buff)->content = "";
				(*buff)->content_size = 0;
			}
			else
			{
				previous != NULL ? previous->next = curr->next : (*buff = (*buff)->next);
				ft_lstdelone(&curr, ft_freecontent);
			}
			return (1);
		}
		previous = curr;
		curr = curr->next;
	}
	return (0);
}
*/

/*
static int	pop_fd_buffer(t_list **buff, int fd, char **content)
{
	t_list		*previous;
	t_list		*curr;
	
	curr = *buff;
	while (curr)
	{
		if ((int)curr->content_size == fd)
		{
			*content = ft_strcpy(*content, curr->content);
			if (curr == *buff)
			{
				(*buff)->content = "";
				(*buff)->content_size = 0;
				(*buff = (*buff)->next);
			}
			else
			{
				previous != NULL ? previous->next = curr->next : (*buff = (*buff)->next);
				ft_lstdelone(&curr, ft_freecontent);
			}
			return (1);
		}
		previous = curr;
		curr = curr->next;
	}
	return (0);
}
*/

static t_list	*pop_fd_buffer(t_list **l_file_reads, int fd)
{
	t_list		*curr;
	t_list		*new;
	
	curr = *l_file_reads;
	while (curr)
	{
		if ((int)curr->content_size == fd)
		{	
			new = ft_lstnew(curr->content, ft_strlen(curr->content));
			ft_memset(curr->content, 0, curr->content_size);
			curr->content_size = 0;
			return (new);
		}
		curr = curr->next;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static 	t_list	*l_file_reads;
	t_list			*l_buff;
	char			*ptr_newline;
	size_t			bytes_read;
	size_t			total_bytes;

	total_bytes = 0;
	ptr_newline = NULL;
	bytes_read = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if ((l_buff = pop_fd_buffer(&l_file_reads, fd)))
	{
		ptr_newline = ft_memchr(l_buff->content, '\n', bytes_read);
		bytes_read = l_buff->content_size;
	}
	while ( bytes_read > 0 && ptr_newline == NULL)
	{		
		ft_lst_pushfront(&l_buff, "", BUFF_SIZE + 1);
		bytes_read = read(fd, l_buff->content, BUFF_SIZE);
		if (bytes_read == 0)
		{
			ft_lstdelone(&l_buff, ft_freecontent);
			break;
		}
		((char*)l_buff->content)[bytes_read] = '\0';
		ptr_newline = ft_memchr(l_buff->content, '\n', bytes_read);
	}
	if (ptr_newline)
	{
		*ptr_newline++ = '\0';
		if (ft_strlen(ptr_newline) > 0)
		{	
			ft_lst_pushfront(&l_file_reads, ptr_newline, ft_strlen(ptr_newline) + 1);
			l_file_reads->content_size = (size_t)fd;
		}
		bytes_read = ptr_newline - (char*)l_buff->content;
	}
			
//			ft_putstr("new line not null");
//			ft_putnbr((int)next_n);
//			ft_lstadd(&buff, (ft_lstnew((ptr_newline + 1), bytes_read - next_n)));

//			((char *)buff->content)[bytes_read - next_n + 1] = '\0';
				
//			ft_putstr("Test 0 insertion");
//			ft_putendl(buff->content);
//			
//			(char)(buff->content[bytes_read - next_n + 1]) = '\0';
//			ft_bzero(content + next_n + 1, bytes_read - next_n - 1); 
//			ft_putendl(content);
	//	ft_swap(content, l_content->content);
//		ft_putstr("bytes_read :");
//		ft_putnbr((int)bytes_read);
//		ft_putchar('\n');
//		ft_putendl(content);
		total_bytes += bytes_read;
//		if (next_n != -1 || bytes_read == 0)
//			break;
	if (total_bytes == 0)
//	ft_putendl("FREEING MEMORY");
		return -1;
	if (!(*line = ft_strnew(total_bytes)))
		return(-1);
	make_str(line, l_buff);
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
	

		*line = ft_read_file(fd, buff);

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