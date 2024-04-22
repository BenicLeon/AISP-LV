#include <time.h>
#include<stdio.h>
#include <stdlib.h>

void swap(int*x, int*y) {

	int t = *x;
	*x = *y;
	*y = t;

}
void bubblesort(int*a, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);

}
void heapify(int *a, int n) {
	int i, j, k, broj;
	for (k = 1; k < n; k++) {
		broj = a[k];
		i = k;
		j = (i - 1) / 2;
		if (broj > a[j] && i > 0) {
			a[i] = a[j];
			i = j;
			j = (i - 1) / 2;
		}
		a[i] = broj;
	}

}

void podesi(int*a, int n) {
	int i, j, broj;
	j = 0;
	broj = a[j];
	i = 2 * j + 1;
	while (i <= n - 1) {
		if (i - 1 <= n - 1) {
			if (a[i] < a[i + 1]) {
				i++;
			}
		}
		if (broj < a[i]) {
			a[j] = a[i];
			j = i;
			i = 2 * i + 1;
		}
		else { break; }
		a[j] = broj;
	}

}

void heapsort(int*a, int n) {
	int i, t;
	heapify(a, n);
	for (i = 0; i < n; i++) {
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		podesi(a, i);
	}

}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = (int*)malloc(n1*sizeof(int));
	int *R = (int*)malloc(n2*sizeof(int));

	for (i = 0; i < n1; i++){
		L[i] = arr[l + i];}
	for (j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j];}

	i = 0; 
	j = 0;
	k = l; 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		
		int m = l + (r - l) / 2;

		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



int main() {
	int n,i;
	scanf("%d",&n);
    srand((unsigned)time(NULL));
	int *a =(int*)malloc(n*sizeof(int));
	for (i= 0; i < n; i++) {
		a[i] = rand()%100;
	}
	/*for(i=0;i<n;i++){
	    printf("%d\t",*(a+i));
	}*/
	//printf("\n");
	time_t t1, t2, t3, t4,t5,t6;
	t1 = clock();
	bubblesort(a, n);
	t2 = clock();
    /*for(i=0;i<n;i++){
	    printf("%d\t",*(a+i));	}*/
	t3 = clock();
	heapsort(a, n);
	t4 = clock();
	
	t5=clock();
	merge_sort(a,0,n-1);
	t6=clock();
	
printf("\nVrijeme trajanja  bubblesorta je %ldms\n",t2-t1 );
printf("\nVrijeme trajanja heapsorta je %ldms\n",t4-t3 );
printf("\nVrijeme trajanja mergesorta je %ldms\n",t6-t5 );

free(a);

return 0;
}


