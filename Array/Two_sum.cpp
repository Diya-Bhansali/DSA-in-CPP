/*Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.
Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in any order.

Brute force approach:Time complexity is O(n*n) and Space complexity is O(1).
Optimal approach:using hashing,Time complexity is O(n*logn) for ordered map and for unordered map you know the case.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int>& nums,int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==k) 
            return {i, j};
        }
    }
    return {-1, -1};
}
vector<int> optimal(vector<int>& nums,int n,int k){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a=nums[i];
        int more=k-a;
        if(mpp.find(more)!=mpp.end()) return {mpp[more], i};
        mpp[a]=i;
    }
    return {-1, -1};
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
    int k;
    cout<<"Enter the target element:";
    cin>>k;
    vector<int> ans = optimal(nums,n,k);
    cout<<"Answer:"<<ans[0]<<" "<<ans[1];
}