/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 10:04:31 by exam              #+#    #+#             */
/*   Updated: 2017/03/21 10:18:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void		ft_mallocate(int **mult, char **result, int lns[2])
{
	int size;

	size = lns[0] + lns[1] + 1;
	*mult = (int*)malloc(sizeof(int) * size);
	*result = (char*)malloc(sizeof(char) * size);
	while (size)
		(*mult)[size--] = 0;
}

int			ft_mult(char *one, char *two, int *mult)
{
	int counter[2];
	int iterators[2];

	while (*one == '-')
		one++;
	while (*two == '-')
		two++;
	counter[0] = ft_strlen(one);
	iterators[1] = 0;
	while (--counter[0] >= 0)
	{
		counter[1] = ft_strlen(two);
		iterators[0] = iterators[1];
		while (--counter[1] >= 0)
			mult[iterators[0]++] +=
			(one[counter[0]] - 48) * (two[counter[1]] - 48);
		iterators[1]++;
	}
	return (iterators[0]);
}

void		ft_final_transform(int *mult, char *result, int size, int *iterator)
{
	int counter;

	counter = size + 1;
	while (--counter >= 0)
		if (mult[counter] >= 10)
		{
			mult[counter + 1] += (mult[counter] / 10);
			mult[counter] %= 10;
			counter = size + 1;
		}
	while (mult[size] == 0)
		size--;
	while (size >= 0)
		result[(*iterator)++] = mult[size--] + 48;
	result[(*iterator)] = 0;
}

int			main(int argc, char *av[])
{
	int		*mult;
	int		lns[2];
	int		counter[2];
	char	*result;

	if (argc == 3)
	{
		counter[0] = 0;
		lns[0] = ft_strlen(av[1]);
		lns[1] = ft_strlen(av[2]);
		if (ft_zero(av[1], av[2]))
			return (write(1, "0\n", 2));
		ft_mallocate(&mult, &result, lns);
		ft_minus(av[1], av[2], result, &counter[0]);
		ft_final_transform(mult, result,
				ft_mult(av[1], av[2], mult), &counter[0]);
		ft_putstr(result);
	}
	return (write(1, "\n", 1));
}
