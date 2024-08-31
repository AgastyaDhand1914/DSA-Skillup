#include <iostream>
using namespace std;

int main() {

    int n;
    cin>>n;
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cout<<n-j+1<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=(n*n); i+=n) {
        for (int j = i; j<=(n+i-1); ++j) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<=i; ++j) {
            cout<<'*';
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = 0; j<i; ++j) {
            cout<<i;
        }
        cout<<endl;
    }
    cout<<endl;
    int counter = 1;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=i; ++j) {
            cout<<counter<<" ";
            counter+=1;
        }
        cout<<endl;
    }
    cout<<endl;
    int counter1 = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = i; j<=(i+counter1); ++j) {
            cout<<j<<" ";
        }
        counter1+=1;
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = i; j>=1; --j) {
            cout<<j<<" ";;
        }
        cout<<endl;
    }
    cout<<endl;
    for (char i = 65; i<=(65+n-1); ++i) {
        for (char j = 65; j<=i; ++j) {
            cout<<i;
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=(n); ++i) {
        for (int j = 1; j<=n; ++j) {
            cout<<char('A'+j-1 )<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=(n*n); i+=n) {
        for (int j = i; j<=(n+i-1); ++j) {
            cout<<char('A'+j-1)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int counter2 = 0;
    for (int i = 1; i<=(n); ++i) {
        for (int j = 1; j<=(n); ++j) {
            cout<<char('A'+i+j-2)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = 0; j<i; ++j) {
            cout<<char('A'+i-1)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int counterA = 0;
    for (int i = 0; i<n; ++i) {
        for (int j = 1; j<=i; ++j) {
            cout<<char('A'+counterA)<<" ";
            counterA+=1;
        }
        cout<<endl;
    }
    cout<<endl;
    int counterB = 0;
    for (int i = 0; i<n; ++i) {
        for (int j = 1; j<=i; ++j) {
            cout<<char('A'+i+j-2)<<" ";
        }
        counterB+=1;
        cout<<endl;
    }
    cout<<endl;
    for (int i = n; i>0; --i) {
        for (int j = n; j>=i; --j) {
            cout<<char('A'+ (i-j+n-1))<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = (n-i); j>0 ; --j) {
            cout<<" ";
        }
        for (int k = 1; k<=i ; ++k) {
            cout<<'*';
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<i; ++j) {
            cout<<" ";
        }
        for (int k = n-i; k>0; --k) {
            cout<<"X";
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<i; ++j) {
            cout<<" ";
        }
        for (int k = n-i; k>0; --k) {
            cout<<i+1;
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 1; i<=n; ++i) {
        for (int j = (n-i); j>0 ; --j) {
            cout<<" ";
        }
        for (int k = 1; k<=i ; ++k) {
            cout<<i;
        }
        cout<<endl;
    }
    cout<<endl;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<i; ++j) {
            cout<<" ";
        }
        for (int k = i+1; k<=n; ++k) {
            cout<<k;
        }
        cout<<endl;
    }
    cout<<endl;
    int counterS = 1;
    for (int i = n; i>0; --i) {
        for (int j = i; j>0; --j) {
            cout<<"  ";
        }
        for (int k = 1; k<=(n-i+1); ++k) {
            cout<<counterS<<" ";
            counterS+=1;
        }
        cout<<endl;
    }
    cout<<endl;

    for (int i = n; i>0; --i) {
        for (int j = i; j>0; --j) {
            cout<<"  ";
        }
        for (int k = 1; k<=(n-i+1); ++k) {
            cout<<k<<" ";
        }
        for (int l = (n-i); l>0; --l) {
            cout<<l<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for ( int i = 1; i<=n; ++i) {
        for (int j = 1; j<=(n-i+1); ++j) {
            cout<<j;
        }
        for (int k = 1; k<i; ++k) {
            cout<<"**";
        }
        for (int l = (n-i+1); l>0; --l) {
            cout<<l;
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}