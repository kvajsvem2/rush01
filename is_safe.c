/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_safe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:57:15 by zzibert           #+#    #+#             */
/*   Updated: 2018/03/25 12:01:26 by zzibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		sub_grid(int n, int r, int c, char **argv);

int		is_safe(int n, int r, int c, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < 9)
	{
		if (argv[r][i] == '0' + n)
			return (0);
		i++;
	}	
	while (j < 10)
	{
		if (argv[j][c] == '0' + n)
			return (0);
		j++;
	}
	if (sub_grid(n, r, c, argv) == 0)
		return (0);
	return (1);
}
