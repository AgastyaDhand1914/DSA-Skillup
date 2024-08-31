#include <bits/stdc++.h>
using namespace std;

int sub_Arr(int arr1[], int arr2[]) {
        int count = 0;
        for (int i = 0; i<3; ++i) {
            for (int j = 0; j<10; ++j) {
                if (arr2[i] == arr1[j]) {
                    count+=1;
                }
            }
        }
        return count;
    }
    
int main() {

    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
    int arr2[3];
    for (int i = 0; i <3; ++i) {
        int n;
        cin>> n;
        arr2[i] = n;
    }



    if (sub_Arr(arr1, arr2) == 3) {
        cout<<"true";
    }
    else {
        cout<<"false";
    }
    return 0;
}