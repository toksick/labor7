#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "heapsort.h"
#include "sorting.h"

void bubble_up(int node, int *heap){
	if (node == 0) {
		return;
	}
	int temp;
	int parent = (node-1)/2;
	if (heap[node] > heap[parent]) {
		temp = heap[node];
		heap[node] = heap[parent];
		heap[parent] = temp;
		bubble_up (parent, heap);
	}
}
void bubble_down(int node, int *heap, int end){

	int lChild = (2*node); lChild++;


	int temp;
	if (lChild < end) {
		int child = lChild;
		int rChild = lChild + 1;

		if (rChild < end) {
			if (heap[rChild] > heap[lChild]) {
				child = rChild;
			}
		}
		if (heap[child] > heap[node]) {
			temp = heap[child];
			heap[child] = heap[node];
			heap[node] = temp;
			bubble_down(child, heap, end);
		}
	}
}

void heapify(int *heap){
	int last = (maxlines - 1)/2;
	int i;
	for (i = last; i >= 0; --i) {
		bubble_down(i, heap, maxlines-1);
	}
}

void heapsort(int *heap){
	heapify(heap);
	int temp;
	int i;
	for (i = maxlines-1; i >= 0; --i) {
		temp = heap[i];
		heap[i] = heap[0];
		heap[0] = temp;
		bubble_down(0, heap, i);
	}

}
