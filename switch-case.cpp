#include <iostream>
using namespace std;

 int main() {

    int n;//, a, b;
//    char op;
    cin>>n;
//    cin>>a>>b>>op;

/*Continue is not valid statement within case block as when the flow of code comes down to it and try to
 execute it, because of continue statement it would skip and re-iterate and execution will continue for 
 indefinite amount of time. For this purpose the break statement is valid*/

//Simple Calculator
    /*switch (op) {
        case '+': 
            cout<<a+b<<endl;
            break;

        case '-': 
            cout<<a-b<<endl;
            break;
        
        case '*': 
            cout<<a*b<<endl;
            break;
        
        case '/': 
            cout<<a/b<<endl;
            break;
        
        case '%': 
            cout<<a%b<<endl;
            break;

        default: cout<<"Enter valid values";
    }*/

//n amount of money to num of 100, 50, 20 & 1 rs notes

switch (1) {

    case 1: 
        cout<<"Rs100 notes: "<<n/100<<endl;
        n%=100;
    case 2: 
        cout<<"Rs50 notes: "<<n/50<<endl;
        n%=50;
    case 3: 
        cout<<"Rs20 notes: "<<n/20<<endl;
        n%=20;
    case 4: 
        cout<<"Rs1 notes: "<<n<<endl;

}

    return 0;
 }