/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_opponent_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:01:41 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/02 15:01:43 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_module(int from, t_game *d, int new_y, int new_x)
{
	int res;
	int temp;

	res = 0;
	temp = 0;
	if (!from)
	{
		res = ((0 - d->opp->y) + (0 - d->opp->x));
		res = res < 0 ? res * (-1) : res;
		temp = ((0 - new_y) + (0 - new_x));
		temp = temp < 0 ? temp * (-1) : temp;
		return (res > temp ? 1 : 0);
	}
	else
	{
		res = (d->m_row - d->opp->y) + (d->m_col - d->opp->x);
		temp = (d->m_row - new_y) + (d->m_col - new_x);
		return (res > temp ? 1 : 0);
	}
}

static void	ft_from_begin(t_game *d)
{
	int i;
	int j;

	j = -1;
	while (++j < d->m_row)
	{
		i = -1;
		while (++i < d->m_col)
		{
			if (!d->opp && (d->map[j][i] == d->op ||\
				d->map[j][i] == d->op + 32))
				ft_pointswap(&(d->opp), j, i);
			else if ((d->map[j][i] == d->op || d->map[j][i] == d->op + 32) &&\
				ft_module(0, d, i, j))
				ft_pointswap(&(d->opp), j, i);
		}
	}
}

static void	ft_from_end(t_game *d)
{
	int i;
	int j;

	j = d->m_row - 1;
	while (j)
	{
		i = d->m_col - 1;
		while (i)
		{
			if (!d->opp && (d->map[j][i] == d->op ||\
				d->map[j][i] == d->op + 32))
			{
				ft_pointswap(&(d->opp), j, i);
			}
			else if ((d->map[j][i] == d->op || d->map[j][i] == d->op + 32) &&\
				ft_module(1, d, i, j))
				ft_pointswap(&(d->opp), j, i);
			i--;
		}
		j--;
	}
}

void		ft_find_opponent_points(t_game *d)
{
	static int part;

	if (!part)
	{
		ft_from_begin(d);
		part = 1;
	}
	else
	{
		ft_from_end(d);
		part = 0;
	}
}
