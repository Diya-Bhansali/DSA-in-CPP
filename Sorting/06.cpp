/*Recursive Bubble Sort

Given an array of integers nums, sort the array in non-decreasing order 
using the recursive Bubble Sort algorithm, and return the sorted array.
You must implement Bubble Sort using recursion only.
Do not use built-in sorting functions (sort, sorted, Arrays.sort, etc.).
A sorted array in non-decreasing order is an array where each element is greater than or equal to the previous one.
*/
#include<bits/stdc++.h>
using namespace std;
void bs(vector<int>& nums,int n){
    if(n==1) return;
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            int t=nums[i];
            nums[i]=nums[i+1];
            nums[i+1]=t;
        }
    }
    bs(nums,n-1);
}
int main(){
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    bs(nums,n);
    cout<<"After Sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}

