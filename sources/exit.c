/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:55:45 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/05 12:58:51 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_error(t_struct *game, int num)
{
	if (num == 1)
	{
		ft_printf("Error: Not enough arguments\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 2)
		ft_printf("Error: Invalid map\n");
	else if (num == 3)
	{
		ft_printf("Error: Invalid file descriptor or map extension\n");
		exit(EXIT_FAILURE);
	}
	else if (num == 4)
	{
		ft_printf("Error: Loading textures failed\n");
		mlx_terminate(game->mlx_ptr);
	}
	else if (num == 5)
	{
		ft_printf("Error: Empty file\n");
		exit(EXIT_FAILURE);
	}
	free_map(game->map);
	exit(EXIT_FAILURE);
}

void	exit_succes(t_struct *game)
{
	mlx_terminate(game->mlx_ptr);
	free_map(game->map);
	exit(EXIT_SUCCESS);
}
