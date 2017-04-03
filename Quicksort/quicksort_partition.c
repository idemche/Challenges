/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_partition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 22:44:48 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 22:44:50 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define s_n write(1, "\n", 1)

int		ft_putnbr(int n)
{
	unsigned length;
	unsigned num;

	length = 1;
	num = (n < 0 && write(1, "-", 1)) ? -n : n;
	while ((n /= 10) && (length *= 10))
		;
	while (length)
		(n = (num / length) % 10 + 48) && write(1, &n, 1) && (length /= 10);
	return (1);
}

int		ft_putarray(int ar_size, int *array)
{
	int size;

	size = ar_size;
	while(ar_size)
		ft_putnbr(array[size - ar_size--]) && write(1, " ", 1);
	return (1);
}

void partition(int ar_size, int *array)
{
	int main_iter;
	int counters[2];
	int l_e_r[3][ar_size];

	main_iter = 2;
	while (main_iter-- > 0)
		counters[main_iter] = 0;
	l_e_r[1][0] = array[0];
	while (((main_iter == -1 ) ? main_iter += 2 : ++main_iter)  < ar_size)
	{
		if (array[main_iter] >= l_e_r[1][0])
			l_e_r[2][counters[1]++] = array[main_iter];
		else
			l_e_r[0][counters[0]++] = array[main_iter];
	}
	ft_putarray(counters[0], l_e_r[0]);
	ft_putnbr(l_e_r[1][0]);
	write(1, " ", 1);
	ft_putarray(counters[1], l_e_r[2]);
}

int main(void)
{
	int array_size;
	scanf("%d", &array_size);
	int array[array_size];
	for(int _ar_i = 0; _ar_i < array_size; _ar_i++) 
		scanf("%d", &array[_ar_i]); 
	partition(array_size, array);
	return 0;
}
