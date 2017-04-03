/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:37:16 by exam              #+#    #+#             */
/*   Updated: 2017/02/28 12:38:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_MULT_H
# define INFIN_MULT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_minus(char **argv);
int		ft_zero(char **argv, char **str);
void	ft_transform(char **a, int **num);
void	ft_allign(int **num, int size);
void	ft_malloch(char **argv, char **str, int **num, int *len);
void	ft_tostr(char **str, int *num, int size);

#endif
