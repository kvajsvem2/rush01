/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_unassigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzibert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:58:03 by zzibert           #+#    #+#             */
/*   Updated: 2018/03/25 12:07:12 by zzibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		number_unassigned(char **argv, int *row, int *column)
{
	int		i;
	int		j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (argv[i][j] == '.')
			{
				*row = i;
				*column = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
