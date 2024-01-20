/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:01 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/20 19:07:59 by fde-mour         ###   ########.fr       */
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

void get_fps(void)
{
	struct timeval time;
	static int frames;
	static int second;

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

void cap_fps(int cap)
{
	struct timeval time;
	
	const int FPS_CAP = cap;
    const int US_PER_FRAME = 1000000 / FPS_CAP;
    static struct timeval last_frame_time = {0};
    gettimeofday(&time, NULL);
    long elapsed_time = (time.tv_sec - last_frame_time.tv_sec) * 1000000 +
                         time.tv_usec - last_frame_time.tv_usec;
    if (elapsed_time < US_PER_FRAME) {
        usleep(US_PER_FRAME - elapsed_time);
    }
    last_frame_time = time;
}