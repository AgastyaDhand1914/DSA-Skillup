#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//while defining function parameter for 2d arrays, we need to define columns in array otherwise 
//we get an error...
// ex. int func(int arr[][4])

bool isPresent(int arr[][3], int target, int row) {
    for( int i = 0; i<row; ++i) {
        for(int j = 0; j<3; ++j) {
            if (arr[i][j]==target) {
                return 1;
            }
        }
    }
    return 0;
}

void RowWiseSum(int arr[][3], int row) {
    int arr1[row];
    for (int i = 0; i<row; ++i) {
        int sum = 0;
        for (int j = 0; j<3; ++j) {
            sum+=arr[i][j];
            arr1[i] = sum;
        }
        cout<<"Sum of elements in row "<<i+1<<": "<<sum<<endl;
    }
    int max = 0;
    for (int i = 1; i<row; ++i) {
        if(arr1[max]<arr1[i]) {
            max = i;
        }
    }
    cout<<"Maximum row sum is: "<<arr1[max]<<" at row "<<max+1<<endl;
}

void WavePrint(int arr[][3], int row){
    for (int j = 0; j<3; ++j) {
        if (j%2==0) {
            for (int i = 0; i<row; ++i) {
                cout<<arr[i][j]<<" ";
            }
        }
        else {
            for (int i = row-1; i>=0; --i) {
                cout<<arr[i][j]<<" ";
            }
        }
    }
}


vector<int> SpiralPrint(vector<vector<int>>& matrix) {
    vector<int>result;
    int row = matrix.size(), col = matrix[0].size();
    int total_ele = row*col, count = 0;
        
    int row_start = 0, col_start = 0;
    int row_end = row-1, col_end = col-1;

    while(count<total_ele) {
            
        for(int i = col_start; (count<total_ele && i<=col_end); ++i) {
            result.push_back(matrix[row_start][i]);
            count++;
        }
        row_start++;

        for(int i = row_start; (count<total_ele && i<=row_end); ++i) {
            result.push_back(matrix[i][col_end]);
            count++;
        }
        col_end--;

        for(int i = col_end; (count<total_ele && i>=col_start); --i) {
            result.push_back(matrix[row_end][i]);
            count++;
        }
        row_end--;

        for(int i = row_end; (count<total_ele && i>=row_start); --i) {
            result.push_back(matrix[i][col_start]);
            count++;
        }
        col_start++;
    }

    return result;
}

void rotate(vector<vector<int>>& matrix) {      //rotate matrix by 90 deg. clockwise
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0; i<row; ++i) {
        for(int j = 0; j<i; ++j) {
            swap(matrix[i][j], matrix[j][i]);   //transpose
        }
    }

    for(int i = 0; i<row; ++i) { 
        reverse(matrix[i].begin(), matrix[i].end());    //reversing order of elements in every row
    }
}


//BINARY SEARCH IN 2D ARRAY

//Row elements are sorted and last element of a row is smaller than first element of following row.
//consider2d array into a linear array. traverse using linear[index] --> Bi[index/col][index%col]
//where col is number of coloumns in 2D array.

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size(), col = matrix[0].size();
    int s = 0, e = (row*col-1);
    int mid  =  s + (e-s)/2;
    while (s<=e) {
        if(matrix[mid/col][mid%col] == target)
            return 1;
        else if(matrix[mid/col][mid%col] > target)
            e = mid - 1;
        else if(matrix[mid/col][mid%col] < target)
            s = mid + 1;
        
        mid  =  s + (e-s)/2;
    }
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    //cornermost element of matrix at upper right
    int row_index = 0;
    int col_index = col-1;

    while(row_index<row && col_index>=0) {
        if (matrix[row_index][col_index] == target)
            return 1;
        else if (matrix[row_index][col_index] > target)//implies target does not lie on last(current) column
            col_index--;
        else if (matrix[row_index][col_index] < target)//implies target does not lie on first(current) row
            row_index++;
    }

    return 0;
}


int main() {
    int row, target;
    cin>>row;
    int arr[row][3];
    cout<<"Enter array elements: "<<endl;
    for (int i = 0; i<row; ++i) {
        for (int j = 0; j<3; ++j) {
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i<row; ++i) {
        for (int j = 0; j<3; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
//    cout<<"Enter target to search: "<<endl;
//    cin>>target;

//    cout<<target<<" is present: "<<isPresent(arr, target, row);
//    WavePrint(arr, row);
    return 0;
}