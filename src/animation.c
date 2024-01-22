/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:09:50 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:03:33 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

//cap_fps(50);
void	animation(void)
{
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
