/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:17:26 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/01 16:17:27 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_delete_all(t_game *d)
{
	t_point *next;

	if (d->pll)
	{
		while (d->pll)
		{
			next = d->pll->next;
			d->pll->x = 0;
			d->pll->y = 0;
			d->pll->next = NULL;
			free(d->pll);
			d->pll = next;
		}
		d->pll = NULL;
	}
	if (d->opp)
	{
		d->opp->x = 0;
		d->opp->y = 0;
		free(d->opp);
		d->opp = NULL;
	}
	ft_free(d->map, d->m_row);
	ft_free(d->tok, d->t_row);
}

void	ft_free(char **s, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		ft_bzero(s[i], ft_strlen(s[i]));
		free(s[i]);
		s[i] = NULL;
	}
}

void	ft_pointadd(t_point **lst, int y, int x)
{
	t_point *temp;
	t_point *head;

	if (!(*lst))
	{
		*lst = (t_point*)malloc(sizeof(t_point));
		(*lst)->x = x;
		(*lst)->y = y;
		(*lst)->next = NULL;
	}
	else
	{
		head = *lst;
		while (head->next)
			head = head->next;
		temp = (t_point*)malloc(sizeof(t_point));
		temp->x = x;
		temp->y = y;
		temp->next = NULL;
		head->next = temp;
	}
}

void	ft_pointswap(t_point **lst, int y, int x)
{
	if (!(*lst))
	{
		*lst = (t_point*)malloc(sizeof(t_point));
		(*lst)->x = x;
		(*lst)->y = y;
		(*lst)->next = NULL;
	}
	else
	{
		(*lst)->x = x;
		(*lst)->y = y;
	}
}
