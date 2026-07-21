/*Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), 
return the only number missing from the array within this range.

For Brute force solution, Time complexity is O(n*n) and space complexity is O(1)
For Better solution, use Hashing , time complexity is O(2n) and space complexity isO(n)
For Optimal solution, use summation - sum of given numbers, Time complexity is O(n) and space complexity is O(1)
there is again a more optimal solution, using X0R, Time complexity is O(n) and space complexity is O(1)
XOR is more better because here the size will not go beyond n while in sum it may go high.
*/
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums,int n){
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(nums[j]==i){
                flag=1;
            }
        }
        if(flag==0)
            return(i);
    }
    return(-1);
}
int better(vector<int>& nums,int n){
    vector<int> hash(n+1,0);
    for(int i=0;i<n-1;i++){
        hash[nums[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0){
            return(i);
        }
    }
    return(-1);
}
int optimal_sum(vector<int>& nums,int n){
    int sum=(n*(n+1))/2;
    int sum_arr=0;
    for(int i=0;i<n-1;i++){
        sum_arr+=nums[i];
    }
    return(sum-sum_arr);
}
int optimal_XOR(vector<int>& nums,int n){
    int xor1=0,xor2=0;
    for(int i=0;i<n-1;i++){
        xor1^=(i+1);
        xor2^=nums[i];
    }
    xor1^=n;
    return(xor1^xor2);
}
int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    vector<int> nums(n-1);
    cout<<"Enter the elements:";
    for(int i=0;i<n-1;i++){
        cin>>nums[i];
    }
    cout<<"Missing Number is:"<<optimal_XOR(nums,n);
}
