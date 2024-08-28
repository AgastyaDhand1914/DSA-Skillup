#include <iostream>
#include <math.h>
using namespace std;

int main() {

    int n;
    cin>>n;
//    int a = 0, b = 1;
//    int prod = 1, sum = 0;
//    int num_in_bit = 0;
//    int num_in_dec = 0;
//    int num_in_bit_comp = 0;
//    int num_in_dec_comp = 0;


// Fibonacci Series
    /*for (int i = 1; i<=n; ++i) {
        cout<<a<<endl;
        a = a + b;
        b = a - b;
    }*/

// Diff of sum and product of digits of a num, given num is positive
   /*while(n>0) {

    int x = n%10;
    n/=10;
    prod*=x;
    sum+=x;
   }

   cout<<prod - sum;*/

//Decimal to Binary
    /*int i = 0;
    while (n!=0) {
        int rem = n%2;

        num_in_bit += (rem*(pow(10,i)));
        n/=2;
        i++;
    }
    cout<<num_in_bit;*/

//Binary to Decimal
    /*int j = 0;
    while (n!=0) {
        int bit = n%10;
        n=n/10;
        if (bit==1) {
            num_in_dec+= pow(2, j);
        }
        j++;
    }

    cout<<num_in_dec<<endl;
    */
//Reversing num
    /*int rev = 0; //range from -2^32 to 2^31 -1, (32 bit) therefore also consider case when reverse is out of range
    while (n!=0) {
        int digit = n%10;
        n/=10;
        //comparing reversed num with range of int (32 bit as per ques)
        if ((rev> INT32_MAX/10) || (rev< INT32_MIN/10)) {
            cout<<"Reversed num is: 0";   // we did not use rev*10 as it is out of int range
        }
        else {
            rev = 10*rev + digit;
        }
    }

    if ((rev< INT32_MAX/10) && (rev> INT32_MIN/10))  {
        cout<<"Reversed num is: "<<rev;
    }*/

   //compliment of base 10 int

    /*int bit_AND = 0;  //this is a mask created so as to ignore the 11111.... in the compliment for
                      //entered +ve num so that the output is not -ve.
    int dupe_n = n;
    while (dupe_n != 0) {
        bit_AND = (bit_AND<<1) | 1;
        dupe_n >>= 1;
    }
    if (n==0) {    // edge case
        cout<<"Compliment of base 10 int as given is: 1";
    }
    else {
        cout<<"Compliment of base 10 int as given is: "<<((~n) & bit_AND);
    }*/
    //~(NOT) returns compliment of given binary with 11111..., to ignore it, we apply AND with our mask
    //which is of the form 0000....111 7s(relative to num of actual bits of n)

    //Power of 2
    int x = 1;
    for (int i = 0; i<=30; i++) {
        if (x==n) {
            cout<<"true, "<<i;
            break;
        }
        x*=2;
    }
    if (x!=n) {
        cout<<"false";
    }
    else if (x == pow(2,31)) {
        cout<<"false";
    }
    return 0;
} 