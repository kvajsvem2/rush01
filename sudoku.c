/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:50:48 by zzibert           #+#    #+#             */
/*   Updated: 2018/03/24 16:08:25 by zzibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_possible(char **argv, int i, int j);

void	sudoku_printer(int argc, char **argv);

void	sudoku_solver(char **argv, int i, int j);

int		check_box(char **argv, int i, int j);

int		check_box(char **argv, int i, int j)
{
	int		box_i;
	int		box_j;
	int		k;
	int		l;

	box_i = (i - 1) / 3;
	box_j = j / 3;
	k = 0;
	while (k < 2)
	{
		l = 0;
		while (l < 2)
		{
			if (i != box_i && j != box_j)
			{
				if (argv[i][j] == argv[box_i][box_j])
					return (0);
			}
			l++;
			box_j++;
		}
		k++;
		box_i++;
	}
	return (1);
}

void	sudoku_solver(char **argv, int i, int j)
{
	int		number;
	if (argv[i][j] != '.')
	{
		if (j == 8)
			sudoku_solver(argv, i + 1, 0);
		else
			sudoku_solver(argv, i, j + 1);
	}

	number = 0;
	while (number < 10 && is_possible(argv, i, j) == 0)
	{
		number++;
		argv[i][j] = number;
	}
	if (i == 8 && j == 8)
		return ;
	else if (j < 8)
		sudoku_solver(argv, i, j + 1);
	else
		sudoku_solver(argv, i + 1, 0);
}

int		is_possible(char **argv, int i, int j)
{
	int row;
	int column;

	column = 0;
	row = 0;
	while (column < 9)
	{
		if (column == j)
			column++;
		if (argv[column][j] == argv[i][j])
			return (0);
		column++;
	}
	while (row < 9)
	{
		if (row == i)
			row++;
		if (argv[i][row] == argv[i][j])
			return (0);
		row++;
	}
	if (check_box(argv, i, j) == 0)
		return (0);
	return (1);
}

void	sudoku_printer(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			c = argv[i][j];
			write(1, &c, 1);
			c = ' ';
			write(1, &c, 1);
			j++;
		}
		c = '\n';
		write(1, &c, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	sudoku_printer(argc, argv);
	sudoku_solver(argv, 0, 0);
	sudoku_printer(argc, argv);
	return (0);
}
