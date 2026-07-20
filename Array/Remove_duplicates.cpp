/*Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.
Return the number of unique elements in the array.
If the number of unique elements be k, then,
Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
The remaining elements, as well as the size of the array does not matter in terms of correctness.
The driver code will assess correctness by printing and checking only the first k elements of the modified array.
An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.

For Brute force,We can consider sets as it doesn't store duplicates. Here, Time complexity- O(N log(N)+ N) & Space Complexity- O(N)

For Optimal Approach,we can use something like 2 pointer,Time Complexity- O(N) & Space Complexity-O(1)
*/
#include<bits/stdc++.h>
using namespace std;
int brute(vector<int>& nums,int n){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(nums[i]);
    }
    int index=0;
    for(auto it:st){
        nums[index]=it;
        index++;
    }
    return(index);
}
int optimal(vector<int>& nums,int n){
    int j=0;
    for(int i=1;i<n;i++){
        if(nums[i]!=nums[j]){
            j++;
            nums[j]=nums[i];
        }
    }
    return(j+1);
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
    vector<int> nums1 = nums;
    vector<int> nums2 = nums;
    int sol1=brute(nums1,n);
    int sol2=optimal(nums2,n);
    cout<<"Using Brute Force:\nAnswer = "<<sol1<<"\nUsing Optimised Approach:\nAnswer = "<<sol2<<endl;
}