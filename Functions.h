using namespace std;
#include <iostream>
#include <limits>
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void insertionSort(int* arr,int size);

void quickSort(int*arr,int p,int r);

void selectionSort(int* arr,int size);

void mergeSort(int* arr,int p,int r);

float sortmain(int* arr,int size,int id);

int partition(int *arr, int p, int r);


#endif

