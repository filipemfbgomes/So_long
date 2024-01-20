/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:57:14 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 18:26:34 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

t_canvas	*canvas(void)
{
	static t_canvas canv;

	return (&canv);
}

t_objects	*objs(void)
{
	static t_objects objs;

	return (&objs);
}

t_keys	*keys(void)
{
	static t_keys keys;

	return (&keys);
}

t_action	*act(void)
{
	static t_action act;

	return (&act);
}

t_map	*map(void)
{
	static t_map map;
	
	return (&map);
}

t_win	*win(void)
{
	static t_win win;

	return (&win);
}
