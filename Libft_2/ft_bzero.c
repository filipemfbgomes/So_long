/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:30:42 by fde-mour          #+#    #+#             */
/*   Updated: 2023/04/26 17:34:26 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*var;

	var = s;
	i = 0;
	while (i < n)
	{
		var[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char test[] = "fsdfsfsfs";
	int	test2[7] = {1,2,3,4,5,6};
	ft_bzero(test2, 12);
	ft_bzero(test, 3);
    //printf("%s", test);
	for (int i = 0; i < 6; i++)
        printf("%d ", test2[i]);
	return (0);
}*/