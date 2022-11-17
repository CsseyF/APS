#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge(char arr[7][20], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
// Create temp arrays
char L[n1][20], R[n2][20];
// Copy data to temp array
for (i = 0; i < n1; i++){
    strcpy(L[i],malloc(sizeof(arr[l+i])));
    strcpy(L[i], arr[l + i]);
}
for (j = 0; j < n2; j++){
    strcpy(R[i],malloc(sizeof(arr[m+i+1])));
    strcpy(R[j], arr[m + 1+ j]);
}
// Merge the temp arrays
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (strcmp(L[i],R[j])<0)
{
strcpy(arr[k++],L[i++]);
}
else
{
strcpy(arr[k++],R[j++]);
}
}
// Copy the remaining elements of L[]
while (i < n1)
{
strcpy(arr[k++],L[i++]);
}
// Copy the remaining elements of R[]
while (j < n2)
{
strcpy(arr[k++],R[j++]);
}
}


void mergeSort(char arr[7][20], int l, int r)
{
if (l < r)
{
// Finding mid element
int m = (l+r)/2;
// Recursively sorting both the halves
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
 
// Merge the array
merge(arr, l, m, r);
}
}

void printArray(char A[7][20], int size)
{
int i;
for (i=0; i < size; i++)
printf("%s ", A[i]);
printf("\n");
}

int main()
{
char arr[7][20] = {"Casey", "Leonardo", "Gustavo", "Lucas", "Nicolas", "Rodrigo", "Douglas"};
int arr_size = sizeof(arr)/sizeof(arr[0]);

printf("Given array is \n");
printArray(arr, arr_size);
mergeSort(arr, 0, arr_size - 1);
printf("\nSorted array is \n");
printArray(arr, arr_size);
return 0;
}