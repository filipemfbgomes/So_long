/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:43:02 by fde-mour          #+#    #+#             */
/*   Updated: 2023/10/27 17:48:10 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

char *open_map(char *file)
{
	int		fd = open(file, O_RDONLY);
	char 	*line = get_next_line(fd);
	close(fd);
	
	return (line);
}

int	main(void)
{
	char 	*line = open_map(MAP);
	printf("%s\n",line);
	free(line);
    return 0;
}
