#include<iostream>
using namespace std;

void merge(int* arr, int s, int e){
    
    int mid = s + (e-s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // Dynamically creating 2 arrays
    int* first = new int[len1];
    int* second = new int[len2];

    // Copying values in both
    int k = s;
    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    
    k = mid + 1;
    for(int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // Merge 2 Arrays
    int index1 = 0;
    int index2 = 0;
    k = s;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1]< second[index2]){
            arr[k++] = first[index1++];
        }
        else{
            arr[k++] = second[index2++];
        }
    }

    while(index1 < len1){
        arr[k++] = first[index1++];
    }

     while(index2 < len2){
        arr[k++] = second[index2++];
    }

    // Free up dynamically alloted memory
    delete []first;
    delete []second;
}



void mergeSort(int* arr , int s, int e)
{
    // Base Case
    if(s >= e){        
       return;
       }

    int mid = s + (e-s)/2;
 
    // Left Part Merge karna hai
    mergeSort(arr,s,mid);

   // Right Part Merge karna hai
    mergeSort(arr,mid+1,e);

    // Merge Both parts
    merge(arr,s,e);
}

int main() {

    int arr[7] = {38,27,43,3,9,82,10};
    int n = 7;

    mergeSort(arr, 0, n-1);

    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    } cout << endl;
    cout<<endl<<endl;

    return 0;
}