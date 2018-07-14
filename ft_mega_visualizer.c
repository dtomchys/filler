/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mega_visualizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtomchys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:25:28 by dtomchys          #+#    #+#             */
/*   Updated: 2018/03/02 15:25:30 by dtomchys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

#define RESET	"\x1B[0m"
#define RED		"\x1B[31m"
#define BLUE	"\x1B[34m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define PURPLE	"\x1B[35m"

void			ft_perform_player(char *s)
{
	if (ft_strstr(s, "p1"))
		printf(BLUE "%s\n" RESET, s);
	if (ft_strstr(s, "p2"))
		printf(RED "%s\n" RESET, s);
}

void			ft_set_field(char *s)
{
	while (*s)
	{
		if (*s == 'X')
			printf(RED "%c" RESET, *s);
		else if (*s == 'x')
			printf(GREEN "%c" RESET, *s);
		else if (*s == 'O')
			printf(BLUE "%c" RESET, *s);
		else if (*s == 'o')
			printf(YELLOW "%c" RESET, *s);
		else
			printf("%c", *s);
		s++;
	}
	printf("\n");
}

void			ft_print_res(char *s)
{
	int i;
	int x;
	int o;

	i = 0;
	while (!ft_isdigit(s[i]))
		i++;
	o = ft_atoi(s + i);
	free(s);
	get_next_line(0, &s);
	i = 0;
	while (!ft_isdigit(s[i]))
		i++;
	x = ft_atoi(s + i);
	if (o > x)
		printf(BLUE "%s[%d, %d]\n" RESET, "Player 1 WON", o, x);
	else if (o < x)
		printf(RED "%s[%d, %d]\n" RESET, "Player 2 WON", o, x);
	else
		printf(PURPLE "%s[%d, %d]\n" RESET, "DRAW", o, x);
	free(s);
	exit(EXIT_SUCCESS);
}

int				main(void)
{
	char	*line;
	int		i;

	i = -1;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$"))
			ft_perform_player(line);
		else if (ft_isdigit(line[0]))
			ft_set_field(line);
		else if (ft_strstr(line, "="))
			ft_print_res(line);
		else if (line[0] == ' ' || line[0] == '.' || line[0] == '*'
			|| line[0] == 'P' || line[0] == '<')
			printf("%s\n", line);
		free(line);
	}
	return (0);
}
