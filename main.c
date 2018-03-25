/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:49:11 by zzibert           #+#    #+#             */
/*   Updated: 2018/03/25 13:36:20 by zzibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	print_sudoku(int argc, char **argv);

int		solve_sudoku(char **argv, int *row, int *column);

void	print_sudoku(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < 9)
		{
			c = argv[i][j];
			write(1, &c, 1);
			if (j != 8)
			{
				c = ' ';
				write(1, &c, 1);
			}
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int row;
	int column;
	int rowcp;
	int columncp;

	rowcp = 1;
	columncp = 0;
	row = 1;
	column = 0;
	if (solve_sudoku(argv, &row, &column))
		print_sudoku(argc, argv);
	else
		printf("ERROR");
	return (0);
}
