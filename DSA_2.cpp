#include <iostream>
#include <math.h>
using namespace std;

int main() {

    int n;
    cin>>n;
//    int a = 0, b = 1;
//    int prod = 1, sum = 0;
//    float num_in_bit = 0;
    int num_in_dec = 0;


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
    int j = 0;
    while (n!=0) {
        int bit = n%10;
        n=n/10;
        if (bit==1) {
            num_in_dec+= pow(2, j);
        }
        j++;
    }

    cout<<num_in_dec<<endl;

    return 0;
} 