#include<iostream>
using namespace std;
 
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void QuickSort(int arr[], int low, int high){
    if(low<high){
        int part = partition(arr, low, high);
        QuickSort(arr, low, part-1);
        QuickSort(arr,part+1, high);
    }
}

int main(){
    int a[8] = {52,5,21,4,12,3,10,3};
    QuickSort(a,0,7);

    for(int i=0; i<8; i++)
        cout<<a[i]<<" ";
    return 0;
}