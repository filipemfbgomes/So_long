/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:19:00 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/02 15:25:11 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 10)
	{
		count += ft_putnbr_u(nbr / 10, base);
	}
	count += ft_putchar_count(base[nbr % 10]);
	return (count);
}

/*int	main(void)
{
	unsigned char test[] = "0123456789";
	ft_putnbr_u(42, test);
}*/