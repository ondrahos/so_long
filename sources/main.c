/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohosnedl <ohosnedl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:12:09 by ohosnedl          #+#    #+#             */
/*   Updated: 2024/01/05 14:11:22 by ohosnedl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_hook(t_struct *game)
{
	size_t	i;

	if (game->map[game->y][game->x] == 'c')
	{
		game->map[game->y][game->x] = 'd';
		i = 0;
		while (i < game->collectible_img->count)
		{
			if (game->y * 64 == game->collectible_img->instances[i].y
				&& game->x * 64 == game->collectible_img->instances[i].x)
				game->collectible_img->instances[i].enabled = false;
			i++;
		}
		game->collectiblecount--;
		ft_printf("You have collected a carrot. Another %i remaining.\n",
			game->collectiblecount);
	}
	if (game->collectiblecount == 0)
	{
		if (game->map[game->y][game->x] == 'e')
		{
			ft_printf("--------\nYOU WIN! \n--------\n");
			exit_succes(game);
		}
	}
}

static void	my_keyhook2(t_struct *game, char c)
{
	if (c == 'W')
	{
		if (game->map[game->y - 1][game->x] == '1')
			return ;
		game->character_img->instances[0].y -= 64;
		game->y -= 1;
		ft_printf("You have made: %i moves!\n", game->movecount++);
	}
	else if (c == 'D')
	{
		if (game->map[game->y][game->x + 1] == '1')
			return ;
		game->character_img->instances[0].x += 64;
		game->x += 1;
		ft_printf("You have made: %i moves!\n", game->movecount++);
	}
	else if (c == 'A')
	{
		if (game->map[game->y][game->x - 1] == '1')
			return ;
		game->character_img->instances[0].x -= 64;
		game->x -= 1;
		ft_printf("You have made: %i moves!\n", game->movecount++);
	}
}

static void	my_keyhook3(t_struct *game, char c)
{
	if (c == 'S')
	{
		if (game->map[game->y + 1][game->x] == '1')
			return ;
		game->character_img->instances[0].y += 64;
		game->y += 1;
		ft_printf("You have made: %i moves!\n", game->movecount++);
	}
	else if (c == 'E')
	{
		exit_succes(game);
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_struct	*game;

	game = (t_struct *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		my_keyhook2(game, 'W');
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		my_keyhook2(game, 'D');
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		my_keyhook2(game, 'A');
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		my_keyhook3(game, 'S');
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		my_keyhook3(game, 'E');
	if (keydata.action == MLX_PRESS)
		my_hook(game);
}

int	main(int ac, char **av)
{
	t_struct	game;

	if (ac != 2)
		exit_error(&game, 1);
	game_init(&game);
	load_map(av[1], &game);
	check_map(&game);
	game.mlx_ptr = mlx_init(game.width * 64, game.height * 64,
			"so_long - FEED THE HORSIE", false);
	if (!game.mlx_ptr)
		return (0);
	load_all_textures(&game);
	mlx_key_hook(game.mlx_ptr, &my_keyhook, &game);
	mlx_loop(game.mlx_ptr);
	exit_succes(&game);
}
