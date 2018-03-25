/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:53:53 by zzibert           #+#    #+#             */
/*   Updated: 2018/03/25 13:24:54 by zzibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		number_unassigned(char **argv, int *row, int *column);

int		is_safe(int i, int row, int column, char **argv);

int		solve_sudoku(char **argv)
{
	int i;
	int row;
	int column;	

	if (number_unassigned(argv, &row, &column) == 0)
		return (1);
	i = 1;
	while (i < 10)
	{
		if (is_safe(i, row, column, argv) == 1)
		{
			argv[row][column] = i + '0';
			if (solve_sudoku(argv))
				return (1);
			argv[row][column] = '.';
		}
		i++;
	}
	return (0);
}
