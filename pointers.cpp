#include <iostream>
using namespace std;

//Pointer stores address of variable (variable of variable)

int main() {

/*    int num = 7;
    int *ptr = 0;
    ptr = &num;        //to access address we use & ("address of" operator)
    //ptr is a pointer to store "int" type

    cout<<ptr<<endl;    //memory address in hexadec
    cout<<*ptr<<endl; //* --> dereference operator (gives value stored at the pointed location)
    cout<<sizeof(num)<<endl;
    cout<<sizeof(ptr)<<endl;       //as it stores address, 32 bit: 4 ; 64 bit: 8       always

    int a1 = num;
    int a2 = *ptr;
    a1++;
    cout<<"a1: "<<a1<<endl;
    cout<<*ptr<<endl;

    (*ptr)++;
    (*ptr)*=2;
    cout<<"updated *ptr: "<<*ptr<<endl;
    cout<<"updated num: "<<num<<endl;

    //copying pointer
    int *q = ptr;
    cout<<ptr<<" -- "<<q<<endl;
    cout<<*ptr<<" -- "<<*q<<endl;

    //pointer arithmetics
    cout<<"initial ptr: "<<ptr<<endl;
    ptr+=1;     // goes to next location by adding as many number of bytes as 
                // taken by data type (here, int-->4)
    cout<<"Final ptr: "<<ptr<<endl;

    int arr[5] = {5,4,3,2,1};
    cout<<"Address of first element (0 index): "<<arr<<endl;    //arr points to first ele of array
    cout<<"Address of 1 index: "<<&arr[1]<<endl;
    cout<<"Initial *arr: "<<*arr<<endl;   //first element
    (*arr)++;
    cout<<"Updated *arr: "<<*arr<<endl;
    *(arr+1)+=1;
    cout<<"Updated 2nd element: "<<*(arr+1)<<endl;

    // ---NOTE---
    //arr[i] = *(arr+i) = *(i+arr) = i[arr]; basically it gives value at the memory location
    // of (arr + 4*i) as 1 block = 4 bytes for int. 

    cout<<4[arr]<<endl; //last element; 1

    int *p = &arr[0];
    
    //pointer stores location but is itself dotred in a different location
    cout<<p<<endl;
    cout<<&p<<endl;

    char ch[6] = "abcde";   //extra index for null char
    char *c = &ch[0];

    //both return the string itself
    cout<<ch<<endl;
    cout<<c<<endl;

    char temp = 'h';
    char *cr = &temp;

    // returns temp and some following chars until null char is found
    cout<<cr<<endl;

    // ---NOTE---
    //we can use pointers in a function, however scope for pointer itself is limited to function
    //whereas for pointer value it is not. This means we can operate on *ptr but not ptr to
    //reflect on main.

    //when we pass an array in a function, the array itself is not passed, however the pointer
    //*arr (pointing to 1st element) is passed behind the scenes.
    // func(int arr[]) --> func(int *arr)



    int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout<<"value at p: "<<*p<<endl;
    cout<<"printing p: "<<p<<endl;
    cout<<"printing p2: "<<p2<<endl;
    cout<<"value at p2: "<<*p2<<endl;
    cout<<"value through p2: "<<**p2<<endl;
    */


    return 0;
}