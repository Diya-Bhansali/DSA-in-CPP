/*Recursive Insertion Sort

Given an array of integers nums, sort the array in non-decreasing order 
using the recursive Insertion Sort algorithm, and return the sorted array.
You must implement Insertion Sort using recursion only.
Do not use loops (like for or while) or built-in sorting functions (sort, Arrays.sort, etc.).
A sorted array in non-decreasing order is an array where each element is greater than or equal to all elements that come before it.
*/
#include<bits/stdc++.h>
using namespace std;
void is(vector<int>& nums,int i,int n){
    if(i==n) return;
    for(int j=i;j>0;j--){
        if(nums[j-1]>nums[j]){
            swap(nums[j-1],nums[j]);
        }
    }
    is(nums,i+1,n);
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
    is(nums,0,n);
    cout<<"After Sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}
