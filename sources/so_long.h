/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:12:05 by ohosnedl          #+#    #+#             */
/*   Updated: 2023/12/20 13:41:19 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/MLX42/include/MLX42/MLX42.h"
# include "../libraries/ft_printf/ft_printf.h"
# include "../libraries/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct s_struct
{
    int     fd;
    int     height;
    int     width;
    int     playercount;
    int     exitcount;
    int     collectiblecount;
    int     y;
    int     x;
    int     movecount;

    char    **map;

    mlx_texture_t   *floor;
    mlx_image_t     *floor_img;
    mlx_texture_t   *wall;
    mlx_image_t     *wall_img;
    mlx_texture_t   *character;
    mlx_image_t     *character_img;
    mlx_texture_t   *collectible;
    mlx_image_t     *collectible_img;
    mlx_texture_t   *horse;
    mlx_image_t     *horse_img;
    mlx_t           *mlx_ptr;
}   t_struct;

void    load_map(char *map_path, t_struct *game);
void    game_init(t_struct *game);
void    check_map(t_struct *game);
void    exit_error(t_struct *game, int num);
void    load_all_textures(t_struct *game);
void    exit_succes(t_struct *game);

#endif