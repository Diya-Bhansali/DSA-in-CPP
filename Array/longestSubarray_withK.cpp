/*Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. 
If no such sub-array exists, return 0.

for positive:
Brute Force Solution:Time complexity is nearly O(n*n*n) or O(n*n) if improvised by understanding summation pattern
Better Solution: using hashing, Time complexity is O(n*log n) for ordered map and 
time complexity for unordered map is O(n*n) and Space Complexity is O(n)
Optimal Approach:Two pointer approach,Time complexity is O(2n) and Space complexity is O(1)

For negative:
the better solution is the most optimised soltion
*/

#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums,int n,int k){
    int len=0;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=i;j<n;j++){
            s+=nums[j];
            if(s==k) len=max(len,j-i+1);
        }
    }
    return(len);
}
int better(vector<int>& nums,int n,int k){
    map<int, int> preSumMap;
    int sum=0,maxLen=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum==k)  maxLen=max(maxLen,i+1);
        if(preSumMap.find(sum-k)!=preSumMap.end()){
            int len=i-preSumMap[sum-k];
            maxLen=max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end())
        preSumMap[sum]=i;
    }
    return(maxLen);
}
int optimal(vector<int>&nums,int n,int k){
    int left=0,right=0,sum=nums[0],len=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=nums[left];
            left++;
        }
        if(sum==k)  len=max(len,right-left+1);
        right++;
        if(right<n) sum+=nums[right];
    }
    return(len);
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
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Answer:"<<optimal(nums,n,k);
}