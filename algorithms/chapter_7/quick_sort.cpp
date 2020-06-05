#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int> &v, int l, int r){
	int key = v[r];
	int low_id = l-1; 	//index of lower element
	int temp;

	for(int i=l; i<r; i++){
		if(v[i] <= key){
			low_id++;
			temp = v[low_id];
			v[low_id] = v[i];
			v[i] = temp;
		}
	}

	low_id++;
	v[r] = v[low_id];
	v[low_id] = key;
	
	return low_id;
}

void quicksort(vector<int> &v, int l, int r, bool randomized){
	if (l >= r){ return; }
	
	if (randomized){
		srand(time(NULL));
		int rnum = l + rand()%(r-l);
		int temp = v[rnum];
		v[rnum] = v[r];
		v[r] = temp;
	}

	int pivot = partition(v, l, r);
	
	quicksort(v, l, pivot-1, randomized);
	quicksort(v, pivot+1, r, randomized);
}

void print_vector(vector<int> v){
	for(int i=0; i<v.size(); i++){ cout << v[i] << " "; }
	cout << '\n';
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	for(int &x : v){ cin >> x; }

	bool randomized;

	cout << "Use randomized algorithm? (0/1): ";
	cin >> randomized;

	quicksort(v, 0, n-1, randomized);
	print_vector(v);

	return 0;
}