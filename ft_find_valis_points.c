/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_valis_points.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 14:59:45 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/02 14:59:46 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_set_shape(t_game *d, int *sr)
{
	int j;
	int i;
	int row;

	i = -1;
	row = 0;
	while (++i < d->t_row)
	{
		j = -1;
		while (++j < d->t_col)
			if (d->tok[i][j] == '*')
				row++;
	}
	*sr = row;
}

static int		ft_check_tok(t_game *d, int y, int x)
{
	int i;
	int j;
	int sr;
	int err;

	j = -1;
	err = 0;
	ft_set_shape(d, &sr);
	while (++j < d->t_row && y + j < d->m_row)
	{
		i = -1;
		while (++i < d->t_col && i + x < d->m_col)
		{
			if (d->tok[j][i] == '*' && d->map[y + j][x + i] == d->pl && ++err)
				sr--;
			if (d->tok[j][i] == '*' && d->map[y + j][x + i] == EMPTY)
				sr--;
			if (d->tok[j][i] == '*' && d->map[y + j][x + i] == d->op)
				return (1);
		}
	}
	if (!sr && err == 1)
		return (0);
	return (1);
}

void			ft_find_valid_points(t_game *d)
{
	int i;
	int j;

	j = -1;
	while (++j < d->m_row)
	{
		i = -1;
		while (++i < d->m_col)
			if (!ft_check_tok(d, j, i))
				ft_pointadd(&(d->pll), j, i);
	}
}
