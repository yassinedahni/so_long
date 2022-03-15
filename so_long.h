/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:21:44 by ydahni            #+#    #+#             */
/*   Updated: 2022/03/15 05:45:37 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

int	g_m;

typedef struct call
{
	int	p;
	int	e;
	int	c;
}	t_call;

typedef struct call_2
{
	void	*mlx;
	void	*mlx_wind;
	void	*player_f;
	void	*player_d;
	void	*player_l;
	void	*player_r;
	void	*wall;
	void	*zero;
	void	*coins;
	void	*exit;
	char	**map;
	int		h;
	int		l;
	int		p_h;
	int		p_l;
	int		e_h;
	int		e_l;
}	t_call_2;

int		ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
int		chercheline(char *str);
char	*get_line(int fd, char *a);
char	*beforline(char *a);
char	*get_next_line(int fd);
int		ft_strchr(char *str);
int		ft_counterword(char *s, char c);
int		ft_counterchar(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *str);
void	check_map(char **map);
void	check_map2(char **map);
void	check_map3(char **map);
t_call	check_map4(char **map);
void	check_name(char *str);
void	error(void);
void	so_long_paint(t_call_2 m);
void	ft_putnbr(int n);
t_call	ft_up(t_call_2 *m, t_call l);
t_call	ft_down(t_call_2 *m, t_call l);
t_call	ft_right(t_call_2 *m, t_call l);
t_call	ft_left(t_call_2 *m, t_call l);
int		key_hook(int key, t_call_2 *m);
int		exit_mouse(int key);

#endif