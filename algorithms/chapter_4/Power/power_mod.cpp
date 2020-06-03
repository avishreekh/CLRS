// [Modular Exponentiation] C++ implementation for finding (x^n) % p 

#include <iostream>
using namespace std;

long long power_iterative(long long x, long long n, long long p){
	x = x % p;

	if(x == 0){ return 0; }

	long long pow = 1;

	while(n > 0){
		if (n & 1){ pow = ((pow % p) * (x % p)) % p; }
		n = n >> 1;
		x = ((x % p) * (x % p)) % p;
	}

	return pow;
}

long long power_recursive(long long x, long long n, long long p){
	if (n == 0){ return 1; }

	long long half_pow = power_recursive(x, n/2, p);
	long long half_pow_mod = ((half_pow % p) * (half_pow % p)) % p;
	
	if(n & 1){ return (half_pow_mod * (x % p)) % p ;}
	
	return half_pow_mod;
}

int main(){
	long long x, n, p;
	cin >> x >> n >> p;

	cout << power_iterative(x, n, p) << '\n';
	cout << power_recursive(x, n, p) << '\n';

	return 0;
} 