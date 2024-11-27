#include<iostream>
using namespace std;


void merge(int arr[],int start, int mid, int end){
    int temp[end-start +1];
    int left = start;   // starting index of left subarray
    int right = mid+1;  // starting index of right subarray
    int k = 0;          // starting index of temporary array


    while(left<=mid && right<=end){
        if(arr[left]<=arr[right]){
            temp[k] = arr[left];
            left++;
        } else{
            temp[k] = arr[right];
            right++;
        }
        k++;
    }

    while(left<=mid){
        temp[k] = arr[left];
        left++;
        k++;
    }

    while(right<=end){
        temp[k] = arr[right];
        right++;
        k++;
    }

    for(int t=0;t<k; t++){
        arr[start + t] = temp[t];
    }


}

void mergeSort(int arr[], int start, int end){
    if (start < end){
        int mid = ( start + end)/2;
        mergeSort(arr,start, mid);  // left part
        mergeSort(arr,mid+1, end);  // right part
        merge(arr,start,mid,end);  // for merging
    }
}


int main(){
    int n;
    cout<<"Enter number of students : ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter Roll numbers to be Sorted : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Before Sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    mergeSort(arr,0,n-1);

    cout<<"After Sorting: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}