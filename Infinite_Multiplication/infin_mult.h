/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:52:38 by exam              #+#    #+#             */
/*   Updated: 2017/03/21 11:52:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFIN_MULT_H
# define INFIN_MULT_H
# include <unistd.h>
# include <stdlib.h>

unsigned	ft_strlen(char *str);
void		ft_putstr(char *str);
void		ft_minus(char *str1, char *str2, char *result, int *counter);
int			ft_zero(char *str1, char *str2);
void		ft_mallocate(int **mult, char **result, int lns[2]);
int			ft_mult(char *one, char *two, int *mult);
void		ft_final_transform(int *mult, char *result,
			int size, int *iterator);

#endif
