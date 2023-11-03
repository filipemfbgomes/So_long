/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:40:24 by fde-mour          #+#    #+#             */
/*   Updated: 2023/04/26 17:45:23 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		result;

	i = 0;
	if (!n)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			result = (((unsigned char *)s1)[i] - (((unsigned char *)s2)[i]));
			return (result);
		}
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	unsigned char test[] = "BoasGabriel";
	printf("%d", ft_memcmp(test, "BoasGabriel", sizeof(test)));
}*/