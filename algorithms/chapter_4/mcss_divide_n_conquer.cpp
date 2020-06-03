#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct elements{
	int min_id;
	int max_id;
	int sum;
};

elements mcss_crossing(vector<int> v, int l, int mid, int r);
elements mcss(vector<int> v, int l, int r);

elements mcss(vector<int> v, int l, int r){
	if (l == r){ 
		elements e = {l,r,v[l]};
		return e;
	}

	elements e_l, e_r, e_mid;
	int mid = (l+r)/2;
	
	e_l = mcss(v, l, mid);
	e_r = mcss(v, mid+1, r);
	e_mid = mcss_crossing(v, l, mid, r);

	if ((e_l.sum >= e_r.sum) && (e_l.sum >= e_mid.sum)){ return e_l; }
	if (e_r.sum >= e_mid.sum){ return e_r; }
	return e_mid;
}

elements mcss_crossing(vector<int> v, int l, int mid, int r){
	int left_sum = INT_MIN, right_sum = INT_MIN;
	int left_id, right_id;
	int sum = 0;

	for(int i=mid; i>=l; i--){
		sum += v[i];
		if(sum > left_sum){
			left_sum = sum;
			left_id = i;
		}
	}

	sum = 0;
	for(int i=(mid+1); i<=r; i++){
		sum += v[i];
		if(sum > right_sum){
			right_sum = sum;
			right_id = i;
		}
	}

	elements e = {left_id, right_id, left_sum+right_sum};
	return e;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	for(int &x : v){ cin >> x; }
	elements ele = mcss(v,0,(n-1));
	cout << "Left id: " << ele.min_id << " | Right id: " << ele.max_id << " | Sum: " << ele.sum << '\n';
	return 0;
}