/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:56:31 by zzibert           #+#    #+#             */
/*   Updated: 2018/03/25 13:52:59 by zzibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sub_grid(int n, int r, int c, char **argv)
{
	int		row_start;
	int		column_start;
	int		i;
	int		j;

	row_start = ((r - 1) / 3) * 3 + 1;
	column_start = (c / 3) * 3;
	i = row_start;
	while (i < row_start + 3)
	{
		j = column_start;
		while (j < column_start + 3)
		{
			if (argv[i][j] == '0' + n)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
