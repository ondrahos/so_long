/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:37:02 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/05 12:56:31 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_struct *game)
{
	while (game->map[game->y])
	{
		game->x = 0;
		while (game->map[game->y][game->x])
		{
			if (game->map[game->y][game->x] == 'P')
				return ;
			game->x++;
		}
		game->y++;
	}
}

int	parse_map(t_struct *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i] != '\0' && game->map[j][i] != '\n')
		{
			if ((game->map[j][i] != 'C' && game->map[j][i] != 'P'
				&& game->map[j][i] != 'E' && game->map[j][i] != '1'
				&& game->map[j][i] != '0') || i >= game->width)
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
