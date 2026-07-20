/*Given an array of integers nums, return the second-largest element in the array. 
If the second-largest element does not exist, return -1.

For Brute Force: Time Complexity- O(N logN + N)
For Better Solution: Time Complexity- O(N + N)=O(2N)
For Optimal Approach: Time Complexity- O(N)
*/
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums,int n){
    sort(nums.begin(),nums.end());
    for(int i=n-2;i>=0;i--){
        if(nums[i]!=nums[n-1])
        return(nums[i]);
    }
    return(-1);
}
int better(vector<int>& nums,int n){
    int largest=nums[0];
    int slargest=INT_MIN;
    for(int i=1;i<n;i++){
        if(nums[i]>largest)
        largest=nums[i];
    }
    for(int i=0;i<n;i++){
        if(nums[i]>slargest && nums[i]!=largest)
        slargest=nums[i];
    }
    if(slargest==INT_MIN){
        return(-1);
    }
    return(slargest);
}
int optimal(vector<int>& nums,int n){
    int largest=nums[0];
    int slargest=INT_MIN;
    for(int i=1;i<n;i++){
        if(nums[i]>largest){
            slargest=largest;
            largest=nums[i];
        }
        else if(nums[i]>slargest && nums[i]!=largest){
            slargest=nums[i];
        }
    }
    if(slargest==INT_MIN){
        return(-1);
    }
    return(slargest);
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
    vector<int> temp=nums;
    int sol1=brute(temp,n);
    int sol2=better(nums,n);
    int sol3=optimal(nums,n);
    cout<<"Using Brute Force:\nSecond Largest element is "<<sol1<<"\nUsing Better Approach:\nSecond Largest element is "<<sol2<<"\nUsing Optimised Approach:\nSecond Largest element is "<<sol3<<endl;
}