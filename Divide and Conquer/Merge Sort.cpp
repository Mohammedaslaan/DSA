#include <bits/stdc++.h>
using namespace std;

void merge(int* arr, int s , int e){
    int mid = s + (e-s)/2;
    //creating left and right arrays.
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;
    int* left = new int[lenLeft];
    int* right = new int[lenRight];
    // copying left and right arrays.
    int k = s;
    for(int i = 0 ; i <lenLeft ; i++){
        left[i] = arr[k];
        k++;
    }
    k = mid+1;
    int rightarr[e-mid] = {0};
    for(int i = 0 ; i<lenRight ; i++){
        right[i] = arr[k];
        k++;
    }
    //now merge these two sorted arrays.
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;
    while(leftIndex < lenLeft && rightIndex < lenRight){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] =  left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    while(leftIndex < lenLeft){
        arr[mainArrayIndex] =  left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    while(rightIndex < lenRight){
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    delete left,right;




}
void mergeSort(int* arr,int s,int e){
    if(s >= e){
        return; // single Element.
    }

    int mid = s + (e-s) / 2;
    //recursion left part sort kr dega
    mergeSort(arr,s,mid);
    //recursion right part sort kr dega
    mergeSort(arr,mid+1,e);
    //now merge two sorted arrays.
    merge(arr,s,e);
}
int main(){
    int arr[] = {4,5,13,2,13,2,12};
    int n = 7;
    int s = 0;
    int e = n -1;
    mergeSort(arr,s,e);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}