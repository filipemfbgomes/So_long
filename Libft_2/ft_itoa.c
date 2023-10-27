/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:47:48 by fde-mour          #+#    #+#             */
/*   Updated: 2023/04/27 12:26:22 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_lenght(int y)
{
	int	i;

	i = 0;
	while (y > 9)
	{
		y = y / 10;
		i++;
	}
	return (i + 1);
}

int	is_negative(int x)
{
	if (x < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int		i;
	int		signal;
	char	*var;

	i = 0;
	signal = is_negative(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (signal == 1)
		n = -n;
	i = check_lenght(n);
	var = (char *)malloc(sizeof(char) * (i + signal) + 1);
	if (!var)
		return (NULL);
	var[i + signal] = '\0';
	while (i > 0)
	{
		var[i + signal - 1] = n % 10 + 48;
		i--;
		n = n / 10;
	}
	if (signal == 1)
		var[0] = '-';
	return (var);
}
