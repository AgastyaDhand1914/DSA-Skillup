#include <iostream>
#include <cstring>
using namespace std;

int factorial(int num) {
    if(num==0)
        return 1;   
        //base case. (termination of recursion)
        //no base case --> segmentation fault (function call till call stack overflows)
    else
        return  num * factorial(num-1);
}

int power(int num, int pow) {   // where pow is positive
    if (num==0 || num ==1)
        return 1;
    else if (pow == 1) 
        return num;
    else 
        return num * power(num, pow - 1);
}

void series(int num) {
    if (num==0)
        return;
    
    cout<<num<<" ";
    series(num - 1);
}

int climbstairs(int num) {
    if (num<0)
        return 0;
    else if (num==0)
        return 1;

    return climbstairs(num - 1) + climbstairs(num - 2);
}

void saydigits(long num) {
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (num == 0) 
        return;
    saydigits(num/10);
    cout<<arr[num%10]<<" ";
}

bool isSorted(int *arr, int size) {
    if (size==0 || size==1)
        return true;
    if (arr[0] > arr[1])
        return false;

    return isSorted((arr+1), size - 1);
}

int sum(int *arr, int size) {
    if (size==0) 
        return 0;
    return *arr + sum((arr + 1), size - 1);
}

bool LinearSearch(int *arr, int size, int key) {
    if (*arr==key)
        return true;
    if (size==0)
        return false;
    return LinearSearch(arr + 1, size - 1, key);
}

bool BinarySearch(int arr[], int s, int e, int key) {
    int mid = s + (e-s)/2;
    if (*(arr+mid) == key)
        return true;
    if (s>e)
        return false;
    if (*(arr+mid) > key)
        return BinarySearch(arr, s, mid - 1, key);
    if (*(arr+mid) < key)
        return BinarySearch(arr, mid + 1, e, key);
}

void reverseString(string &str, int s) {
    int e = str.length() - s - 1;
    if (s>e) 
        return;
    swap(str[s], str[e]);
    reverseString(str, ++s);
}

bool checkPalindrome(string str, int s) {
    int e = str.length() - s - 1;
    if (s>e) 
        return true;
    if (str[s] != str[e])
        return false;
    return true && checkPalindrome(str, ++s);
}

void bubbleSort(int *arr, int size) {
    if (size==0 || size==1)
        return;
    for (int i = 0; i<size-1; ++i) {
        if (*(arr + i) > *(arr + i + 1))
            swap(arr[i], arr[i+1]);
    }

    cout<<"Round: ";
    for (int i = 0; i<size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    bubbleSort(arr, size - 1);
}

void selectionSort(int *arr, int size) {
    if (size==0 || size==1)
        return;
    for (int i = size - 1; i>0; --i) {
        if (arr[i] < arr[i-1])
            swap(arr[i], arr[i-1]);
    }

    cout<<"Round: ";
    for (int i = 0; i<size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    selectionSort(arr+1, size-1);
}

void inserionSort(int *arr, int size) {
    if(size==0 || size==1)
        return;

    inserionSort(arr, size-1);

    int i = size-2, val = arr[size-1];
    for(; i>=0; --i) {
        if (arr[i] > val)
            arr[i+1] = arr[i];
    }
    arr[i+1] = val;

    cout<<"Round: ";
    for (int i = 0; i<size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {

     int n, key;//, pow;
     cin>>n;//>>pow;

     int *arr = new int[n];   
     for (int i = 0; i<n; ++i) {
         cin>>arr[i];    
     }

    // cout<<"Enter key: \n";
    // cin>>key;

//    cout<<"Factorial of "<<n<<" is: "<<factorial(n)<<endl;
//    cout<<n<<" to the power "<<pow<<" is "<<power(n, pow)<<endl;
//    cout<<n<<" ki Series: "<<endl;
//    series(n);
//    cout<<"Total ways of climbing "<<n<<" stairs is: "<<climbstairs(n)<<endl;
//    cout<<n<<" in words is: "<<endl;
//    saydigits(n);

//    cout<<"Array is Sorted: "<<isSorted(arr, n)<<endl;
//    cout<<"Sum of given array: "<<sum(arr, n)<<endl;
//    cout<<"Linear searching inputted Array for key: "<<key<<endl;
//    cout<<"Result: "<<LinearSearch(arr, n, key)<<endl;

    // cout<<"Binary searching inputted Sorted Array for key: "<<key<<endl;
    // cout<<"Result: "<<BinarySearch(arr, 0, n - 1, key)<<endl;

//     string ch;
//     cin>>ch;

//     reverseString(ch, 0);
//     cout<<"Reversed String: "<<ch<<endl;

//     cout<<"Given String is Palindrome: "<<checkPalindrome(ch, 0)<<endl;


    // bubbleSort(arr, n);
    // cout<<"Sorted Array using Recursive Bubble Sort: "<<endl;
    // for (int i = 0; i<n; ++i) {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<endl;

    // selectionSort(arr, n);
    // cout<<"Sorted Array using Recursive Selection Sort: "<<endl;
    // for (int i = 0; i<n; ++i) {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<endl;

    // inserionSort(arr, n);
    // cout<<"Sorted Array using Recursive Insertion Sort: "<<endl;
    // for (int i = 0; i<n; ++i) {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    return 0;
}