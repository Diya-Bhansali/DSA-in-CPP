/*Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.

For Brute force approach,Time complexity is O(N+K) & extra space-O(K)
For optimised approach,Time complexity is O(2N) & there no extra space is required-O(1)
*/
#include<bits/stdc++.h>
using namespace std;
void brute(vector<int>& nums,int n,int k){
    k=k%n;
    vector<int> temp;
    for(int i=0;i<k;i++){
        temp.push_back(nums[i]);
    }
    for(int i=k;i<n;i++){
        nums[i-k]=nums[i];
    }
    int j=0;
    for(int i=n-k;i<n;i++){
        nums[i]=temp[j++];
    }
}
void reverse(vector<int>& nums,int start,int end){
    while(start<=end){
        int temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
}
void optimal(vector<int>& nums,int n,int k){
    k=k%n;
    reverse(nums,0,k-1);
    reverse(nums,k,n-1);
    reverse(nums,0,n-1);
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
    int k;
    cout<<"Enter value of K:";
    cin>>k;
    optimal(nums,n,k);
    cout<<"Ater left rotation by K:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}