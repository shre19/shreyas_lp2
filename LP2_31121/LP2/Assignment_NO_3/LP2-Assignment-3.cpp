#include <bits/stdc++.h>
#define pb push_back
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

vector<int> selectionSort(vector<int> &arr, int n){  // 8 7 6 5 4 3 2 1
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
    return arr;
}

int main(){
    vector<int> arr;
    int n;
    cout << "Enter size of Array = "; 
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        arr.pb(val);
    }
    vector<int> ans;
    ans = selectionSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}