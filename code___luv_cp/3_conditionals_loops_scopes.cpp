#include<bits/stdc++.h>
// #include<iostream.h>

using namespace std;

int A;//global var anywhere we can use 

int main(){

	int a = 2;
	int b= 3;
	int c = 4;
	cout << ((a < b) && (b > c)) << endl;
	cout << ((a < b) || (b > c)) << endl;

	//if conditions
	int n;
	cin >> n;
	if (n%2 == 0){
		int x;//local var it is only valid in this if section ---local scope
		cout << "YES" << endl;
	}
	//outside we cant use x it throws error...scope means inside { brackets only}
	else if (n%3 ==0){
		cout << "by 3 it is divisible"<< endl;
	}
	else{
		cout << "NO"<< endl;
	}

	//loops
	int i = 1;
	while(i<=10){
		cout << i << endl;
		i++;
	}

	
	// for(;;) is also valid 
	for (int i=1; i<=10; ++i){
		cout << i << endl;
		//here i scope is inside {means local we can use i later too }
	}
	int t;
	cin >> t;
	for( int test =0; test<t; ++test){
		int nn;
		cin >> nn;
		for (int i=1; i<=nn; ++i){
			for(int j=1; j<=i; ++j){
				if (j == 6){
					continue;
				}
				cout << "*";
			}
			cout << endl;
		}
	}
	while(t--){
		int nn;
		cin >> nn;
		for (int i=1; i<=nn; ++i){
			for(int j=1; j<=i; ++j){
				if (j==2){
					break;//comes out of this for loop(inner loop will get exit )no effect on if else conditions 
				}
				cout << "*";
			}
			cout << endl;
		}
	}
	// while(true){
	// 	int y;
	// 	cin >> y;
	// 	if(y == 42){
	// 		break;
	// 	}
	// 	cout << y << endl;
	// }//stops when it gets 42 as input 
	// used more this while making games type codes

	int z;
	cin >> z;
	int sum=0;
	cout << z << "is now number" <<endl;
	while(z>0){
		sum = sum + z%10;
		z=z/10;
		cout << z << "is now number" <<endl;
	}
	cout << sum <<" is total sum"<< endl;
	
}