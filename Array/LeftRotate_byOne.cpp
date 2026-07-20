/*Given an integer array nums, rotate the array to the left by one.
Note: There is no need to return anything, just modify the given array

Here exactly left rotate means the first element goes to last and all others move one step to the left.

time complexity- O(N) & Space Complexity-O(1)
Note: There is difference in space complexity used in algoritm .i.e O(n) here.
while space complexity for extra space in program is O(1).
*/
#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int>& nums,int n){
    int temp=nums[0];
    for(int i=1;i<n;i++){
       nums[i-1]=nums[i];
    }
    nums[n-1]=temp;
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
    rotate(nums,n);
    cout<<"Ater left rotation by one:";
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}