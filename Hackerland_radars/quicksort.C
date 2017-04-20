char xor_swap(int *a, int *b)
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

	one =
		two = left - 1;
	pivot = array[right];
	while(++two < right)
		if (array[two] <= pivot)
			xor_swap(&(array[++one]), &array[two]);
	xor_swap(&(array[one + 1]), &array[right]);
	return (one + 1);
}

void quicksort(int *array, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right);
		quicksort(array, left, pivot - 1);
		quicksort(array, pivot + 1, right);
	}
}
