/*Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.

Time Complexity- O(N)
*/
#include<bits/stdc++.h>
using namespace std;
bool check_sorted_array(vector<int>& nums,int n){
    for(int i=1;i<n;i++){
        if(nums[i]<nums[i-1])
        return(false);
    }
    return(true);
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
    int check=check_sorted_array(nums,n);
    if(check){
        cout<<"The Array is Sorted."<<endl;
    }
    else{
        cout<<"The Array is not Sorted."<<endl;
    }
}