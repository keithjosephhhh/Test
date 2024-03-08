#include<iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high){
    int h = low;
    int i = low; 
    int j = mid+1;
    int b[high-low+1];

    while(h<=mid && j<=high){
        if(arr[h]<=arr[j]){
            b[i-low] = arr[h];
            h++;
        }
        else{
            b[i-low] = arr[j];
            j++;
        }
        i++;
    }

    if(h>mid){
        for(int k=j; k<=high; k++){
            b[i-low] = arr[k];
            i++;
        }
    }
    else{
        for(int k = h; k<=mid; k++){
            b[i-low] = arr[k];
            i++;
        }
    }
    for(int k = low; k<=high; k++){
        arr[k] = b[k-low];
    }

}

void MergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1, high);
        Merge(arr,low,mid,high);
    }
}
 
int main(){
    int a[8] = {52,5,21,4,12,3,10,3};
    MergeSort(a,0,7);

    for(int i=0; i<8; i++)
        cout<<a[i]<<" ";
    return 0;
}