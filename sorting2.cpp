#include <iostream>
using namespace std;

//MERGE SORT: Divide, Conquer & Merge
//Divide array into 2 sub-parts and do the same for these sub-parts. 
//Sort (until 1 element in each sub-part: sub-part can no longer be divided) and then merge back 
//into the sorted array. It is faster and more stable than selection/bubble/insertion sorts.

//TC: O(nlogn); SC: O(n)
//requires additional memory for temporary sub-arrays. Therefore, it is not in-place sorting.

//APPROACH 1

void merge(int *arr, int s, int e) {
    int dupe = s;
    int mid = s + (e - s)/2;
    int len_left = mid - s + 1;
    int len_right = e - mid;

    int *left = new int[len_left];
    int *right = new int[len_right];

    int k = s, l = mid + 1;
    for(int i = 0; i<len_left; ++i) {
        left[i] = arr[k++];
    }
    for(int i = 0; i<len_right; ++i) {
        right[i] = arr[l++];
    }

    int index_left = 0, index_right = 0;

    while (index_left<len_left && index_right<len_right) {
        if (left[index_left] < right[index_right])
            arr[dupe++] = left[index_left++];
        else 
            arr[dupe++] = right[index_right++];
    }

    while (index_left<len_left) {
        arr[dupe++] = left[index_left++];
    }
    while (index_right<len_right) {
        arr[dupe++] = right[index_right++];
    }

    delete []left;
    delete []right;
}

void mergeSort(int *arr, int s, int e) {
    int mid = s + (e - s)/2;
    if (s>=e)
        return;
    
    mergeSort(arr, s, mid);       // sort Left sub-array
    mergeSort(arr, mid + 1, e);   // sort Right sub-array

    merge(arr, s ,e);
}

int main() {

    int n;
    cin>>n;
    int *arr = new int[n];

    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    cout<<"Sorting inputted Array using MERGE sort: "<<endl;
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete []arr;

    return 0;
}