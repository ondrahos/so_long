/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:21:22 by ohosnedl          #+#    #+#             */
/*   Updated: 2023/12/20 13:38:08 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_texture(t_struct *game)
{
    game->floor = mlx_load_png("./assets/textures/floor.png");
    game->floor_img = mlx_texture_to_image(game->mlx_ptr, game->floor);
    game->wall = mlx_load_png("./assets/textures/wall.png");
    game->wall_img = mlx_texture_to_image(game->mlx_ptr, game->wall);
    game->collectible = mlx_load_png("./assets/textures/collectible.png");
    game->collectible_img = mlx_texture_to_image(game->mlx_ptr, game->collectible);
    game->character = mlx_load_png("./assets/textures/character.png");
    game->horse = mlx_load_png("./assets/textures/horse.png");
    game->horse_img = mlx_texture_to_image(game->mlx_ptr, game->horse);
    if (!game->floor || !game->wall || !game->collectible || !game->character
        || !game->horse)
        exit_error(game, 4);
}
    
void    load_all_textures(t_struct *game)
{
    int y = 0;
    init_texture(game);
    while (game->map[y])
    {
        int x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1')
                if (mlx_image_to_window(game->mlx_ptr, game->wall_img, x * 64, y * 64) < 0)
                    exit_error(game, 4);
            if (game->map[y][x] == '2' || game->map[y][x] == 'c' || game->map[y][x] == 'p'
                || game->map[y][x] == 'e')
                if (mlx_image_to_window(game->mlx_ptr, game->floor_img, x * 64, y * 64) < 0)
                    exit_error(game, 4);
            if (game->map[y][x] == 'c')
                if (mlx_image_to_window(game->mlx_ptr, game->collectible_img, x * 64, y * 64) < 0)
                    exit_error(game, 4);
            if (game->map[y][x] == 'e')
                if (mlx_image_to_window(game->mlx_ptr, game->horse_img, x * 64, y * 64) < 0)
                    exit_error(game, 4);
            x++;
        }
        y++;
    }
    game->character_img = mlx_texture_to_image(game->mlx_ptr, game->character);
    if (mlx_image_to_window(game->mlx_ptr, game->character_img, game->x * 64, game->y * 64) < 0)
        exit_error(game, 4);
    if (!game->floor_img || !game->wall_img || !game->collectible_img || !game->character_img
        || !game->horse_img)
        exit_error(game, 4);
}
