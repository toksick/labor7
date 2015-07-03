#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "sorting.h"

int qpart(int *array, int l, int h){
	int iPivot = (l+h)/2;
	int pivot = array[iPivot];

	array[iPivot] = array[h];
	array[h] = pivot;
	int i, temp;
	int j = l;
	for (i = l; i < h; ++i) {
		if(array[i]<=pivot){
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			j++;
		}
	}
	temp = array[j];
	array[j] = array[h];
	array[h] = temp;
	return j;
}

void quicksort(int *array, int l, int h){
	if (l < h) {
		int iPivot = qpart(array, l, h);
		quicksort(array, l, iPivot-1);
		quicksort(array, iPivot+1, h);
	}
}
