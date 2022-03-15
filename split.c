/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydahni <ydahni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 21:20:32 by ydahni            #+#    #+#             */
/*   Updated: 2022/03/13 21:35:35 by ydahni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_counterword(char *s, char c)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (s[i] != c)
		x++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			x++;
		i++;
	}
	return (x);
}

int	ft_counterchar(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	new = malloc(sizeof(char *) * (ft_counterword(s, c) + 1));
	if (!new)
		return (NULL);
	while (s[i])
	{
		while (j < ft_counterword(s, c))
		{
			while (s[i] == c && s[i])
				i++;
			new[j++] = ft_substr(s, i, ft_counterchar(s + i, c));
			i += ft_counterchar(s + i, c);
		}
		if (s[i])
			i++;
	}
	new[j] = NULL;
	return (new);
}
