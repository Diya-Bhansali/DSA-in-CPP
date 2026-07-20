/*Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. 
The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

For brute force approach,Time complexity- o(n1 logn + n2 logn)+ o(n1+n2) & Space complexity -o(n1+n2)+ o(n1+n2)
note: here in space complexity another O(n1+n2) is for returning array.

For optimal approach,using 2 pointer method,Time complexity- O(n1+n2) & Space complexity-O(n1+n2) 
note here also all space complexity is considered for returning array only.
*/
/*Given an array of integers nums and an integer target, find the smallest index (0 based indexing) where the target appears in the array. 
If the target is not found in the array, return -1*/
#include<bits/stdc++.h>
using namespace std;
vector<int> brute(vector<int>& num1,vector<int>& num2,int n1,int n2){
    set<int> st;
    vector<int> union_array;
    for(int i=0;i<n1;i++){
        st.insert(num1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(num2[i]);
    }
    for(auto it:st){
        union_array.push_back(it);
    }
    return(union_array);
}
vector<int> optimal(vector<int>& num1,vector<int>& num2,int n1,int n2){
    int i=0,j=0;
    vector<int> Union;
    while(i<n1 && j<n2){
        if(num1[i]<num2[j]){
            if(Union.empty() || Union.back()!=num1[i])
                Union.push_back(num1[i]);
            i++;
        }
        else if(num2[j]<num1[i]){
            if(Union.empty() || Union.back()!=num2[j])
                Union.push_back(num2[j]);
            j++;
        }
        else{
            if(Union.empty() || Union.back()!=num1[i])
                Union.push_back(num1[i]);
            j++; i++;
        }
    }
    while(i<n1){
        if(Union.empty() || Union.back()!=num1[i])
            Union.push_back(num1[i]);
        i++;
    }
    while(j<n2){
        if(Union.empty() || Union.back()!=num2[j])
            Union.push_back(num2[j]);
        j++;
    }
    return(Union);
}
int main(){
    int n1,n2;
    cout<<"Enter the number of elements of 1st Array:";
    cin>>n1;
    vector<int> num1(n1);
    cout<<"Enter the elements:";
    for(int i=0;i<n1;i++){
        cin>>num1[i];
    }
    cout<<"Enter the number of elements of 2nd Array:";
    cin>>n2;
    vector<int> num2(n2);
    cout<<"Enter the elements:";
    for(int i=0;i<n2;i++){
        cin>>num2[i];
    }
    vector<int> union_array=optimal(num1,num2,n1,n2);
    cout<<"The union of given arrays is ";
    for(int i=0;i<union_array.size();i++){
        cout<<union_array[i]<<" ";
    }
}