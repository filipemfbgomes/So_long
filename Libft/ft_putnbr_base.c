/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:18:18 by fde-mour          #+#    #+#             */
/*   Updated: 2023/11/02 15:25:05 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	basesize;
	unsigned int	n;
	int				count;

	count = 0;
	basesize = ft_strlen_count(base);
	if (nbr < 0)
	{
		n = -nbr;
		count += ft_putchar_count('-');
	}
	else
		n = nbr;
	if (n >= basesize)
	{
		count += ft_putnbr_base(n / basesize, base);
	}
	count += ft_putchar_count(base[n % basesize]);
	return (count);
}

/*int	main(void)
{
	ft_putnbr_base(0, "0123456789");
}*/