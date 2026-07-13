/* Counting Frequencies of Array Elements

Given an array nums of size n which may contain duplicate elements.
Return a list of pairs where each pair contains a unique element from the array and its frequency in the array.
You may return the result in any order, but each element must appear exactly once in the output.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of values(n) to be enterd:\n";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter elements:"<<"\n";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    } 
    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<"\n";
    }
    return(0);
}