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

int main() {

    int n, r;
    cin>>n>>r;
    cout<<fact(n)<<endl<<fact(r)<<endl;
    cout<<nCr(n, r)<<endl;
    
    if (Prime(n)==1) {
        cout<<n<<" is Prime"<<endl;
    }
    else {
        cout<<n<<" is not Prime"<<endl;
    }

    return 0;
}