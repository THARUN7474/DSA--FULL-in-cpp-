#include<bits/stdc++.h>

using namespace std;

int main(){
	//arrays
	// int a[10];
	//index access from 0 ----n
	//if index is morethan n-1 ===give segmentation error
	// a[0]= 100;
	// cout << a[0];

	int n;
	cin>>n;
	int a[n];
	int sum =0;
	for(int i =0;i<n;i++){
		cin>>a[i];
		sum = sum+a[i];
	}

	cout<<"sum is "<< sum;

	//datatype var[size]----syntax
	int m;
	cin>>m;
	char b[n], b1[n];//char array----more usefull string not char array
	//more use vectors than this

	//2d array
	int p,q;
	cin>>p>>q;
	int a2[p][q];

	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			cin >> a2[i][j];
		}
	}

	cout<<"the matrix is";
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < q; ++j)
		{
			cout<<a2[i][j]<<" ";
		}
		cout<<endl;
	}

	//array sizes are not so large it has limit --memory allocation limit gets 
	//almost 10^5 is maxm size to keep---1e5
	//if size increses like size = 1e7 then give segmentation error
	//all above in main() fun or in any local scope

	//in global scope but delacre it as const int n = 1e7 and do 

	//why because it is not in stack memory it is in heap memory so we can use it
	//but in local scope it is in stack memory so we cant use it-----it is fixed size depends on architecture of system
	//so we can use it in global scope or heap memory-like using new int[n] or malloc() in c++---> more over like data segment --we statically declare it 
	//or use vector<int> a(n) or vector<int> a(n,0) to keep all 0s in it
	//or use vector<int> a(n,1) to keep all 1s in it
}