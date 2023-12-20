/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:15:37 by ohosnedl          #+#    #+#             */
/*   Updated: 2023/12/20 15:28:03 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void get_player_position(t_struct *game)
{
    while (game->map[game->y])
    {
        game->x = 0;
        while(game->map[game->y][game->x])
        {
            if (game->map[game->y][game->x] == 'P')
                return ;
            game->x++;
        }
        game->y++;
    }
}

static int  check_counts(t_struct *game)
{
    int i;
    int j;

    j = 0;
    if (game->collectiblecount < 1 || game->playercount != 1 || game->exitcount != 1)
        return (0);
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i])
        {
            if (game->map[j][i] == 'C' || game->map[j][i] == 'P' || game->map[j][i] == 'E')
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}

static int  check_borders(t_struct *game)
{
    int i;

    i = 0;
    while (i < game->width)
    {
        if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < game->height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

static int  parse_map(t_struct *game)
{
    int i;
    int j;

    j = 0;
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i] != '\0' && game->map[j][i] != '\n')
        {
            if ((game->map[j][i] != 'C' && game->map[j][i] != 'P' && game->map[j][i] != 'E'
                && game->map[j][i] != '1' && game->map[j][i] != '0') || i >= game->width)
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}

    static void flood_fill(int y, int x, int height, int width, t_struct *game)
    {
        if (y < 0 || y >= height || x < 0 || x >= width)
            return ;
        else if (game->map[y][x] != 'C' && game->map[y][x] != 'P'
            && game->map[y][x] != 'E' && game->map[y][x] != '0')
            return ;
        else if (game->map[y][x] == 'C')
        {
            game->map[y][x] = 'c';
            game->collectiblecount++;
        }
        else if (game->map[y][x] == 'P')
        {
            game->map[y][x] = 'p';
            game->playercount++;
        }
        else if (game->map[y][x] == 'E')
        {
            game->map[y][x] = 'e';
            game->exitcount++;
        }
        else if (game->map[y][x] == '0')
        {
            game->map[y][x] = '2';
        }
        flood_fill(y, x - 1, height, width, game);
        flood_fill(y, x + 1, height, width, game);
        flood_fill(y - 1, x, height, width, game);
        flood_fill(y + 1, x, height, width, game);
    }

void    check_map(t_struct *game)
{
    if (!check_borders(game))
        exit_error(game, 2);
    if (!parse_map(game))
        exit_error(game, 2);
    get_player_position(game);
    flood_fill(game->y,game->x, game->height, game->width, game);
    if (!check_counts(game))
        exit_error(game, 2);
    if (game->width * 64 > 1920 || game->height * 64 > 1080)
        exit_error(game, 2);
}
