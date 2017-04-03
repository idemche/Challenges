/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_part1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 22:48:10 by idemchen          #+#    #+#             */
/*   Updated: 2017/03/31 22:48:47 by idemchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void print_array(int *ar, int size)
{
	for (int i = 0; i < size; i++)
			__builtin_printf("%d ", ar[i]);
		__builtin_printf("\n");
}

void insertionSort(int ar_size, int *ar)
{
	int last;

	int size = ar_size;
	last = ar[--ar_size];
	while (ar_size-- >= 0)
	{
		ar[ar_size + 1] = (ar[ar_size] > last) ? ar[ar_size] : last;
		print_array(ar, size);
		if (ar[ar_size] <= last)
			break;
		ar[ar_size] = (ar_size == 0) ? last :
		ar[ar_size];
	}
}

int main(void) 
{
    int _ar_size;
    scanf("%d", &_ar_size);
    int array[_ar_size];

    for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++)
        scanf("%d", &array[_ar_i]); 
    insertionSort(_ar_size, array);
    return 0;
}
