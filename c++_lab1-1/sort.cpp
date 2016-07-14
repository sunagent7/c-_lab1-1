void merge(int a[], int p, int q, int r)
{
	int sizeL = q - p + 1;
	int sizeR = r - q;
	int *L;
	int *R;
	L = new int[sizeL];
	R = new int[sizeR];

	int i, j, k;
	for (i = 0; i < sizeL; i++)
	{
		L[i] = a[p + i];
	}
	for (j = 0; j < sizeR; j++)
	{
		R[j] = a[q + 1 + j];
	}
	for (i = 0, j = 0, k = 0; k < r - p + 1; k++)
	{
		if (i < sizeL && L[i] <= R[j])
		{
			a[p + k] = L[i];
			i++;
		}
		else if (j < sizeR && L[i] > R[j])
		{
			a[p + k] = R[j];
			j++;
		}
		else if (i < sizeL)
		{
			a[p + k] = L[i];
			i++;
		}
		else
		{
			a[p + k] = R[j];
			j++;
		}
	}

	delete[] L;
	delete[] R;
}

void merge_sort(int a[], int p, int r)
{
	int q;
	if (p<r)
	{
		q = (r + p) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}

// function that sorts an array 
void sort(int a[], int size)
{
	// this place we use merge sort
	merge_sort(a, 0, size - 1);
}