#include <iostream>
using namespace std;

//Binary search is only applicable if array elements are Sorted (monotonic)

//inputting array
void MakeArr(int arr[], int size) {
     for (int i = 0; i < size; ++i) {
        int ele;
        cin>>ele;
        arr[i] = ele;
    }
}

//searching for entered element in sorted array
int BSearch(int arr[], int s, int e, int key) {
    int begin = s;
    int finish = e;
    int middle = begin + (finish - begin)/2; 
//we dont directly use (beg+fin)/2 due because of invalidity when size = 2^31 - 1;
    while(begin<=finish) {
        if (arr[middle] == key) {
            return middle;
        }
        else if (arr[middle] > key) {
            finish = middle-1;
        }
        else if (arr[middle] < key) {
            begin = middle+1;
        }
        middle = begin + (finish - begin)/2;
    }
    return -1;
}

//leftmost occurence of given element
int FirstOcc(int arr[], int size, int key) {
    int ans = -1;
    int begin = 0;
    int finish = size-1;
    int middle = begin + (finish - begin)/2; 

    while(begin<=finish) {
        if (arr[middle] == key) {
            ans = middle;
            finish = middle-1;
        }
        else if (arr[middle] > key) {
            finish = middle-1;
        }
        else if (arr[middle] < key) {
            begin = middle+1;
        }
        middle = begin + (finish - begin)/2;
    }
    return ans;
}

//rightmost occurence of given element 
int LastOcc(int arr[], int size, int key) {
    int ans = -1;
    int begin = 0;
    int finish = size-1;
    int middle = begin + (finish - begin)/2; 

    while(begin<=finish) {
        if (arr[middle] == key) {
            ans = middle;
            begin = middle+1;
        }
        else if (arr[middle] > key) {
            finish = middle-1;
        }
        else if (arr[middle] < key) {
            begin = middle+1;
        }
        middle = begin + (finish - begin)/2;
    }
    return ans;
}

//finding index of "peak" in a mountain array
int MountainPeak(int arr[], int size) {
    int s = 0;
    int e = size-1;
    int mid = s + (e-s)/2;
    int peak;
    while(s<=e) {
        if (arr[mid] > arr[mid+1]) {
            e = mid-1;
        }
        else if (arr[mid] < arr[mid+1]) {
            s = mid+1;
        }
        mid = s + (e-s)/2;
        peak = mid;
    }
    return peak;
}

int pivotIndex(int arr[], int size) {
        int sumleft = 0;
        int sumright = 0;
        for (int i = 1; i<size; ++i) {
            sumleft+=arr[i];
        }   
        for (int j = 0; j<size; ++j) { 
            if (sumleft == sumright) {
                return j;
            }
            if (j<(size-1)) {
                sumright+=arr[j];
                sumleft-=arr[j+1];
            }
        }
        return -1;
    }

//array is sorted but rotated. e. [1,2,3,4,5]-->[3,4,5,1,2]. Pivot point is therefore 1, at index 3.
int Pivot(int arr[], int size) {
    int s = 0;
    int e = size-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        if (arr[mid]>=arr[0]) {
            s = mid+1;
        }
        else {
            e = mid;
        } 
        mid = s + (e-s)/2;
    }
    return e;
}

//searching for element in roatated sorted array. For this we find pivot point and then compare.
int search_rotated(int arr[], int size, int key) {
    int s = 0;
    int e = size-1;
    int pivot_index = Pivot(arr,size);
    int mid = s+ (e-s)/2;
    if ((arr[pivot_index]<=key) && (arr[size-1]>=key)) {
        return BSearch(arr, pivot_index, (size-1), key);
    }
    else {
        return BSearch(arr, 0, pivot_index, key);
    }
}

//sqrt using binary search
int sqrtBS(int num) {
    int ans, s = 0, e = num;
    long long int mid = s + (e-s)/2;
    while (s<=e) {
        if ((mid*mid)>num) {
            e = mid-1;
        }
        else if ((mid*mid)<=num) {
            ans = mid;
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {

//Array is SORTED (/MONOTONIC) in all cases except pivot index.

    int n, k;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
//    int arr[n];
//    cout<<"Enter elements of array: "<<endl;
//    MakeArr(arr, n);
    int ans = sqrtBS(n);
    cout<<"Square root of entered number is: "<<ans<<endl;
    return 0;
}