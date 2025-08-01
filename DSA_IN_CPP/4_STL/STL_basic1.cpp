#include <bits/stdc++.h>

using namespace std;

void nl()
{
    cout << "\n";
}

// The C++ Standard Template Library (STL) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks. It provides four components called 
// algorithms, containers, functions, and iterators. 

// Containers in C++
 

// The Containers Library in STL  is a holder object that stores a collection of other objects, which in simplest words can be described as the objects used to contain data or rather a collection of objects, and it allows great flexibility in the types supported as elements. The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators. Some container classes are vector, list, forward_list, queue, priority_queue, stack, set, multiset, map, multimap, unordered_set.

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

void learnpair()
{

    pair<int, int> p = {1, 3};

    cout << p.first << " " << p.second << endl;

    pair<int, string> p1 = {1, "hello"};

    cout << p1.first << " " << p1.second << endl;

    pair<int, string> p2 = make_pair(1, "hello");

    cout << p2.first << " " << p2.second << endl;

    pair<int, pair<int, int>> p3 = {1, {1, 2}};
    cout << p3.first << " " << p3.second.first << " " << p3.second.second << endl;

    pair<float, float> pr[] = {{1, 2}, {1.1, 2.3}, {1.22, 1.33}};
    for (int i = 0; i < 3; i++)
    {
        cout << pr[i].first << " " << pr[i].second << endl;
    }
}

void learnvector(){
        vector<int> v1;

    vector<int> v2(6);

    vector<int> v3(v2.begin(),v2.end()-1);

    vector<int> v4{1,2,3,4,5,6,7,8,9,10};

    vector<int> v5(5,100);

    vector<int> v6(v5);


    for(auto it : v6){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> v7 = {1,2,3,4,5,6,7};
    vector<int>::iterator it = v7.begin();//iterater 
    vector<int>::iterator it2 = v7.end();//iterater 
    // vector<int>::iterator it3 = v7.rbegin();//iterater 
    // vector<int>::iterator it4 = v7.rend();//iterater 

    // even though we access by v[i]
    //iteraters points to the memory location of the data

    it++;
    cout<< *(it) << " "<<endl;

    it = it + 2;//move according to memory wise 

    cout<< *(it) << " "<<endl;
    vector<int> v;

    cout<< v.front()<<endl;
    cout<< v.back()<<endl;
    cout<< v.size()<<endl;
    cout<< v.capacity()<<endl;
    cout<< v.max_size()<<endl;
    cout<< v.empty()<<endl;
    cout<< v.data()<<endl;
    cout<< v.at(2)<<endl;
    cout<< v[2]<<endl;

    for(vector<int>::iterator it = v.begin(); it != v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(auto it = v.begin(); it != v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    for(auto it : v){
        cout<<it<<" ";//auto ---automatically asssign datatype accordingly
    }
    cout<<endl;//this is normal not iterator one 


    v.erase(v.begin());

    v.erase(v.begin(),v.begin()+2);

    // v.erase(v.begin()+5);

    // v.clear();//empty's complete vector

    // v.insert(v.begin(),5);
    // v.insert(v.begin()+2,5);
    // v.insert(v.begin()+1,2,4);//at where start , no of elements to insert , element to insert

    // vector<int>  c{30,300};
    // v.insert(v.begin(),c.begin(),c.end());
    
    // v.assign(v.begin(),v.end());

    vector<int> vv{1,2};
    vector<int> vvv;
    vvv.assign(vv.begin(),vv.end());
    for(auto it: vvv){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> vv1 = {3,4};

    for(auto it: vv){
        cout<<it<<" ";
    }
    cout<<endl;

    vv1.swap(vv);

    for(auto it: vv){
        cout<<it<<" ";
    }
    cout<<endl;


    vv.pop_back();
}

void learnlist(){
    list<int> l1;

    list<int> l2(6);

    list<int> l3(l2.begin(),l2.end());

    list<int> l4{1,2,3,4,5,6,7,8,9,10};

    list<int> l5(5,100);

    list<int> l6(l5);

    for(auto it : l6){
        cout<<it<<" ";
    }
    cout<<endl;

    l6.pop_back();
    l6.push_back(1);
    l6.pop_front();
    l6.push_front(2);
    l6.emplace_back(22);
    l6.emplace(l6.begin(),22);

    // rest operations are same as vector all_of
    // begin , end , rend, rbegin, insert, erase, swap, clear----
}

void learnDequeue(){
    deque<int> dq;
    deque<int> dq1(6);
    deque<int> dq2(dq1.begin(),dq1.end());
    deque<int> dq3{1,2,3,4,5,6,7,8,9,10};
    deque<int> dq4(5,100);
    deque<int> dq5(dq4);
    for(auto it : dq5){
        cout<<it<<" ";
    }
    cout<<endl;
    dq5.pop_back();
    dq5.push_back(1);
    dq5.pop_front();
    dq5.push_front(2);
    dq5.emplace_back(22);
    dq5.emplace(dq5.begin(),22);
    dq5.insert(dq5.begin(),5);
    dq5.erase(dq5.begin());
    dq5.erase(dq5.begin(),dq5.begin()+2);
    dq5.clear();
    dq5.assign(dq5.begin(),dq5.end());
    dq5.swap(dq5);
    dq5.resize(10);
    dq5.resize(10,100);
    dq5.shrink_to_fit();
    dq5.emplace_front(1);
    dq5.emplace_back(2);
    dq5.emplace(dq5.begin(),1);
    dq5.back();
    dq5.front();
    // rest operations are same as vector all_of
    // begin , end , rend, rbegin, insert, erase, swap, clear----
}


void learnstack(){
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.size();
    S.top();
    S.empty();
    S.pop();
    S.emplace(1);
    // LIFO PRINICIPLE FOLLOWED 
}

void learnqueue(){
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.size();
    Q.front();
    Q.back();
    Q.empty();
    Q.pop();
    Q.emplace(1); 
    // FIFO PRINICIPLE FOLLOWED
}

void learnPriorityQueue(){
    priority_queue<int> pq;
    pq.push(1);//{1}
    pq.push(2);//{2,1}
    pq.push(30);//{30,2,1}
    pq.push(4);
    pq.emplace(1);
    //in comments add the following priority queue how it will be 
    pq.size();
    pq.top();
    pq.empty();
    pq.pop();
    pq.emplace(1);
    // max heap is used by default 
    // min heap can be created by passing greater<int>() as second argument to constructor

    priority_queue<int , vector<int> , greater<int>()> mpq;
    // min heap can be created by passing less<int>() as second argument to constructor
    //add more data here ---or methods and at last give me time complexity things too
}


void learnset(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.emplace(1);
    s.emplace(2);
    s.emplace(3);
    s.find(6);
    s.erase(6);
    s.clear();
    auto it = s.find(2);
    s.erase(it);
    auto it2 = s.find(3);
    s.erase(it,it2);
    // begin , end , rend, rbegin, insert, erase, swap, clear----
    // all other ways 

    // auto it = s.lower_bound();
    // auto it = s.upper_bound();
    // auto it = s.equal_range();
    //add more data here ---or methods and at last give me time complexity things too

}