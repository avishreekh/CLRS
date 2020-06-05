#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int random_partition(vector<int> &v, int l, int r){
	srand(time(NULL));
	int rnum = l + rand()%(r-l);
	int temp = v[rnum];
	v[rnum] = v[r];
	v[r] = temp;

	int key = v[r];
	int low_id = l-1; 	//index of lower element
	
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

int randomized_select(vector<int> &v, int l, int r, int i){
	if(l == r){ return v[l]; }
	int pivot = random_partition(v, l, r);
	int k = pivot - l + 1;
	if(k == i){ return v[pivot]; }
	if(k > i){ return randomized_select(v, l, pivot-1, i); }
	return randomized_select(v, pivot+1, r, i-k);
}

int main(){
	int n, i;
	cin >> n >> i;
	vector<int> v(n+1,0);
	for(int i=1; i<=n; i++){ cin >> v[i]; }
	// for(int &x : v){ cin >> x; }
	int i_th_statistic = randomized_select(v, 1, n, i);
	cout << i_th_statistic << '\n';
	return 0;
}