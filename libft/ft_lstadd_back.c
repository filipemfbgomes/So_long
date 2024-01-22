/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:13:38 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/06 14:09:26 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		ft_lstlast(*lst)->next = new;
	else
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
	
	ft_lstadd_back(&list, n4);

	while(list)
	{
		printf("Content of node: %s\n", (char *)list->content);
	 	list = list->next;
	}
	return (0);
}*/