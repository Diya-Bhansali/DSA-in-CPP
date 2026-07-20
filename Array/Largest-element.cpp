/*Given an array of integers nums, return the value of the largest element in the array

For Brute force we can use sorting and the last element is the largest element. So here, 
Time Complexity is O(N logN) and Space Complexity is O(1) 

Now considering optimal solution- Time Complexity is O(N)
*/
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums,int n){
    sort(nums.begin(),nums.end());
    return(nums[n-1]);
}
int optimal(vector<int>& nums,int n){
    int largest=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]>largest)
        largest=nums[i];
    }
    return(largest);
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
    int sol1=brute(nums,n);
    int sol2=optimal(nums,n);
    cout<<"Using Brute Force:\nLargest element is "<<sol1<<"\nUsing Optimised Approach:\nLargest element is "<<sol2<<endl;
}