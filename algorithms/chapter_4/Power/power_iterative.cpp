// C++ implementation for finding x^n iteratively

#include <iostream>
using namespace std;

int main(){
	long long x, n;
	cin >> x >> n;
	
	long long pow = 1;

	while(n > 0){
		if(n & 1){ pow *= x; }
		n = n >> 1;
		x = x*x;
	}

	cout << pow << '\n';
	return 0;
}