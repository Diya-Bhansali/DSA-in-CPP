/*Given an array nums consisting of only 0, 1, or 2. 
Sort the array in non-decreasing order.
The sorting must be done in-place, without making a copy of the original array.

For Brute force:Use merge sort,Time complexity is O(n*log n) & Space complexity of O(n)
For Better approach:Time complexity is O(2*n) & Space complexity of O(1)
For Optimal approach:Use three pointer,Time complexity is O(n) & Space complexity of O(1)
*/
#include<bits/stdc++.h>
using namespace std;
void better(vector<int>& nums,int n){
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==0) c0++;
        if(nums[i]==1) c1++;
        if(nums[i]==2) c2++;
    }
    for(int i=0;i<c0;i++){
        nums[i]=0;
    }
    for(int i=c0;i<c0+c1;i++){
        nums[i]=1;
    }
    for(int i=c0+c1;i<n;i++){
        nums[i]=2;
    }
}
void optimal(vector<int>& nums,int n){
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    optimal(nums,n);
    cout<<"After sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}