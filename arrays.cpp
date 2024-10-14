#include <iostream>
#include <vector>
#include <algorithm>
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

void MakeVec(vector<int>&arr, int size) {
     for (int i = 0; i < size; ++i) {
        int ele;
        cin>>ele;
        arr.push_back(ele);
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

void PrintVec(vector<int>&arr, int size) {
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

//Find the non duplicate element, list size must always be of 2m+1 type, i.e., odd.
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

//merge two sorted arrays
void Merge2Arr(int arr1[], int size1, int arr2[], int size2, int arr3[]) {
    int i = 0, j = 0, k = 0;
    while(i<size1 && j<size2) {
        if (arr1[i]>arr2[j]) {
            arr3[k] = arr2[j];
            cout<<arr3[k]<<" ";
            j++;
            k++;
        }
        else {
            arr3[k] = arr1[i];
            cout<<arr3[k]<<" ";
            i++;
            k++;
        }
    }

//when one of the array's indexes reaches end value, we just need to copy remaining elements of
//other array in same sorted order
//either loop will be executed based on inputed sizes
    while(j<size2) {
        arr3[k] = arr2[j];
        cout<<arr3[k]<<" ";
        j++;
        k++;
    }

    while(i<size1) {
        arr3[k] = arr1[i];
        cout<<arr3[k]<<" ";
        i++;
        k++;

    }

    cout<<endl;
    return;
}


//two sorted arrays with zeroes on end one of array equal to number of elements on second array
//example: arr1 = [1,2,3,0,0,0] arr2 = [2,5,6]....Result = [1,2,2,3,5,6]
void merge2Arrinsame(int arr1[], int size1, int arr2[], int size2) {
    int arr3[max(size1, size2)];
    int i = 0, j = 0, k = 0;

    while(i<size1 && j<size2) {
        if (arr1[i]>arr2[j]) {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
    }

/*    while(j<size2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }*/

    while(i<(size1-size2)) {
        arr3[k] = arr2[i-j];
        i++;
        k++;

    }
    int num = 0;

    for (int l = 0; l<max(size1, size2); l++) {
        arr1[l] = arr3[l];
    }

    cout<<endl;
    return;
}

//move zeroes to right side and preserve order of non-zero elements
void moveZeroes(int arr[], int size) {
    int i = 0;
    for (int j = 0; j<size; ++j) {
        if (arr[j]!=0) {
            swap(arr[j], arr[i++]);
            
        }
    }
    return;
}

//shift elements to left by k places
void Shift_ele_left(int arr[], int size, int k) {
    int arr1[size];
    for(int i = 0; i<size; ++i) {
        int shifted_index = (i+k)%(size);
        arr1[shifted_index] = arr[i];         //to get index location for shifting
    }
    for (int i = 0; i<size; ++i) {
        arr[i] = arr1[i];
    }
}

//ex. k = 3, size of array = 5
//i<k
//0--> 2 (size-k+i)
//1--> 3 (size-k+i)
//2--> 4 (size-k+i)
//i>=k
//3--> 0 (i-k)
//4--> 1 (i-k)
//shift elements to right by k places
void Shift_ele_right(int arr[], int size, int k) {
    int arr1[size];
    int shifted_index;
    for(int i = 0; i<size; ++i) {
        if (i<k) {
            shifted_index = (size-k+i);        //to get index location for shifting
        }
        else {
            shifted_index = (i-k);
        }

        arr1[shifted_index] = arr[i];
    }
    for (int i = 0; i<size; ++i) {
        arr[i] = arr1[i];
    }
}


//add two arrays. ex. [1,2,3] + [1,0,8] = [2,3,1]
//[9,0,1] + [2,1,0] = [1,1,1,1]
void add_two_arr(vector<int>&arr1, vector<int>&arr2) {
    vector<int>arr_res;

    int i = (arr1.size()-1), j = (arr2.size()-1); 
    int sum, carry = 0;
    while(i>=0 && j>=0) {
        sum = arr1[i] + arr2[j] + carry;
        carry = sum/10;
        sum%=10;
        arr_res.push_back(sum);
        i--;
        j--;
    }

    while(i>=0) {
        sum = arr1[i]+ carry;
        carry = sum/10;
        sum%=10;
        arr_res.push_back(sum);
        i--;
    }

    while(j>=0) {
        sum = arr2[j] + carry;
        carry = sum/10;
        sum%=10;
        arr_res.push_back(sum);
        j--;
    }

    while(carry!=0) {
        sum = carry;
        carry = sum/10;
        sum%=10;
        arr_res.push_back(sum);
    }

    reverse(arr_res.begin(), arr_res.end());
    arr1 = arr_res;
    return;
}



int main() {

// inputting array

    int n1, n2;
    cout<<"Enter sizes of arr1 and arr2 respectively: "<<endl;
    cin>>n1>>n2;
//    cout<<"Enter places to shift:"<<endl;
//    cin>>k;
    vector<int>arr1;
    vector<int>arr2;
//    int arr2[n2];

//    int arr3[n1+n2];

    MakeVec(arr1, n1);
    MakeVec(arr2, n2);
//    MakeArr(arr2, n2);
    PrintVec(arr1, n1);
    PrintVec(arr2, n2);
//    PrintArr(arr2, n2);
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

//    Merge2Arr(arr1, n1, arr2, n2, arr1);
//    merge2Arrinsame(arr1, n1, arr2, n2);
//    PrintArr(arr1, n1);
//    moveZeroes(arr1, n1);
//    Shift_ele_right(arr1, n1, k);
    add_two_arr(arr1, arr2);
    cout<<"Addition: "<<endl;
    PrintVec(arr1, arr1.size());

    return 0;
}