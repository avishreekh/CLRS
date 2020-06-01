#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
	int key, j;
	for(int i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
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
	insertion_sort(arr, n);
	print_array(arr, n);
}