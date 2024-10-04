#include <iostream>
using namespace std;

// define array
void MakeArr(int arr[], int size) {
     for (int i = 0; i < size; ++i) {
        int ele;
        cin>>ele;
        arr[i] = ele;
    }
}

// print array
void PrintArr(int arr[], int size) {
    cout<<"List elements are: ";
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main() {

    int n, temp;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array"<<endl;
    MakeArr(arr, n);

// SELECTION SORT - When size of array/vector is small - TC: O(n^2); SC: O(1) (assume input given)
// In Place Sorting: No additional space used (swapping)

/*    for (int i = 0; i<(n-1); ++i) {
        int min = i;
        for (int j = (i+1); j<(n); ++j) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        PrintArr(arr, n);
    }*/

// BUBBLE SORT - TC: O(n^2); SC: O(1) (assume input given)
// In Place Sorting: No additional space used (swapping)

/*    for (int i = 0; i<(n-1); ++i) {
        cout<<"Round: "<<(i+1)<<endl;
        for (int j = 0; j<(n-i-1); ++j) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
            cout<<"Step:"<<(j+1)<<endl;
            PrintArr(arr, n);
        }
    }*/

// INSERTION SORT - adaptable, stable - TC: O(n^2); SC: O(1) (assume input given))
// In Place Sorting: No additional space used (shifting)

    for (int i = 1; i<(n); ++i) {
        cout<<"Round: "<<(i)<<endl;
        int j = (i-1), val = arr[i];
        for (; j>=0; j--) {
            if (arr[j] > val) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
        }
        arr[j+1] = val;
        PrintArr(arr, n);
    }

    cout<<"List has been sorted"<<endl;
    PrintArr(arr, n);
    return 0;
}