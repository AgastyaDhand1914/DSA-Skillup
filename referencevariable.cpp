#include <iostream>
using namespace std;

void update1(int n) {
    //pass by value-->creates a copy of variable with new memory and modifies it
    //not reflected in main
    n++;
}

void update2(int &n) {
    //pass by reference-->does not create a copy. works on same memory reference with separate name
    n++;
}

void sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i<n; ++i) {
        sum+= arr[i];
    }
    cout<<"Sum: "<<sum<<endl;
}

//never return a pointer/reference variable through a function because they are limited to the scope
//of the function (local) and after execution that memory is erased
//on execution we get a warning

// ---NOTE---

//int n; 
//cin>>n;
//int arr[n];

//never use above practice: array size is formed during runtime after n is inputted.
//it is ideal to know the size of array at time of compiling
//During compiling, memory is allocated into stack and heap which are fixed for a program.

//stack is static memory allocation
//heap is dynamic memory allocation

//array goes into stack. if size of array that we input during runtime turns out to be greater than
//the stack, the program crashes

//Solution: Use heap memory

int main() {

    int n;
    cin>>n;

 /*   int n = 5;
    cout<<"Initial: "<<n<<endl;
    update2(n);
    cout<<"Final: "<<n<<endl;*/

    //Dynamic memory allocation

    char *ptr = new char;   
    //new char returns address of memory allocated in heap for a single char
    //this memory is dynamic
    //however, ptr is stored in stack, which points to a memory in heap
    //total memory = size of ptr + size of char

    //variable array size
/*    int *arr = new int[n];
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }
    sum(arr, n);*/

    //2D array (n x n) creation
    int **arr = new int *[n];   //n-->row
    for (int i = 0; i<n; ++i) {
        arr[i] = new int[n];    //n-->col
    }

    //2D array initialisation
    for (int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j) {
            cin>>arr[i][j];
        }
    }

    //2D array print
    for (int i = 0; i<n; ++i) {
        for(int j = 0; j<n; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // ---NOTE---
    //unlike stack where memory is erased after usage, in heap we manually release/free memory.
    //using "delete"

    //releasing memory
    for (int i = 0; i<n; ++i) {
        delete []arr[i];    //first delete *ptr, which are individual rows of 2D array
    }

    delete []arr;   //deleting **ptr, which was for the whole array

    return 0;
}