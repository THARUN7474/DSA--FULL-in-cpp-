#include<bits/stdc++.h>
using namespace std;

int main(){
	string str = "hello";
	cout << str << endl;
	string str2 = "tharun";
	cout << str2 << endl;

	string str3;
	cin >> str3;//taking input string
	cout << str << str3 << endl;

	string result = str + str3;
	cout << result << endl;//concatinating


	if (str2 == str3){//comparing strings
		cout << "equal strings" << endl;
	}
	else{
		cout << "not equal strings"<< endl;
	}


	str[1]='a';//" " must not use while //indexing
	cout << str << endl;
	cout << str.size()<< endl;///size of string

	for( int i=0; i<str3.size(); ++i){
		cout << str3[i]<< endl;
	}

	string str4 , str5;
	cin >> str4 >> str5;
	cout << str4 << " "<< str5 << endl;

	//learn working of cin...buffers all that 
	//simply cin takes all up to new line or whitespace occurs 
	//cin stops when it is encoutred with whitespace or newline
	//but get line takes imeditate to the curser so here it is takig whitespace as input 
	//so use ignore fun or incress t value better to use ignore fun for cin
	// string str6;
	// getline(cin, str6);
	// cout << str6 << endl;
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin, s);
		cout << s << endl;
	}

	//write code for str_ reverse
	// 1 is to use loops and rewrite into new string 
	// or exhange 1st and last untill it gets middle 
	//better dont add char to string more often
	//loops using more takes so much time 
	// use str.push_back(str[i]) fun //O(1)
	// palendrome code 

	// code yourself do problems given 

	// and to take large numbers given as input use string instead of double or long long
	string ss;
	cin >> ss;
	cout << int(ss[ss.size()-1]) << endl;//normal indexing method
	int last_digit = ss[ss.size()-1]-'0';//using ascii values
	cout << last_digit << endl;
}