#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int low,int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j)
    {
        while(i <= high - 1 && arr[i] <= pivot)
            i++;
        while(j >= low + 1 && arr[j] > pivot)
            j--;
        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int>& arr,int low,int high)
{
    if(low < high)
    {
        int part = partition(arr,low,high);
        qs(arr,low,part-1);
        qs(arr,part+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    qs(arr,0,n-1);
    cout<<"After sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

