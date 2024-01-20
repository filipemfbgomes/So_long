/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:09:50 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 17:53:23 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void	animation(void)
{
	cap_fps(100);
	animate_cristal(&act()->cristal);
}

void	animate_cristal(int *cristal)
{
	static int	count;

	count++;
	if (count == 20)
	{
		(*cristal)++;
		count = 0;
	}
	if (*cristal == 24)
		*cristal = 0;
}
