// C++ implementation for finding x^n recursively

#include <iostream>
using namespace std;

long long int power(long long x, long long n){
	if (n == 0){ return 1; }
	long long half_pow;
	half_pow = power(x, n/2);

	if(n & 1){ return half_pow*half_pow*x; }

	return half_pow*half_pow;
}

int main(){
	long long int x, n;
	cin >> x >> n;
	cout << power(x, n) << '\n';
}