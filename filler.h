/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:47:21 by dtomchys          #+#    #+#             */
/*   Updated: 2018/02/27 12:47:23 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# define EMPTY '.'

typedef struct			s_point
{
	int					y;
	int					x;
	struct s_point		*next;
}						t_point;

typedef struct			s_game
{
	char				pl;
	char				op;
	t_point				*opp;
	t_point				*pll;
	char				**map;
	char				**tok;
	int					m_row;
	int					m_col;
	int					t_row;
	int					t_col;
	int					s_row;
	int					s_col;
}						t_game;

char					**ft_set_tok(t_game *d, char *s);
char					**ft_set_map(t_game *d, char *s);
void					ft_free(char **s, int size);
void					ft_pointadd(t_point **lst, int y, int x);
void					ft_pointswap(t_point **lst, int y, int x);
void					ft_delete_all(t_game *d);
void					ft_find_valid_points(t_game *d);
void					ft_find_opponent_points(t_game *d);

#endif
