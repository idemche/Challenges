/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 22:43:51 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 22:44:01 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#define string(s) #s
#define sn write(1, "\n", 1)

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

void ft_re_write(int ar_size, int counters[2], int *old, int **new)
{
	int *array;

	array = (int*)new;
	counters[1] += counters[0];
	while (counters[1]-- > counters[0])
		old[counters[1] + 1] = array[2 * ar_size + (counters[1] - counters[0])];	
	old[++counters[1]] = array[1 * ar_size + 0];
	while (counters[0]-- >= 0)
		old[counters[0]] = array[counters[0]];
}

void quickSort(int ar_size, int *array)
{
   int l_e_r[3][ar_size];
   int counters[2];
   int iterator;

   iterator = 2;
   while (iterator-- > 0)
   	counters[iterator] = 0;
   l_e_r[1][0] = array[++iterator];
   while (++iterator < ar_size)
   	(array[iterator] > l_e_r[1][0]) ?
   		(l_e_r[2][counters[1]++] = array[iterator])
   	:
   		(l_e_r[0][counters[0]++] = array[iterator]);
   	if (counters[0] > 1)
   		quickSort(counters[0], l_e_r[0]);
   	if (counters[1] > 1)
   		quickSort(counters[1], l_e_r[2]);
   	ft_re_write(ar_size, counters, array, (int**)l_e_r);
   	ft_putarray(ar_size, array);
   	sn;
}

int main(int argc, char **argv)
{
   int ar_size;
   scanf("%d", &ar_size);
   int ar[ar_size], i;
   for(i = 0; i < ar_size; i++)
      scanf("%d", &ar[i]); 
 
   quickSort(ar_size, ar);
   return 0;
}
