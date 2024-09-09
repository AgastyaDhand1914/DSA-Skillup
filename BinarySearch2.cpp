//WELCOME TO HELL :')

#include <iostream>
#include <algorithm>
using namespace std;

void MakeArr(int arr[], int size) {
     for (int i = 0; i < size; ++i) {
        int ele;
        cin>>ele;
        arr[i] = ele;
    }
}

bool PossibleAllocate(int arr[], int size, int students, int mid) {
    int student_count = 1, sum_pages = 0;
    for (int i = 0; i<size; ++i) {
        if (sum_pages + arr[i] <= mid) {
            sum_pages+=arr[i];
        }
        else {
            ++student_count;
            if ((student_count>students) || (arr[i]>mid)) { //arr[i] must not to be greater than mid
                return false;
            }
            sum_pages = arr[i];
        }
    }
    return true;
}

//*REVISIT THIS PROBLEM*
//Book allocation problem
int AllocateBooks(int arr[], int size, int students) {
    int s = 0, sum = 0;
    for (int i = 0; i<size; ++i) {
        sum+=arr[i];
    }
    int e = sum, mid = s + (e-s)/2, ans = -1;
    while(s<=e) {
        if(PossibleAllocate(arr,size, students, mid)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

//*REVISIT THIS PROBLEM*
//Painters Partition Problem
//same as book allocation
int PainterPartition(int arr[], int size, int painters) {
    int s = 0, total_time = 0;
    for (int i = 0; i<size; ++i) {
        total_time+=arr[i];
    }
    int e = total_time, mid = s + (e-s)/2, ans = -1;
    while(s<=e) {
        if (PossibleAllocate(arr, size, painters, mid)) {
            ans = mid;
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

bool CowAllocate (int arr[], int size, int cows, int mid) {
    int cow_count = 1, ref = arr[0];
    for ( int i = 0; i<size; ++i) {
        if(arr[i]-ref >= mid) {
            ++cow_count;
            if (cow_count==cows) {
                return true;
            }
            ref = arr[i];
        }
    }
    return false;
}

//Aggresive cows problem
//JUST REVISIT THE ENTIRE FILE AT THIS POINT, FML.....
int AggroCows(int arr[], int size, int cows) {
    std::sort(arr, arr + size);
    int s = 0, ans = -1, maxi = -1;
    for( int i = 0; i<size; ++i) {
        maxi = max(maxi, arr[i]);
    }
    int e = maxi;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if (CowAllocate(arr, size, cows, mid)) {
            ans = mid;
            s = mid+1;
        }
        else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int n, m;
    cout<<"Enter size of array:\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:\n";
    MakeArr(arr, n);
    cout<<"Enter number of Cows:\n";
    cin>>m;

    int result = AggroCows(arr, n, m);
    cout<<"Maximum distance among %d cows is: "<<result<<endl;
    return 0;
}