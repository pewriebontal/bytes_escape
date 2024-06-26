/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 01:37:21 by mkhaing           #+#    #+#             */
/*   Updated: 2024/03/22 04:37:00 by mkhaing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

void	free_map(t_map *m_ptr)
{
	int	i;

	i = 0;
	if (m_ptr->map)
	{
		while (m_ptr->map[i])
		{
			yeet(m_ptr->map[i]);
			i++;
		}
		yeet(m_ptr->map);
		m_ptr->map = NULL;
	}
}

void	free_graphic(t_game *g_ptr)
{
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.player_up);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.player_right);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.player_down);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.player_left);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.wall);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.path);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.exit_open);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.exit_close);
	mlx_destroy_image(g_ptr->mlx_ptr, g_ptr->sprite.bit_berry);
	g_ptr->sprite.player_up = NULL;
	g_ptr->sprite.player_right = NULL;
	g_ptr->sprite.player_down = NULL;
	g_ptr->sprite.player_left = NULL;
	g_ptr->sprite.wall = NULL;
	g_ptr->sprite.path = NULL;
	g_ptr->sprite.exit_open = NULL;
	g_ptr->sprite.exit_close = NULL;
	g_ptr->sprite.bit_berry = NULL;
}

void	free_all(t_game *g_ptr)
{
	if (g_ptr->test_map.map)
	{
		free_map(&g_ptr->test_map);
	}
	if (g_ptr->real_map.map)
	{
		free_graphic(g_ptr);
	}
	if (g_ptr->real_map.map)
	{
		free_map(&g_ptr->real_map);
	}
}
