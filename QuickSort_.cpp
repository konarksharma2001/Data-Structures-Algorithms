#include<iostream>
using namespace std;

int partition(int arr[], int s , int e)
{
    int pivot = arr[s];
    int count = 0;

    for(int i = s+1;i<=e;i++)
   {
       if(arr[i] < pivot)
       {
           count++;
       }
   }
   
   // Place Pivot Element at right position
   int pivotIndex = s + count;
   swap(arr[pivotIndex],arr[s]);

   // Left aur right wala part smbhal lete h
   int i = s,j = e;
   while(i < pivotIndex && j > pivotIndex)
   {
       while(arr[i] < pivotIndex) {i++;}
       while(arr[j] > pivotIndex) {j--;}

   if(i < pivotIndex && j > pivotIndex)
       {
       swap(arr[i++],arr[j--] );
       }
    }   
   return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // Base Case 
    if(s >= e) return;

    // Partioning Karenge
    int p = partition(arr,s,e);

    //  left wala part sort karo
    quickSort(arr,s,p-1);

    // right wala part sort karo
    quickSort(arr,p+1,e);
}

int main() {

    int arr[10] = {2,4,1,86,9 ,9,9,10,11,18};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}