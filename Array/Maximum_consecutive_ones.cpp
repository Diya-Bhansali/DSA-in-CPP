/*Given a binary array nums, return the maximum number of consecutive 1s in the array.
A binary array is an array that contains only 0s and 1s.

Time complexity is O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int maximum_1(vector<int>& nums,int n){
    int maxi=0,cnt=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else
        cnt=0;
    }
    return(maxi);
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
    cout<<"Maximum consecutive ones:"<<maximum_1(nums,n);
}
