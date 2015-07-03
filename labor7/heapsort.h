/*
 * heapsort.h
 *
 *  Created on: 01.07.2015
 *      Author: Alex
 */

void bubble_up(int node, int *heap);
void bubble_down(int node, int *heap, int end);
void heapify(int *heap);
void heapsort(int *heap);

