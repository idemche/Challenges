/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 22:49:22 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 22:49:26 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#define s_n write(1, "\n", 1)
#define deb __builtin_printf("counter: {%d} counter - 1 {%d}", array[counter], array[counter -1])

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
	return (s_n);
}


int		ft_sort(int ar_size, int *array)
{
	int last;
	int size;

	size = ar_size;
	last = array[--ar_size];
	while(--ar_size >= 0)
	{
		if (array[ar_size] > last)
			array[ar_size + 1] = array[ar_size];
		else if (array[ar_size] < last)
			return(array[ar_size + 1] = last);
		(ar_size == 0) ? array[ar_size] = last : 0;
	}
	return (1);
}

void insertionSort(int ar_size, int *array)
{
	int counter;

	counter = 0;
	while (++counter < ar_size)
	{
		if (array[counter] < array[counter - 1])
			ft_sort(counter + 1, array);
		ft_putarray(ar_size, array);
	}
}

int main(void)
{
	int ar_size;
	scanf("%d", &ar_size);
	int array[ar_size];
	for(int array_i = 0; array_i < ar_size; array_i++)
		scanf("%d", &array[array_i]);
	insertionSort(ar_size, array);
	return 0;
}
