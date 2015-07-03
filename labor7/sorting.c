#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "sorting.h"
#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"

int maxlines;

int main(int argc, char *argv[]){

	FILE *in = stdin;
	if(argc >2){
		fprintf(stderr, "Usage: %s"
				"[<file>]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if(argc == 2){
		in = fopen(argv[1], "r");
		if(!in){
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	int arrayMer[100000];
	int arraySel[100000];
	int arrayQui[100000];
	int arrayHea[100000];

	read(in, arrayMer);
	int i;

	for (i = 0; i < maxlines; ++i) {
		arraySel[i] = arrayMer[i];
		arrayQui[i] = arrayMer[i];
		arrayHea[i] = arrayMer[i];
	}

	if (maxlines < 11) {
		for (i = 0; i < maxlines; ++i) {
			printf("%d", arrayMer[i]);
		}
		printf("\n");
	}

	printf("\nMergeSort:\n");

    LARGE_INTEGER frequency;        // ticks per second
    LARGE_INTEGER t1, t2;           // ticks
    double elapsedTime;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&t1);
	mergeSort(arrayMer, maxlines);
    QueryPerformanceCounter(&t2);
    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    if (maxlines < 11) {
		for (i = 0; i < maxlines; ++i) {
			printf("%d\n", arrayMer[i]);
		}
    }
	printf("\nDauer: %lf\n",elapsedTime);

	printf("\nSelectionSort:\n");

    QueryPerformanceCounter(&t1);
	selectionSort(arraySel);
    QueryPerformanceCounter(&t2);

    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    if (maxlines < 11) {
		for (i = 0; i < maxlines; ++i) {
			printf("%d\n", arraySel[i]);
		}
    }
	printf("\nDauer: %lf\n",elapsedTime);

	printf("\nQuickSort:\n");

    QueryPerformanceCounter(&t1);
	quicksort(arrayQui, 0, maxlines-1);
    QueryPerformanceCounter(&t2);

    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    if (maxlines < 11) {
		for (i = 0; i < maxlines; ++i) {
			printf("%d\n", arrayQui[i]);
		}
    }
	printf("\nDauer: %lf\n",elapsedTime);

	printf("\nHeapSort:\n");

    QueryPerformanceCounter(&t1);
	heapsort(arrayHea);
    QueryPerformanceCounter(&t2);

    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    if (maxlines < 11) {
		for (i = 0; i < maxlines; ++i) {
			printf("%d\n", arrayHea[i]);
		}
    }
    printf("\n");
	printf("\nDauer: %lf\n",elapsedTime);

	return(0);
}

void read(FILE *in, int *array){
	int i;
	maxlines = 0;
	for (i = 0; !feof(in); ++i) {
		fscanf(in, "%d\n", &array[i]);
		maxlines++;
	}
}
