#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> counting_sort_with_ranges(vector<int> a){
	int n = a.size();
	vector<int> b(n);

	int min = *min_element(a.begin(), a.end());
	int max = *max_element(a.begin(), a.end());
	int k = max - min;

	vector<int> c(k+1,0);

	for(int i=0; i<n; i++){ c[a[i]-min]++; }
	for(int i=0; i<=k; i++){ c[i] += c[i-1]; }
	for(int i=(n-1); i>=0; i--){
		b[c[a[i]-min]-1] = a[i];
		c[a[i]-min]--;
	}
	return b;
}

vector<int> counting_sort(vector<int> a, int k){
	int n = a.size();
	vector<int> b(n);
	vector<int> c(k+1, 0);
	for(int i=0; i<n; i++){ c[a[i]]++; }
	for(int i=0; i<=k; i++){ c[i] += c[i-1]; }
	for(int i=(n-1); i>=0; i--){
		b[c[a[i]]-1] = a[i];
		c[a[i]]--; 
	}
	return b;
}

void print_vector(vector<int> v){
	for(auto it=v.begin(); it != v.end(); it++){
		cout << *it << " ";
	}
	cout << '\n';
}

int main(){
	int n, k;

	//k = -1 indicates that the range needs to be found 
	cin >> n >> k;
	vector<int> a(n,0);

	for(int &x : a){ cin >> x; }

	vector<int> sorted_a;
	
	if(k == -1){
		sorted_a = counting_sort_with_ranges(a);
	}
	else { sorted_a = counting_sort(a, k); }
	
	print_vector(sorted_a);

	return 0;
}