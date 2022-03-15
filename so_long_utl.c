/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:28:25 by ydahni            #+#    #+#             */
/*   Updated: 2022/03/15 05:40:56 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] == '1')
			j++;
		else
			error();
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) == j)
			i++;
		else
			error();
	}
}

void	check_map2(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			error();
		i++;
	}
	while (map[i - 1][j])
	{
		if (map[i - 1][j] == '1')
			j++;
		else
			error();
	}
}

void	check_map3(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != 'C' && map[i][j] != 'P')
				error();
			j++;
		}
		i++;
	}
}

t_call	check_map4(char **map)
{
	int		i;
	int		j;
	t_call	k;

	k.c = 0;
	k.e = 0;
	k.p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				k.e++;
			else if (map[i][j] == 'C')
				k.c++;
			else if (map[i][j] == 'P')
				k.p++;
			j++;
		}
		i++;
	}
	return (k);
}

void	check_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (str[i + 1] != 'b' )
		error();
	if (str[i + 2] != 'e')
		error();
	if (str[i + 3] != 'r' )
		error();
	if (str[i + 4])
		error();
}
