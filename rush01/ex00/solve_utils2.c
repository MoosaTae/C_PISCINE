/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawongpr <sawongpr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:27:06 by sawongpr          #+#    #+#             */
/*   Updated: 2023/06/18 23:35:12 by sawongpr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_height_left(int *row, int N)
{
	int	j;
	int	maxx;
	int	cnt;

	j = 0;
	maxx = 0;
	cnt = 0;
	while (++j <= N)
	{
		if (row[j] > maxx)
		{
			maxx = row[j];
			cnt++;
		}
	}
	return (cnt);
}

int	check_height_left_range(int **b, int N, int i)
{
	int	j;
	int	maxx;
	int	cnt;
	int	high;

	j = 0;
	maxx = 0;
	cnt = 0;
	while (++j <= N)
	{
		if (b[i][j] > maxx)
		{
			maxx = b[i][j];
			cnt++;
		}
	}
	high = cnt + N - maxx;
	if (maxx != N)
		cnt++;
	if (cnt > b[i][0] || high < b[i][0])
		return (0);
	return (1);
}

int	check_height_right(int *row, int N)
{
	int	j;
	int	maxx;
	int	cnt;

	j = N + 1;
	maxx = 0;
	cnt = 0;
	while (--j >= 1)
	{
		if (row[j] > maxx)
		{
			maxx = row[j];
			cnt++;
		}
	}
	return (cnt);
}

int	check_height_up(int **b, int N, int i)
{
	int	j;
	int	maxx;
	int	cnt;

	j = 0;
	maxx = 0;
	cnt = 0;
	while (++j <= N)
	{
		if (b[j][i] > maxx)
		{
			maxx = b[j][i];
			cnt++;
		}
	}
	return (cnt);
}

int	check_height_down(int **b, int N, int i)
{
	int	j;
	int	maxx;
	int	cnt;

	j = N + 1;
	maxx = 0;
	cnt = 0;
	while (--j >= 1)
	{
		if (b[j][i] > maxx)
		{
			maxx = b[j][i];
			cnt++;
		}
	}
	return (cnt);
}
