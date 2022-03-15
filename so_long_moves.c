/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 04:49:59 by ydahni            #+#    #+#             */
/*   Updated: 2022/03/15 05:30:47 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_call	ft_up(t_call_2 *m, t_call l)
{
	if (m->map[m->p_l - 1][m->p_h] != '1')
	{
		if (m->map[m->p_l - 1][m->p_h] != 'E')
		{
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->zero,
				m->p_h * 50, m->p_l * 50);
			m->p_l--;
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->player_f,
				m->p_h * 50, m->p_l * 50);
			if (m->map[m->p_l][m->p_h] == 'C')
			{
				l.c--;
				m->map[m->p_l][m->p_h] = '0';
			}
			if (m->map[m->p_l][m->p_h] == 'B')
			{
				write (1, "YOU WIN\n", 8);
				exit(1);
			}
			g_m++;
			ft_putnbr(g_m);
			write (1, "\n", 1);
		}
	}
	return (l);
}

t_call	ft_down(t_call_2 *m, t_call l)
{
	if (m->map[m->p_l + 1][m->p_h] != '1')
	{
		if (m->map[m->p_l + 1][m->p_h] != 'E')
		{
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->zero,
				m->p_h * 50, m->p_l * 50);
			m->p_l++;
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->player_d,
				m->p_h * 50, m->p_l * 50);
			if (m->map[m->p_l][m->p_h] == 'C')
			{
				l.c--;
				m->map[m->p_l][m->p_h] = '0';
			}
			if (m->map[m->p_l][m->p_h] == 'B')
			{
				write (1, "YOU WIN\n", 8);
				exit(1);
			}
			g_m++;
			ft_putnbr(g_m);
			write (1, "\n", 1);
		}
	}
	return (l);
}

t_call	ft_right(t_call_2 *m, t_call l)
{
	if (m->map[m->p_l][m->p_h + 1] != '1')
	{
		if (m->map[m->p_l][m->p_h + 1] != 'E')
		{
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->zero,
				m->p_h * 50, m->p_l * 50);
			m->p_h++;
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->player_r,
				m->p_h * 50, m->p_l * 50);
			if (m->map[m->p_l][m->p_h] == 'C')
			{
				l.c--;
				m->map[m->p_l][m->p_h] = '0';
			}
			if (m->map[m->p_l][m->p_h] == 'B')
			{
				write (1, "YOU WIN\n", 8);
				exit(1);
			}
			g_m++;
			ft_putnbr(g_m);
			write (1, "\n", 1);
		}
	}
	return (l);
}

t_call	ft_left(t_call_2 *m, t_call l)
{
	if (m->map[m->p_l][m->p_h - 1] != '1')
	{
		if (m->map[m->p_l][m->p_h - 1] != 'E')
		{
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->zero,
				m->p_h * 50, m->p_l * 50);
			m->p_h--;
			mlx_put_image_to_window(m->mlx, m->mlx_wind, m->player_l,
				m->p_h * 50, m->p_l * 50);
			if (m->map[m->p_l][m->p_h] == 'C')
			{
				l.c--;
				m->map[m->p_l][m->p_h] = '0';
			}
			if (m->map[m->p_l][m->p_h] == 'B')
			{
				write (1, "YOU WIN\n", 8);
				exit(1);
			}
			g_m++;
			ft_putnbr(g_m);
			write (1, "\n", 1);
		}
	}
	return (l);
}

int	key_hook(int key, t_call_2 *m)
{
	t_call	l;

	l = check_map4(m->map);
	if (key == 126 || key == 13)
		l = ft_up(m, l);
	if (key == 125 || key == 1)
		l = ft_down(m, l);
	if (key == 124 || key == 2)
		l = ft_right(m, l);
	if (key == 123 || key == 0)
		l = ft_left(m, l);
	if (l.c == 0)
		m->map[m->e_l][m->e_h] = 'B';
	if (key == 53)
		exit_mouse(-1);
	return (0);
}
