/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_inplace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 22:42:59 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 22:43:06 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define transition write(1, "\n", 1)

char	ft_putnbr(int n)
{
	unsigned n_l[2];

	n_l[1] = 1;
	n_l[0] = (n < 0 && write(1, "-", 1)) ? -n : n;
	while((n /= 10) && (n_l[1] *= 10))
		;
	while (n_l[1])
		(n = (n_l[0] / n_l[1]) % 10 + 48) && write(1, &n, 1) && (n_l[1] /= 10);
	return (1);
}

void	ft_putarray(int ar_size, int *array)
{
	while (ar_size--)
		ft_putnbr(*array++) && write(1, " ", 1);
}

char	xor_swap(int *a, int *b)
{
	if(a == b)
		return (0);
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	return (1);
}

int partition(int *array, int left, int right)
{
	int pivot;
	int one;
	int two;

	one = left - 1;
	two = left - 1;
	pivot = array[right];
	while(++two < right)
		if (array[two] <= pivot)
			xor_swap(&(array[++one]), &array[two]);
	xor_swap(&(array[one + 1]), &array[right]);
	return (one + 1);
}

void quicksort(int *array, int left, int right, int array_size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		ft_putarray(array_size, array);
		transition;
		quicksort(array, left, pivot - 1, array_size);
		quicksort(array, pivot + 1, right, array_size);
	}
}

int		main(int argc, char **argv)
{
    int *array;
    int array_size;
    int counter;

    counter = 0;
    scanf("%d", &array_size);
    array = (int*)malloc(sizeof(int) * array_size);
    while(counter < array_size)
    	scanf("%d", &array[counter++]);
    quicksort(array, 0, array_size - 1, array_size);
    return 0;
}
