/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:50:57 by exam              #+#    #+#             */
/*   Updated: 2017/03/21 11:50:59 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin_mult.h"

unsigned	ft_strlen(char *str)
{
	unsigned size;

	size = 0;
	while (*str)
		(str++) && ++size;
	return (size);
}

void		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void		ft_minus(char *str1, char *str2, char *result, int *counter)
{
	if ((str1[0] == '-' && str2[0] != '-'))
		(result[(*counter)++] = '-');
	else if ((str2[0] == '-' && str1[0] != '-'))
		(result[(*counter)++] = '-');
}

int			ft_zero(char *str1, char *str2)
{
	if (str1[0] == 48 || str2[0] == 48)
		return (1);
	return (0);
}
