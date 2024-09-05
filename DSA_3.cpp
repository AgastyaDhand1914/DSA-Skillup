#include <bits/stdc++.h>
#include <vector>
using namespace std;

// define array
void MakeArr(int arr[], int size) {
     for (int i = 0; i < size; ++i) {
        int ele;
        cin>>ele;
        arr[i] = ele;
    }
}

// print array
void PrintArr(int arr[], int size) {
    cout<<"List elements are: ";
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sub_Arr(int arr1[], int arr2[]) {
    int count = 0;
    for (int i = 0; i<3; ++i) {
        for (int j = 0; j<10; ++j) {
            if (arr2[i] == arr1[j]) {
                    count++;
            }
        }
    }
    return count;
}

std::vector<int> ArrInter(int arr1[], int size1, int arr2[], int size2) {
    std::vector<int> ans;
    int l = 0;
    for(int i = 0; i<size1; ++i) {
        for (int k = 0; k<size2; ++k) {
            if (arr1[i]==arr2[k]) {
                ans.push_back(arr1[i]);
                break;
            }
        }
    }
    return ans;
}

std::vector<std::vector<int>> findTriplets( vector<int>arr, int n, int k) {
    std::vector<std::vector<int>> ans;
    for(int i = 0; i<n; ++i) {
        for(int j = i+1; j<n; ++j) {
            for(int l = j+1; l<n; ++l) {
                if (arr[i]+arr[j]+arr[l] == k) {
                    std::vector<int> arr1 = {arr[i], arr[j], arr[l]};
                    ans.push_back(arr1);
                }
            }
        }
    }
    return ans;
}

int main() {

// searching for sorted sub array in a pre-defined sorted array 
/*    int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
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


    int n1, n2;
    cin>>n1>>n2;
    int arr1[n1], arr2[n2];
    MakeArr(arr1, n1);
    cout<<endl;
    MakeArr(arr2, n2);
    cout<<endl;

    std::vector<int> ans = ArrInter(arr1, n1, arr2, n2);
    cout << "Intersection elements: ";
    for (int num : ans) {
        std::cout << num << " ";  // Print each element in the vector
    }
    std::cout << std::endl;*/

    int n, k;
    cin>>n>>k;
    std::vector <int> arr;
    cout<<"Enter elements for array:"<<endl;
    for(int i= 0; i<n; ++i) {
        int ele;
        cin>>ele;
        arr.push_back(ele);
    }
    
    std::vector<std::vector<int>> result = findTriplets(arr, n, k);
    cout<<"Triplets with sum as "<<k<<" are:"<<endl;
    for (const std::vector<int>& num : result) { // Looping through each triplet
        std::cout << "{ ";
        for (int x : num) { // Looping through each element in the triplet
            std::cout << x << " ";
        }
        std::cout << "}" << std::endl;
    }


    return 0;
}