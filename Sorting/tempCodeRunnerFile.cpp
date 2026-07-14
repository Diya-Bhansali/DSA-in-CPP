/*Merge Sorting

Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. 
Return the sorted array.
*/
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int low,int mid,int high){
    int left=low;
    int right=mid+