#include <iostream>
using namespace std;

void selection_sort(int arr[], int n){
	int min_id, temp;

	for(int i=0; i<(n-1); i++){
		min_id = i;
		for(int j=(i+1); j<n; j++){
			if(arr[j] < arr[min_id]){ min_id = j; }
		}
		temp = arr[min_id];
		arr[min_id] = arr[i];
		arr[i] = temp;
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
	selection_sort(arr, n);
	print_array(arr, n);
}