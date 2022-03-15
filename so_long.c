/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:20:35 by ydahni            #+#    #+#             */
/*   Updated: 2022/03/15 05:42:35 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(char **s)
{
	t_call	t;

	check_map(s);
	check_map2(s);
	check_map3(s);
	t = check_map4(s);
	if (t.c == 0 || t.p != 1 || t.e == 0)
		error();
}

int	main(int ac, char **av)
{
	int			i;
	int			fd;
	char		*str;
	char		*new;
	t_call_2	m;

	i = 0;
	new = ft_strdup("");
	check_name(av[1]);
	fd = open(av[1], O_RDONLY);
	if (ac == 2)
	{
		str = get_next_line(fd);
		while (str)
		{
			new = ft_strjoin(new, str);
			free(str);
			str = get_next_line(fd);
		}
		m.map = ft_split(new, '\n');
		free (new);
		check_all(m.map);
		so_long_paint(m);
	}
}
