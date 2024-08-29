#include <iostream>
using namespace std;

//factorial
int fact(int n) {
    int prod = 1;
    for (int i = 1; i<=n; ++i) {
        prod*=i;
    }
    return prod;
}

//nCr (combination)
int nCr(int n, int r) {
    int result = (fact(n))/(fact(r)*fact(n-r));
    return result;
}

//Check for prime
bool Prime(int n) {
    for (int i = 2; i<n; ++i) {
        if (n%i==0) {
            return false;
        }
    }
    return true;

}

//nth term of AP
int nthAP(int n) {
    return (3*n +7);
}

//count total set bits (1s)

int count_setbits(int n) {
    int count = 0;

    while(n!=0) {
        int bit1 = n&1;
        n>>=1;
        if (bit1 == 1) {
            count+=1;
        }
    }
    return count;
}

int main() {

    int n, r;
    cin>>n>>r;
    cout<<n<<" factorial is: "<<fact(n)<<endl<<r<<" factorial is: "<<fact(r)<<endl;
    cout<<"nCr is: "<<nCr(n, r)<<endl;
    
    if (Prime(n)==1) {
        cout<<n<<" is Prime"<<endl;
    }
    else {
        cout<<n<<" is not Prime"<<endl;
    }

    cout<<"n term of AP is: "<<nthAP(n)<<endl;
    cout<<"Total set bits (1s) are: "<<(count_setbits(n) + count_setbits(r));
    return 0;
}