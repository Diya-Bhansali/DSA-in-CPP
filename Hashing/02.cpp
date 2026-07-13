/* Highest Occurring Element in an Array

Given an array nums of n integers, find the most frequent element in it 
i.e., the element that occurs the maximum number of times. 
If there are multiple elements that appear a maximum number of times, find the smallest of them.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the value of n:"<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    int max=0,ans;
    for(auto it:mpp){
        if(it.second>max){
            max=it.second;
            ans=it.first;
        }
        else if(it.second==max && it.first<ans){
            ans=it.first;
        }
    }
    cout<<"Most Frequent element is:"<<ans<<endl;
    return(0);
}