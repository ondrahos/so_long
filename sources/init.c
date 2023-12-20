/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:32:26 by ohosnedl          #+#    #+#             */
/*   Updated: 2023/12/20 15:30:36 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    game_init(t_struct *game)
{
    game->fd = 0;
    game->height = 0;
    game->width = 0;
    game->playercount = 0;
    game->exitcount = 0;
    game->collectiblecount = 0;
    game->y = 0;
    game->x = 0;
    game->movecount = 1;
    game->map = NULL;
    game->floor = NULL;
    game->floor_img = NULL;
    game->wall = NULL;
    game->wall_img = NULL;
    game->collectible = NULL;
    game->collectible_img = NULL;
    game->character = NULL;
    game->character_img = NULL;
    game->horse = NULL;
    game->horse_img = NULL;
    game->mlx_ptr = NULL;
}

static int get_map_width(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\n' && line[i] != '\0')
        i++;
    return (i);
}

static int add_line(t_struct *game, char *line)
{
    char    **tmp;
    int     i;

    if (!line)
        return (0);
    i = 0;
    game->height++;
    tmp = malloc(sizeof(char *) * (game->height + 1));
    tmp[game->height] = NULL;
    while (i < game->height - 1)
    {
        tmp[i] = game->map[i];
        i++;
    }
    tmp[i] = line;
    if (game->map)
        free(game->map);
    game->map = tmp;
    return (1);
}

void    load_map(char *map_path, t_struct *game)
{
    char    *readline;
   
    game->fd = open(map_path, O_RDONLY);
    if (game->fd < 0)
        exit_error(game, 3);
    while (1)
    {
        readline = get_next_line(game->fd);
        if (!add_line(game, readline))
            break ;
    }
    close(game->fd);
    if (game->map == NULL)
        exit_error(game, 5);
    game->width = get_map_width(game->map[0]);
}
