#include <stdio.h>
#include <string.h>

void	comparemerge(int a[], int l, int mid, int r, int ll, int rr)
{
	int	i;
	int	*al;
	int	*ar;

	*al = malloc((m - l  + 2)*sizeof(int));
	while (++ll < mid)
		al[ll] = a[l + ll];
	while (++rr < r)
		ar[rr] = a[mid + rr];
	i = l;
	ll = 0;
	rr = 0;
	while (ll < l && rr < r - mid)
	{
		if (al[ll] > ar[rr])
			a[i++] = ar[rr++];
		else
			a[i++] = al[ll++];
	}
	while (ll < l)
		a[i++] = al[ll++];
	while (rr < r - mid)
		a[i++] = al[rr++];
}


void	merge(int a[], int l, int mid, int r)
{
	int	ll;
	int	rr;

	ll = -1;
	rr = -1;
	comparemerge(a, l, mid, r, ll, rr);
}

void	mergesort(int a[], int l, int r)
{
	int	mid;

	mid = (l + r) / 2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	merge(a, l, mid, r);
}

int	main(void)
{
	return (0);
}
