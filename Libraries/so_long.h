/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:53:38 by fde-mour          #+#    #+#             */
/*   Updated: 2024/01/22 02:05:33 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "class_structs.h"
# include "macros.h"
# include <sys/time.h>

//check_map.c
void	check_rows(t_map *map);
void	check_columns(t_map *map);
void	count_map(t_map *map);
void	verify_parameters(t_map *map);
void	check_map(t_map *map);

//map_init.c
void	check_command(int argc, char *argv);
void	init_map(char *argv);
void	check_for_empty_line(char *arr);
void	start_map(void);

//animation.c
void	animate_cristal(int *cristal);
void	animate_portal(int coll, int max, int *portal);
void	animation(void);

//engine.c
void	engine(void);
void	move(int x, int y);
void	check_collected(int x, int y, char **map);
void	check_movement(void);

//flood_fill.c
void	flood_fill(int x, int y, int *flag);
int		check_collec(char **mapa);
int		fill_flood(void);

//free.c
int		error_msg(char *message);
void	free_map(char **arr);
void	free_all(t_win *win);
void	destroy_images(t_win *win);
int		exit_game(void);

//game_init.c
void	init_game(char *argv);
void	init_textures(t_win *win);
t_img	load_image(t_win *win, char *path);
void	init_cristal(t_win *win);
t_img	new_image(t_win *win, int x, int y);

//handle_input.c
int		scan_key_release(int keycode);
int		scan_key(int keycode);

//mlx_management.c
void	init_mlx(t_win *win);
void	mlx_managent(void);

//my_mlx_function.c
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	my_mlx_get_pixel(t_img *data, int x, int y);

//paint.c
void	paint_icon(t_img img, int pos_x, int pos_y, t_img *screen);
void	paint_objects(t_map map, t_canvas *canvas, t_action act);
void	print_movements(t_win *win);
void	paint(void);

//render.c
void	get_max_values(int *fd);
void	get_player(t_map map, t_player *player);
int		render(t_win *win);

//so_long.c
void	so_long(t_win *win);

//utils.c
char	*ft_str_doublepointer(char **s1, const char *s2);
void	get_fps(void);
void	cap_fps(int cap);

#endif