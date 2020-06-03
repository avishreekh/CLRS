#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int merge(vector<int>& v, int l, int mid, int r){
	int inversions = 0;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int left[n1+1];
	int right[n2+1];
	for(int i=0; i<n1; i++){
		left[i] = v[l+i];
	}
	for(int i=0; i<n2; i++){
		right[i] = v[mid+1+i];
	}

	left[n1] = INT_MAX;
	right[n2] = INT_MAX;

	int i=0, j=0;
	for(int k=l; k<=r; k++){
		if(left[i] <= right[j]){
			v[k] = left[i];
			i++;
		}
		else{
			v[k] = right[j];
			j++;
			inversions += (n1 - i);
		}
	}
	return inversions;
}

int mergesort(vector<int>& v, int l, int r){
	int inversions = 0;
	if (l >= r){ return 0; }

	int mid = (l+r)/2;

	inversions += mergesort(v, l, mid);
	inversions += mergesort(v, mid+1, r);
	inversions += merge(v, l, mid, r);
	return inversions;
}

int count_inversions(vector<int> v){
	vector<int> temp; //we don't want to sort the original array so create a temporary array
	for(int i : v){ temp.push_back(i); }
	
	int inversions = mergesort(temp, 0, temp.size()-1);
	
	return inversions;
}


int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	for(int &x : v){ cin >> x; }
	int inversions = count_inversions(v);
	cout << inversions << '\n';
	return 0;
}