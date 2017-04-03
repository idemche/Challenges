/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:36:07 by exam              #+#    #+#             */
/*   Updated: 2017/02/28 12:36:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

void	ft_allign(int **num, int size)
{
	int	counter;
	int	length;

	counter = 0;
	length = size;
	while (size >= 0)
	{
		if ((*num)[size] >= 10)
		{
			(*num)[size + 1] += (*num)[size] / 10;
			(*num)[size] %= 10;
			size = length;
			continue;
		}
		size--;
	}
}

void	ft_malloch(char **argv, char **str, int **num, int *len)
{
	*str = (char*)malloc(sizeof(char) * (*len));
	*num = (int*)malloc(sizeof(int) * (*len + 1));
	*len += 2;
	while ((*len)-- > 0)
		(*num)[(*len)] = 0;
	(ft_minus(argv)) ? ((*str)[0] = '-') : 0;
}

void	ft_tostr(char **str, int *num, int size)
{
	int counter;

	counter = ((*str)[0] == '-') ? 1 : 0;
	while (num[size] == 0)
		size--;
	size += 1;
	while (size-- && num[size] >= 0 && num[size] < 10)
	{
		(*str)[counter] = num[size] + 48;
		counter++;
	}
	(*str)[counter] = '\0';
}

int		main(int argc, char **argv)
{
	int		len;
	char	*str;
	int		*num;

	if (argc == 3)
	{
		len = ft_strlen(argv[1]) + ft_strlen(argv[2]);
		ft_malloch(argv, &str, &num, &len);
		if (ft_zero(argv, &str))
			return (write(1, "0\n", 2));
		ft_transform(argv, &num);
		len = ft_strlen(argv[1]) + ft_strlen(argv[2]);
		ft_allign(&num, len);
		ft_tostr(&str, num, len);
		ft_putstr(str);
	}
	else
		write(1, "\n", 1);
	return (0);
}
