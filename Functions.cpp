using namespace std;
#include <iostream>
#include <limits>
#include "Functions.h"
#include <cstdio>
#include <ctime>
#include <chrono>

void insertionSort(int* arr,int size)
{
	int key;
	int j;
	for (int i=1;i<size;i++)
	{
		key=arr[i];
		 j=i-1;
		while(j>=0&&arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}

}
/////////////////////////////////////////////////////
////////////////////////////////////////////////////
int partition(int *arr, int p, int r)
{
	int key;
	key = arr[r];
	int i = p - 1;
	int temp;

	for (int j = p; r - 1; j++)
	{
		if (arr[j] <= key)
		{
			i = i + 1;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;

		}
	}

	temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;
	return(i + 1);
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////


void quickSort(int*arr, int p, int r)
{

	if (p < r)
	{
		int part;
		part = partition(arr, p, r);
		quickSort(arr, p, part - 1);
		quickSort(arr, part + 1, r);
	}
}

/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int min(int *x, int size, int &index)
{
	int min = x[0];
	for (int i = 0; i < size; i++)
	{
		if (x[i] < min)
		{
			min = x[i];
			index = i;

		}
	}
	return min;
}
void selectionSort(int* arr,int size)
{ 
	int indexOfMin=0;
		
	
	for(int i=0;i<size;i++)
	{ 
		int v = 0;
		int *subarr= new int[size-i];
		for (int j=i; i < size; i++)
		{
			subarr[v] = arr[j];
		}
		int temp=arr[i];
		arr[i]=min(subarr,size-i,indexOfMin);
		arr[indexOfMin]=temp;
	}

}
//////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void merge(int* arr, int p, int q, int r)
{
	int arr1 = q - p + 1;
	int arr2 = r - q;
	int * l  = new int[arr1];
	int * R = new int[arr2];

	for (int i = 0; i < arr1; i++)
	{
		l[i] = arr[p + i];
	}
	for (int j = 0; j < arr2; j++)
	{
		R[j] = arr[q + j];
	}

	l[arr1] = std::numeric_limits<int>::max();
	R[arr2] = std::numeric_limits<int>::max();
	int i = 0;
	int j = 0;

	for (int x = p; p < r; x++)
	{
		if (l[i] < R[j])
		{
			arr[x] = l[i];
			i = i + 1;
		}
		else
		{
			arr[x] = R[j];
			j = j + 1;
		}
	}

}
void mergeSort(int* arr,int p,int r)
{   int q;

	

	if(p<r)
	{
     q=(p+r)/2;
     mergeSort(arr,p,q);
     mergeSort(arr,q+1,r);
	 merge(arr, p, q, r);
	}

}

///////////////////////////////////////////////////
//////////////////////////////////////////////////

void hybirdSort()
{

}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
float sortmain(int* arr,int size,int id)
{
	 std::clock_t start;
    float duration;
	auto start_time = std::chrono::high_resolution_clock::now();

	// if id =0 Selection sort
if(id=0){ 
	start = std::clock();

     selectionSort(arr,size);
 }
	// if id=1 -> insertion sort
	else if (id=1){
		insertionSort(arr,size);

	}
		//if id=2-> merge sort
		else if (id=2){
			mergeSort(arr,0,size-1);
		}
			// if id =3 -> quick sort
			else if (id=3){
				
				quickSort(arr,0,size-1);
			}
				//if id=4 -> hybird sort
				else {
				
				}
auto end_time = std::chrono::high_resolution_clock::now();
auto time = end_time - start_time;
duration=(std::chrono::duration_cast<std::chrono::milliseconds>(time).count());
// duration = std::clock() - start / (double)CLOCKS_PER_SEC;
     return duration;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////