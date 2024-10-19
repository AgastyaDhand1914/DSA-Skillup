#include <iostream>
#include <vector>
using namespace std;

bool equal_arr(int arr1[26], int arr2[26]) {
    for (int i = 0; i<26; ++i) {
        if (arr1[i] != arr2[i]) 
            return 0;
    }
    return 1;
}

void MakeVec(vector<char>&arr, int size) {
     for (int i = 0; i < size; ++i) {
        char ele;
        cin>>ele;
        arr.push_back(ele);
    }
}

void PrintVec(vector<char>&arr, int size) {
    cout<<"List elements are: ";
    for (char i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void PrintArr(int arr[], int size) {
    cout<<"List elements are: ";
    for (int i = 0; i < size; ++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int len_str(char arr[]) {
    int count = 0;
    for (int i = 0; arr[i]!='\0'; ++i) {
        count++;
    }
    return count;
}

void rev_str(char arr[], int size) {
    int s = 0, e = size - 1;

    while(s<e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    return;
}

int check_palindrome(char arr[]) {      //if string = reversed string
    int s = 0, e = len_str(arr) - 1;

    while(s<e) {
        if (arr[s++]!=arr[e--]) 
            return 0;
    }
    return 1;
}

//string stores data internally in form of null(\0) terminated C-string butin normal usage 
//does not allow you to access the null terminator

string lowercase(char arr[]) {
    string j = "";
    for (int i= 0; i<len_str(arr); ++i) {
        if (arr[i]>='a' && arr[i]<='z') {
            j += arr[i];
        }
        else if (arr[i]>='A' && arr[i]<='Z') {
            j += arr[i] + 'a' - 'A';
        }
    }
    return j;
}


int check_palindrome_str(string j) {
            int s = 0, e = j.size() - 1;

                while(s<e) {
                    if (j.at(s++)!=j.at(e--)) 
                        return 0;
                }
                    return 1;
    }

    string lowernumcase_str(string s) {
        string j = "";
        for (int i= 0; i<s.size(); ++i) {
            if (s.at(i)>='a' && s.at(i)<='z') {
                j += s.at(i);
            }
            else if (s.at(i)>='A' && s.at(i)<='Z') {
                j += s.at(i) + 'a' - 'A';
            }
            else if (s.at(i)>='0' && s.at(i)<='9') {
                j += s.at(i);
            }
        }
        return j;
    }

    bool isPalindrome(string s) {
        string j = lowernumcase_str(s);
        return check_palindrome_str(j);
    }


char mx_occ_char(string s) {
        int arr[26] = {0};

        for (int i = 0; i<s.length(); ++i) {
            int num = 0;
            if (s[i]>='a' && s[i]<='z') 
                num = s[i] - 'a';
            else
                num = s[i] - 'A';
            arr[num]++;
        }
        int max_ = -1, ans= 0;
        for (int i = 0; i<26; ++i) {
            if (max_<arr[i]){
                ans = i;
                max_ = arr[i];
            }
        }
        return 'a'+ ans;
}

//strlen(string) for length
//strcmp(s1, s2) to compare (=0 -->equal)
//strcpy(des str, src str) to copy

string replace_spaces(string s) {
    
    for (int i = 0; i<s.length(); ++i) {
        if (s[i]==' ') {
            s.replace(i, 1, "@40");//( start index to be replaced, number of replacement, string replaced by )
            i+= 3-1;            //(length of "@40") - 1
        }
    }

    return s;
}

string remove_Occ(string s, string part) {
    while ((s.length()!=0) && (s.find(part) < s.length())) {
        s.erase(s.find(part), part.length());
    }

    return s;
}

bool CheckInclusion(string s1, string s2) {        //true if s1 or its permuttions present in s2
    int count1[26] = {0};

    for( int i = 0; i<s1.length(); ++i) {
        count1[(int)(s1[i]-'a')]++;             //we now have count of all alphabets in str s1 
    }
    cout<<"Substring Count: "<<endl;
    PrintArr(count1, 26);

    //we now create a window of length that of s1 and traverse through s2.
    //we make another count2[26] for window and increment it accordingly
    //if count2 == count1 for window, return true

    int win_size = s1.length();
    for (int i = 0; i<s2.length(); ++i) {
        int count2[26] = {0};
        for (int j = i; j<(i+s1.length()); ++j) {
            count2[(int)(s2[j]-'a')]++;  
        }
        cout<<"Window Count: "<<i+1<<endl;
        PrintArr(count2,26);
        if (equal_arr(count1, count2)) {
            return 1;
        }
    }
    return 0;
}

string remove_adj_dupe(string s) {
    string temp;
    for(char ch: s) {
        if (temp.size()!=0 && temp[temp.size()-1] == ch)
            temp.pop_back();
        else 
            temp+=ch;
    }
    return temp;
}

int compress(vector<char>&chars) {
    vector<char>arr;
    int i = 0, index = 0;

    while(i<chars.size())  {
        int j = i + 1;
        while(j<chars.size() && (chars[i] == chars[j])) {
            j++;
        }
        int count = j - i;
        arr.push_back(chars[i]);
        index++;
        if(count>1) {
            string c = to_string(count);
            for( char ch:c) {
                arr.push_back(ch);
                index++;
            }
        }
        i = j;
    }
    chars = arr;
    return index;
}

int main() {

/*    char ch[20];
    cout<<"Enter a String:"<<endl;
    cin>>ch;

    cout<<"Entered String is: "<<ch<<endl;
    cout<<"Length of Entered String is: "<<len_str(ch)<<endl;
//    rev_str(ch, len_str(ch));
//    cout<<"Reversed String is: "<<ch<<endl;

    if (check_palindrome(ch)) {
        cout<<"Palindrome"<<endl;
    }
    else {
        cout<<"Not Palindrome"<<endl;
    }

    cout<<lowercase(ch);
//    rev_str(ch, len_str(ch));
//    cout<<ch;*/

//    string s;, part;
//    getline(cin, s);
//    getline(cin, part);
//    cout<<remove_adj_dupe(s);
    int n;
    cin>>n;
    vector<char>arr;
    MakeVec(arr, n);
    cout<<compress(arr);
    return 0;
}