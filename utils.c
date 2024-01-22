/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:01 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/21 19:32:29 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libraries/so_long.h"

char	*ft_str_doublepointer(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1); 
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	check_collected(int x, int y, char **mapa)
{
	if (mapa[y][x] == 'C')
		map()->collectables--;
}

void	get_fps(void)
{
	struct timeval	time;
	static int		frames;
	static int		second;

	gettimeofday(&time, NULL);
	if (second != time.tv_sec)
	{
		second = time.tv_sec;
		ft_printf("FPS: %d\n", frames);
		frames = 0;
	}
	else
		frames++;
}

void	cap_fps(int cap)
{
	struct timeval			time;
	const int				fps_cap = cap;
	const int				us_per_frame = 1000000 / fps_cap;
	static struct timeval	last_frame_time = {0};
	long					elapsed_time;

	gettimeofday(&time, NULL);
	elapsed_time = (time.tv_sec - last_frame_time.tv_sec) * 1000000 + \
	time.tv_usec - last_frame_time.tv_usec;
	if (elapsed_time < us_per_frame) 
	{
		usleep(us_per_frame - elapsed_time);
		gettimeofday(&time, NULL);
		elapsed_time = (time.tv_sec - last_frame_time.tv_sec) * 1000000 + \
		time.tv_usec - last_frame_time.tv_usec;
		if (elapsed_time < us_per_frame) 
			usleep(us_per_frame - elapsed_time);
	}
	last_frame_time = time;
}

t_keys	*keys(void)
{
	static t_keys	keys;

	return (&keys);
}
