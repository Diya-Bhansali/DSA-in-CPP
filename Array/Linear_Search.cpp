/*Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. 
If the target is not found in the array, return -1*/
#include<bits/stdc++.h>
using namespace std;
int linear(vector<int>& nums,int n,int t){
    for(int i=0;i<n;i++){
        if(nums[i]==t){
            return(i);
        }
    }
    return(-1);
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
    int target;
    cout<<"Enter the target:";
    cin>>target;
    int l=linear(nums,n,target);
    if(l==-1){
        cout<<"Target not found!!";
    }
    else{
        cout<<"Target found at "<<l+1;
    }
    
}