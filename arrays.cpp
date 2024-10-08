#include <iostream>
using namespace std;

/* Unlike variables, any change in the array inside a function also reflects in the main function.
In case of variables, a copy of it is formed which is then modified, whereas in array inside the function,
directly the address of the data is provided to execute upon. */

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

// find max num
void MaxArr(int arr[], int size) {
    int max_ele = arr[0];
    for (int i = 1; i < size; ++i) {
        if (max_ele < arr[i]) {
            max_ele = arr[i];
        }
    }
    cout<<"Maximum element in given array is: "<<max_ele<<endl;
}

// find min num
void MinArr(int arr[], int size) {
    int min_ele = arr[0];
    for (int i = 1; i < size; ++i) {
        if (min_ele > arr[i]) {
            min_ele = arr[i];
        }
    }
    cout<<"Minimum element in given array is: "<<min_ele<<endl;
}

//Sum of elements in array
int SumArr(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        int num = int(arr[i]);
        sum += num;
    }
    return sum;
}

//Linear search
bool SearchArr(int arr[], int size, int to_search) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == to_search) {
            return 1;
        }
    }
    return 0;
}

//Reversing array
void RevArr(int arr[], int size) {
    int begin = 0;
    int end = size - 1;
    while(begin<=end) {
        int swapper;
        swapper =arr[end];
        arr[end] = arr[begin];
        arr[begin] =swapper;
        
        ++begin;
        --end;
    }
    cout<<"Array reversed"<<endl;
}

//Reversing alternate terms of array
void RevAltArr(int arr[], int size) {
    for (int i = 0; i < size-1; i+=2) {
        int swapper;
        swapper =arr[i+1];
        arr[i+1] = arr[i];
        arr[i] =swapper;
    }
    cout<<"Array alternate elements were reversed"<<endl;
}

//Find the non duplicate element, list sie must always be of 2m+1 type, i.e., odd.
//better solution is to perform logical XOR(^) of all elements. a^a = 0 and 0^a= a. therefore, directly
//the non duplicate element can be found...
void NonDupArr(int arr[], int size) {
    for (int i = 0; i<size; ++i) {
        int count = 0;
        for (int k = 0; k<size; ++k) {
            if (arr[i]==arr[k]) {
                continue;
            }
            else {
                count+=1;
            }
        }
        if (count==(size-1)) {
            cout<<"Non duplicate element is: "<<arr[i]<<endl;
            break;
        }
    }
    return;
}

//find dupe element
//optimsed way with XOR
void DupArr(int arr[], int size) {
    for(int i = 0; i<size; ++i) {
        for(int k=(i+1);k<size; ++k) {
            if (arr[i]==arr[k]) {
                 cout<<"Duplicate element is: "<<arr[k]<<endl;
            }
        }
    }
    return;
}


int main() {

// inputting array
    int n;
    cin>>n;
    int arr[n];

    MakeArr(arr, n);
    PrintArr(arr, n);
/*    MaxArr(arr, n);
    MinArr(arr, n);
    cout<<"Sum of elements of given list is: "<<SumArr(arr, n)<<endl;

    int ele_search;
    cout<<"Enter element to search in array: "<<endl;
    cin>>ele_search;
    bool ans = SearchArr(arr, n, ele_search);

    if (ans) {
        cout<<"Element is present in array"<<endl;
    }
    else {
        cout<<"Element is absent in array"<<endl;
    }
    cout<<endl;
    RevArr(arr, n);
    PrintArr(arr, n);
    RevAltArr(arr, n);
    PrintArr(arr, n);
    NonDupArr(arr, n);*/
    DupArr(arr, n);
    return 0;
}