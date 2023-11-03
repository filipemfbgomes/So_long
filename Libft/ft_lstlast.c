/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:22:06 by fde-mour          #+#    #+#             */
/*   Updated: 2023/10/16 13:51:19 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*int	main(void)
{
	char *s1 = "Content1";
	char *s2 = "Content2";
	char *s3 = "Content3";

	t_list	*n1 = ft_lstnew(s1);
	t_list	*n2 = ft_lstnew(s2);
	t_list	*n3 = ft_lstnew(s3);

	n1->next = n2;
	n2->next = n3;

	t_list *list = n1;

	printf("%s", (char *)ft_lstlast(list)->content);
	return (0);
}*/