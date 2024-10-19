#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {

//ARRAY

/*Create array*/    array<int,4>arr = {1, 2, 3, 4};
/*Size of array*/    int size = arr.size();

    for (int i = 0; i<size; ++i) {
        cout<<arr.at(i)<<endl;    /*Index access*/
    }
    /*1st element--> .front()
      Last element--> .back()*/


//VECTOR

//Vector is a dynamic O(1) array. If vector has all elements defined and we add on another element,
//vector doubles its size(capacity) by creating a new vector double its size(capacity)
//followed by transporting all elements to bigger vector, replacing older one.
//capacity: 1-->2-->4...
//functions similar to array: front, end, at


    vector<int>v;   //initially zero capacity
    vector<int>a(5, 1); //size:5; all elements are "1"
    v.push_back(1);  //add element "1"
    v.push_back(2);
    v.push_back(3); 
    cout<<"Capacity: "<<v.capacity()<<endl;   //capacity of vector
    cout<<"Size: "<<v.size()<<endl;   //size of vector
    v.pop_back();   //delete last element
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    v.clear();  //size:0; capacity: retained


//DEQUE

//dynamic O(1) just like a vector, however insertion & deletion possible at both ends
//elements are stored in non-contiguous memory blocks.


    deque<int>d;
    //.push_back(ele); .push_front(ele); .pop_back(); .pop_front(); at(index);
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5); //deque: 1 2 3 4 5

    d.erase(d.begin());//deque: 3 4 5 //ele erased from startvalue index to (endvalue-1) index
    //size:0; capacity: retained. If end value not specifies, only start value erased.
    for (int i:d) {
        cout<<i<<" ";
    }


//LIST

//O(1)
//Doubly linked list where elements are scattered in memory with pointers linking them.



    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    list<int>n(l);  //copied list l in list n



//STACK AND QUEUE

//STACK-Last in First out
//O(1)
//QUEUE-First in First out

    stack<string>s;
    s.push("first");
    s.push("second");
    s.push("third");
    cout<<"Top ele: "<<s.top()<<endl;
    s.pop();
    cout<<"Top ele: "<<s.top()<<endl;


    queue<string>q;
    q.push("first");
    q.push("second");
    q.push("third");
    cout<<"First ele: "<<q.front()<<endl; 
    q.pop();
    cout<<"First ele: "<<q.front()<<endl;

//Priority Queue
    //max heap
    priority_queue<int>max;
    //min heap
    priority_queue<int, vector<int>, greater<int>>min;


    max.push(1);
    max.push(4);
    max.push(2);
    max.push(3);

    min.push(1);
    min.push(4);
    min.push(2);
    min.push(3);

    int size2 = max.size();
    for (int i = 0; i<size2; i++) {
        cout<<max.top()<<" ";     
        max.pop();
    }       //4 3 2 1
    cout<<endl;

    for (int i = 0; i<size2; i++) {
        cout<<min.top()<<" ";     
        min.pop();
    }       //1 2 3 4
    cout<<endl;


//SET

    set<int>set1;

    set1.insert(3);
    set1.insert(1);
    set1.insert(4);
    set1.insert(5);
    set1.insert(2);        //O(logn)
    set1.insert(1);
    set1.insert(4);

    for(auto i:set1) {
        cout<<i<<" ";
    }       //sorted- 1 2 3 4 5
    cout<<endl;
    set<int>::iterator it = set1.begin();
    set1.erase(it);

    for(auto i:set1) {
        cout<<i<<" ";
    }       //2 3 4 5
    cout<<endl;
    //s.count(value), returns 1 is value is present, otherwise 0
    set<int>::iterator itr = set1.find(4);
    cout<<"Value at itr: "<<*itr<<endl;


//MAP

//insert, erase, count for Map---> O(logn)


    map<int, string>m;  //sorted
    m[1]="Me";
    m[6]="Them";
    m[2]="You";
    m.insert({5,"Him"});
    for (auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;     //1   2   5    6
                                                //me you him them
    }

    cout<<"find 5:"<<m.count(5)<<endl;  //1-->true, 0-->false

    m.erase(6);

    for (auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;     //1   2   5  
                                                //me you him 
    }
    cout<<endl;
    auto it2 = m.find(5);

    for(auto i=it2; i!=m.end(); i++) {
        cout<<(*i).first<<" ";
    }
    cout<<endl;


//ALGORITHM

    vector<int>v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(5);
    v2.push_back(7);
    v2.push_back(11);

    cout<<"If 5 is present: "<<binary_search(v2.begin(), v2.end(), 5)<<endl;
    cout<<"Lower Bound for 3: "<<lower_bound(v2.begin(), v2.end(), 3)-v2.begin()<<endl;
    cout<<"Upper Bound for 3: "<<upper_bound(v2.begin(), v2.end(), 3)-v2.begin()<<endl;

    //min(a, b); max(a, b); swap(a, b); reverse(string.begin(), string.end())
    //rotate(vector.begin(), vector.begin()+1, vector.end())
    //              start           middle          end
    //                        =extent of rotation
    //sort(vector.begin(), vector.end())---> based on intro sort(quick sort + insertion sort + heap sort)

    return 0;
}