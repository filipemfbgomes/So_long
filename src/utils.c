/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:01 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 18:38:46 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libraries/so_long.h"

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

t_keys	*keys(void)
{
	static t_keys	keys;

	return (&keys);
}

void	init_cristal(t_win *win, int i, char *str1, char *str2)
{
	char	*place;
	char	*path;
	char	*temp;
	t_img	x;

	while (i < 24)
	{
		place = ft_itoa(i + 1);
		temp = ft_strjoin(place, str2);
		path = ft_strjoin(str1, temp);
		x = load_image(win, path);
		canvas()->cristal[i] = x;
		free(path);
		free(place);
		free(temp);
		i++;
	}
}

/*void	get_fps(void)
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
}*/