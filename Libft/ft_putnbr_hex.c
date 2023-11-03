/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:54:02 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/02 15:25:09 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned long int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_hex(nbr / 16, base);
	count += ft_putchar_count(base[nbr % 16]);
	return (count);
}

/*int	main(void)
{
	int x;
	x = ft_putnbr_hex(50000, "0123456789ABCDEF");
	//printf("\n");
	//printf("%d\n", x);
	return (0);
}
*/