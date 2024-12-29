#include <iostream>
using namespace std;

//MERGE SORT: Divide, Conquer & Merge
//Divide array into 2 sub-parts and do the same for these sub-parts. 
//Sort (until 1 element in each sub-part: sub-part can no longer be divided) and then merge back 
//into the sorted array. It is faster and more stable than selection/bubble/insertion sorts.

//TC: O(nlogn); SC: O(n)
//requires additional memory for temporary sub-arrays. Therefore, it is not in-place sorting.
//It is stable.

//APPLICATION: external sorting, sorting linked lists.

//DRAWBACKS: slower compared to other algos for smaller tasks; extra O(n) memory for temporary arrays;
//           goes through whole process even if array is sorted

//APPROACH 1: by creating 2 separate arrays and merging
//APPROACH 2: directly using indices

void merge(int *arr, int s, int e) {
    int dupe = s;
    int mid = s + (e - s)/2;
    int len_left = mid - s + 1;
    int len_right = e - mid;


    //dividing arr into 2 parts
    int *left = new int[len_left];
    int *right = new int[len_right];

    int k = s, l = mid + 1;
    for(int i = 0; i<len_left; ++i) {
        left[i] = arr[k++];
    }
    for(int i = 0; i<len_right; ++i) {
        right[i] = arr[l++];
    }


    //merging 2 sorted arrays
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



//QUICK SORT: Recursive Partition
//We take an element x and place it in the array in such a way that the sub-array on left of x contains 
//elements which are < x and right sub-array contains elements > x. Thus x works as a partition.
//Let this position of element xx be p. then we need to repeat the process for sub-arrays :
//(s, p - 1) & (p + 1, e)

//to get the pivort position of x, we count the number of elements < x. the index of x would does be that
//number from s (s + count_less_than_x)
//we then traverse through array and swap remaining elements based upon > x or < x and then call fn again 
//for resulting sub-arrays.

//TC: O(nlogn), Worst Case: O(n²); SC: O(logn) (avg.)
//It is in-place sorting.
//It is 'Tail Recursive'.
//It is not stable,

//QS is preferred over MS for arrays due to SC and no allocation or deallocation
//MS is preferred over QS for linked lists as for LL we can insert items in O(1) extra space unlike 
//for arrays. Moreover arrays have random acces which isused by QS but LL does not: we have to travel 
//through each and every node. Therefore, there is more overhead for QS. MS accesses data sequentially 
//which is standard for LL.


int partition(int *arr, int s, int e) {
    //let pivot be the rightmost element
    int pivot = arr[s];
    int count_less_than_pivot = 0;

    for (int i = s + 1; i <= e; ++i) {
        if (arr[i] <= pivot)     count_less_than_pivot++;
    }

    //correct position of pivot element
    int pivot_index = s + count_less_than_pivot;
    swap(arr[s], arr[pivot_index]);

    //checking for remaining elements
    int i = s, j = e;
    while (i < pivot_index && j > pivot_index) {
        while (arr[i] <= pivot)     i++;
        while (arr[j] > pivot)     j--;

        //we have indices i and j forwhich the elements are incorrectly placed so we simply swap them
        //not concerned for if the sub-arrays are sorted, it will be handled thrpugh recursion
        //only concern is clubbing elements > x or < x in their respecive sub-arrays.
        if (i < pivot_index && j > pivot_index)     swap(arr[i], arr[j]);
        i++;
        j--;
    }

    return pivot_index;
}

void quickSort(int *arr, int s, int e) {
    if (s >= e)     return;

    int pos = partition(arr, s, e);

    quickSort(arr, s, pos - 1);
    quickSort(arr, pos + 1, e);
}

int main() {

    int n;
    cin>>n;
    int *arr = new int[n];

    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    // cout<<"Sorting inputted Array using MERGE sort: "<<endl;
    // mergeSort(arr, 0, n - 1);

    cout<<"Sorting inputted Array using QUICK sort: "<<endl;
    quickSort(arr, 0, n - 1);

    for (int i = 0; i<n; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete []arr;

    return 0;
}