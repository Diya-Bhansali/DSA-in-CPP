/*Bubble Sort

Given an array of integers called nums,sort the array in non-decreasing order 
using the bubble sort algorithm and return the sorted array.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        int swap_count=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
                swap_count=1;
            }
        }
        if(swap_count==0)
        break;
    }
    cout<<"After sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return(0);
}