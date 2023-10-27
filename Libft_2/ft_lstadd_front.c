/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:34:20 by fde-mour          #+#    #+#             */
/*   Updated: 2023/10/16 13:49:18 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
{
	char *s1 = "Content1";
	char *s2 = "Content2";
	char *s3 = "Content3";
	char *s4 = "Content4";

	t_list	*n1 = ft_lstnew(s1);
	t_list	*n2 = ft_lstnew(s2);
	t_list	*n3 = ft_lstnew(s3);
	t_list	*n4 = ft_lstnew(s4);

	n1->next = n2;
	n2->next = n3;

	t_list *list = n1;
	
	ft_lstadd_front(&list, n4);

	while(list)
	{
		printf("Content of node: %s\n", (char *)list->content);
	 	list = list->next;
	}
	return (0);
}*/