/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:14:39 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/01 16:14:40 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_get_size(char *s, t_game *d)
{
	char **token;

	token = ft_strsplit(s, ' ');
	if (ft_strstr(token[0], "Plateau"))
	{
		d->m_row = ft_atoi(token[1]);
		d->m_col = ft_atoi(token[2]);
	}
	else
	{
		d->t_row = ft_atoi(token[1]);
		d->t_col = ft_atoi(token[2]);
	}
	ft_free(token, 3);
}

char			**ft_set_tok(t_game *d, char *s)
{
	int i;

	ft_get_size(s, d);
	free(s);
	i = 0;
	d->tok = (char**)malloc(sizeof(char*) * d->t_row);
	while (i < d->t_row && get_next_line(0, &s) > 0)
	{
		d->tok[i] = ft_strdup(s);
		free(s);
		i++;
	}
	return (d->tok);
}

char			**ft_set_map(t_game *d, char *s)
{
	int i;

	ft_get_size(s, d);
	free(s);
	get_next_line(0, &s);
	free(s);
	i = 0;
	d->map = (char**)malloc(sizeof(char*) * d->m_row);
	while (i < d->m_row && get_next_line(0, &s) > 0)
	{
		d->map[i] = ft_strdup(s + 4);
		free(s);
		i++;
	}
	return (d->map);
}
