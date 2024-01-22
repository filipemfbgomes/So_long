/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:09:50 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 02:09:07 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

void	animation(void)
{
	animate_cristal(&act()->cristal);
	//cap_fps(15);
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
