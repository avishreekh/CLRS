#include <iostream>
#include <climits>
using namespace std;

void merge(int arr[], int l, int mid, int r);

void merge_sort(int arr[], int l, int r){
	if (l >= r){ return; }
	int mid = (l+r)/2;
	merge_sort(arr, l, mid);
	merge_sort(arr, mid+1, r);
	merge(arr, l, mid, r);
}

void merge(int arr[], int l, int mid, int r){
	int n1 = mid-l+1;
	int n2 = r-mid;
	
	int left[n1+1];
	int right[n2+1];
	
	int i,j,k;

	for(i=0; i<n1; i++){
		left[i] = arr[l+i];
	}
	for(j=0; j<n2; j++){
		right[j] = arr[mid+1+j];
	}

	left[i] = INT_MAX;
	right[j] = INT_MAX;
	i=0;
	j=0;

	for(k=l; k<=r; k++){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
	}
}

void print_array(int arr[], int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int &x : arr){ cin >> x; }
	merge_sort(arr, 0, n-1);
	print_array(arr, n);
}