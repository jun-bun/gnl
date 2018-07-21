#include "libft/libft.h"

t_list	*pop_fd_buffer(t_list **buff, int fd)
{
	t_list		*previous;
	t_list		*curr;
	t_list		*head;
	
	curr = *buff;
	while (curr)
	{
		if ((int)curr->content_size == fd)
		{	
			(previous) ? (head = previous) : (head = curr->next); 
			(curr->next) ? (head->next = curr->next) : (head->next = NULL);
			*buff = head;
			return (curr);
		}
		previous = curr;
		curr = curr->next;
	}
	return (NULL);
}

char *test_read(int fd)