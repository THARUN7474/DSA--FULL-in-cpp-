#include<bits/stdc++.h>
using namespace std;

int main(){
	cout << 7/2 << endl;
	cout << 7/2.0 << endl;
	int a =3/2.0;  
	double b =3/2;  
	cout << a << endl;
	cout << b << endl; 
	



	//precedence matter
	// double> float> long long int> long int> int > char
	cout << 'c'+1 << endl;

	//check operator precidence  and associavity
	cout << 3*7/2 << endl;

	// int,char, long int, long long int, float, double;
	// -10^9 < int < 10^9
	// -10^12 < long int < 10^12
	// -10^18< long long int < 10^18
	//rough ranges to remb
	int A = 100000;
	int B = 100000;
	int C = A*B;//WONT GIVE DESIRED ANSWER HERE 
	long long int c = A * 1LL * B;//to store that much big output use that type only so for that a short trick like keeping 1ll so that high priority so it will be returned to this type
	cout << C << endl;
	cout << c << endl;
	cout << int(INT_MAX) << " "<<int(INT_MIN) << endl;
	cout << int(LONG_MAX) << " "<<int(LONG_MIN) << endl;
	cout << int(LONG_LONG_MAX) << " "<<int(LONG_LONG_MIN) << endl;
	// cout << INT_MAX +1 <<endl;
	//over flow means we get cycle repated -214783647 to 214783647 is cycle means if we add 1 to intmax we get -214783647 as output
	//means cycle repeated 
	//so we remb range adn we use better form like for int we may use long long int like that
	double e = 100000;
	double f = 100000;
	double d = e*f;
	cout << d <<endl;cout << d <<endl;
	//to remove e form scientific notation
	cout << fixed<<d <<endl;
	cout << fixed<< setprecision(1)<<d <<endl;
	//using double is ok but it is not accurate as see below
	double x = 1e24;// 10 ^24 
	cout <<x <<endl;
	cout << fixed<<x <<endl;
	//like this we get precision errors so try to avoid using float double for storing large values as we loose precison and accuracy
	//checkout out alternative--using strings?
	


	//to print area of rectable with constrants
	int ll,bb;
	cin >> ll >> bb;
	// int area = ll *bb will work for basic inputs but not like having contraints 1 < ll <10^9 like this long ....causes overflow problems
	long long int area = ll * 1ll * bb;//this is correct solution or change int of ll,bb to long long int
	cout<< area << endl;
}