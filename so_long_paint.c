/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:19:26 by ydahni            #+#    #+#             */
/*   Updated: 2022/03/15 05:52:04 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_call_2	so_long_paint_2(t_call_2 m, int x, int i)
{
	while (m.map[x][i])
	{
		mlx_put_image_to_window(m.mlx, m.mlx_wind, m.zero, m.h, m.l);
		if (m.map[x][i] == 'C')
			mlx_put_image_to_window(m.mlx, m.mlx_wind, m.coins, m.h, m.l);
		if (m.map[x][i] == 'E')
		{
			mlx_put_image_to_window(m.mlx, m.mlx_wind, m.exit, m.h, m.l);
			m.e_h = i;
			m.e_l = x;
		}
		if (m.map[x][i] == 'P')
		{
			mlx_put_image_to_window(m.mlx, m.mlx_wind, m.player_f, m.h, m.l);
			m.p_h = i;
			m.p_l = x;
		}
		if (m.map[x][i] == '1')
			mlx_put_image_to_window(m.mlx, m.mlx_wind, m.wall, m.h, m.l);
		m.h += 50;
		i++;
	}
	return (m);
}

t_call_2	so_long_paint_1(t_call_2 m)
{
	int	i;
	int	x;
	int	h;
	int	l;

	x = 0;
	m.coins = mlx_xpm_file_to_image(m.mlx, "C.xpm", &h, &l);
	m.zero = mlx_xpm_file_to_image(m.mlx, "0.xpm", &h, &l);
	m.wall = mlx_xpm_file_to_image(m.mlx, "1.xpm", &h, &l);
	m.player_f = mlx_xpm_file_to_image(m.mlx, "P_F.xpm", &h, &l);
	m.player_d = mlx_xpm_file_to_image(m.mlx, "P_D.xpm", &h, &l);
	m.player_l = mlx_xpm_file_to_image(m.mlx, "P_L.xpm", &h, &l);
	m.player_r = mlx_xpm_file_to_image(m.mlx, "P_R.xpm", &h, &l);
	m.exit = mlx_xpm_file_to_image(m.mlx, "E.xpm", &h, &l);
	while (m.map[x])
	{
		i = 0;
		m.h = 0;
		m = so_long_paint_2(m, x, i);
		m.l += 50;
		x++;
	}
	return (m);
}

void	so_long_paint(t_call_2 m)
{
	int	i;
	int	x;

	m.l = 0;
	x = 0;
	i = ft_strlen(*m.map);
	while (m.map[x])
		x++;
	m.mlx = mlx_init();
	m.mlx_wind = mlx_new_window(m.mlx, i * 50, x * 50, "so_long");
	m = so_long_paint_1(m);
	mlx_key_hook(m.mlx_wind, key_hook, &m);
	mlx_hook(m.mlx_wind, 17, 0L, exit_mouse, &m);
	mlx_loop(m.mlx);
}
