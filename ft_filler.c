/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:11:56 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/01 11:11:58 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_set_player(t_game *d, char *s)
{
	if (ft_strstr(s, "p1"))
		d->pl = 'O';
	else
		d->pl = 'X';
	d->op = d->pl == 'O' ? 'X' : 'O';
	free(s);
}

int		ft_dif_point(int o_y, int o_x, int p_y, int p_x)
{
	int res;

	res = 0;
	res = (o_y - p_y) + (o_x - p_x);
	res = res < 0 ? res * (-1) : res;
	return (res);
}

void	ft_set_token(t_game *d)
{
	int		i;
	int		j;
	int		res;
	t_point *temp;

	temp = d->pll;
	i = d->pll->x;
	j = d->pll->y;
	res = ft_dif_point(d->opp->y, d->opp->x, d->pll->y, d->pll->x);
	while (temp)
	{
		if (res > ft_dif_point(d->opp->y, d->opp->x, temp->y, temp->x))
		{
			res = ft_dif_point(d->opp->y, d->opp->x, temp->y, temp->x);
			i = temp->x;
			j = temp->y;
		}
		temp = temp->next;
	}
	ft_printf("%d %d\n", j, i);
}

void	ft_main_algo(t_game *d)
{
	ft_find_valid_points(d);
	if (!(d->pll))
	{
		ft_printf("0 0\n");
		exit(EXIT_FAILURE);
	}
	ft_find_opponent_points(d);
	ft_set_token(d);
	ft_delete_all(d);
}

int		main(void)
{
	char	*line;
	t_game	d;

	line = NULL;
	ft_bzero(&d, sizeof(t_game));
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "dtomchys.filler"))
			ft_set_player(&d, line);
		else if (ft_strstr(line, "Plateau"))
			d.map = ft_set_map(&d, line);
		else if (ft_strstr(line, "Piece"))
		{
			d.tok = ft_set_tok(&d, line);
			ft_main_algo(&d);
		}
		else
			free(line);
	}
	return (0);
}
