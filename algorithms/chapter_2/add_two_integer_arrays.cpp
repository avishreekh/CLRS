#include <iostream>
using namespace std;

void add_two_num(int a[], int b[], int c[], int n){
	int carry = 0;
	int sum = 0;
	for(int i=(n-1); i>=0; i--){
		
		c[i+1] = a[i] + b[i] + carry;
		carry = 0;

		if(c[i+1] >= 2){
			c[i+1] = ((c[i+1] == 2) ? 0 : 1);
			carry = 1;
		}
	}
	c[0] = carry;
}

void print_array(int arr[], int n){
	for(int i=0; i<n; i++){ cout << arr[i] << " "; }
	cout << '\n';
}

int main(){
	int n;
	cin >> n;
	int a[n], b[n];
	for(int &x : a){ cin >> x; }
	for(int &x : b){ cin >> x; }
	int c[n+1];
	add_two_num(a, b, c, n);
	print_array(c, n+1);
}