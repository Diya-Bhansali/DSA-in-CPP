/*Given an array of nums of n integers. Every integer in the array appears twice except one integer. 
Find the number that appeared once in the array.

For Brute force approach, Time complexity is O(n*n) & Space complexity is O(1).

For Better solution use hashing,for hash array size is maximum & Time complexity is O(3n) and Space Complexity is O(maxElement+1)

For optimised approach using xor,Time complexity is O(n) and space complexity is O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums,int n){
    for(int i=0;i<n;i++){
        int cnt=0,num=nums[i];
        for(int j=0;j<n;j++){
            if(nums[j]==num){
                cnt++;
            }
        }
        if(cnt==1) return(num);
    }
    return(-1);
}
int better(vector<int>& nums,int n){
    int maxi=nums[0];
    for(int i=1;i<n;i++){
        maxi=max(maxi,nums[i]);
    }
    vector<int> hash(maxi+1,0);
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    for(int i=0;i<n;i++){
        if(hash[nums[i]]==1) return(nums[i]);
    }
    return(-1);
}
int optimal(vector<int>& nums,int n){
    int xor1=0;
    for(int i=0;i<n;i++){
        xor1^=nums[i];
    }
    return(xor1);
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
    cout<<"Answer:"<<optimal(nums,n);
}