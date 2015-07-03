#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "sorting.h"

void selectionSort(int *array){

	int i,j;
	int min, temp;

	for (i = 0; i < maxlines; ++i) {
		min = i;
		for (j = i+1; j < maxlines; ++j) {
			if(array[j]<array[min]){
				min = j;
			}
		}
		temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}

void mergeSort(int *array, int n){
	if (n <=1) {
		return;
	}
	int l = n/2;
	int r = n-l;

	int links[l];
	int rechts[r];
	int i;
	for (i = 0; i < l; ++i) {
		links[i] = array[i];
	}
	for (i = 0; i < r; ++i) {
		rechts[i] = array[i+l];
	}
	mergeSort(links, l);
	mergeSort(rechts, r);
	int el = 0, er = 0;
	for (i = 0; i < n; ++i) {
		if (el >= l) {
			array[i] = rechts[er];
			er++;
		}
		else if (er >= r){
			array[i] = links[el];
			el++;
		}
		else if (links[el] < rechts[er]) {
			array[i] = links[el];
			el++;
		}
		else {
			array[i] = rechts[er];
			er++;
		}
	}
}

void betterMerge(int n){
	int i, j;
	int laenge = 1;
	while(laenge <= n){

		for (i = 0; i < n; i=i+laenge) {
			printf("i: %d\n",i);
			for (j = i; j < i+laenge; ++j) {
				printf("j: %d\n",j);
			}
			printf("\n");
		}
		laenge = laenge*2;
		printf("laenge: %d\n",laenge);
	}
}
