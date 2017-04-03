/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:38:35 by exam              #+#    #+#             */
/*   Updated: 2017/02/28 12:42:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

int		ft_strlen(char *str)
{
	int len;
	int counter;

	counter = -1;
	len = 0;
	while (str[++counter])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		ft_minus(char **argv)
{
	if ((argv[1][0] == '-' || argv[2][0] == '-') &&
			!(argv[1][0] == '-' && argv[2][0] == '-') && argv[1][0] != 0
			&& argv[2][0] != 0)
		return (1);
	else
		return (0);
}

int		ft_zero(char **argv, char **str)
{
	if (argv[1][0] == 48 || argv[2][0] == 48)
	{
		(*str)[0] = 48;
		(*str)[1] = 0;
		return (1);
	}
	return (0);
}

void	ft_transform(char **a, int **num)
{
	int		cou_scou[2];
	int		f_c;
	int		s_c;
	char	*f;
	char	*s;

	f = a[1];
	s = a[2];
	s_c = ft_strlen(s);
	cou_scou[1] = 0;
	while (s[--s_c] && s[s_c] != '-')
	{
		f_c = ft_strlen(f);
		cou_scou[0] = -1;
		while (f[--f_c] && f[f_c] != '-')
			(*num)[++cou_scou[0] + cou_scou[1]] +=
				(f[f_c] - 48) * (s[s_c] - 48);
		cou_scou[1]++;
	}
}
