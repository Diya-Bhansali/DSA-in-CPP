/*Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.
This must be done in place, without making a copy of the array.

For Brute force, Time Complexity- O(2N) and extra space is O(N)
For Optimal Approach,Time complexity- O(N) and no extra space is used- O(1`)*/
#include<bits/stdc++.h>
using namespace std;
void brute(vector<int>& nums,int n){
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    int s=temp.size();
    for(int i=0;i<s;i++){
        nums[i]=temp[i];
    }
    for(int i=s;i<n;i++){
        nums[i]=0;
    }
}
void optimal(vector<int>& nums,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[j],nums[i]);
            j++;
        }
    }
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
    optimal(nums,n);
    cout<<"Answer:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}