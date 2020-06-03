#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct elements{
	int min_id;
	int max_id;
	int sum;
};

elements mcss(vector<int> v){
	int max_sum = INT_MIN;
	int sum = 0;
	int left_id, right_id;
	int curr_left = 0;

	for(int i=0; i<v.size(); i++){
		sum += v[i];
		if (sum > max_sum){
			max_sum = sum;
			left_id = curr_left;
			right_id = i;
		}
		if (sum < 0){
			sum = 0;
			curr_left = i+1;
		}
	}

	elements e = {left_id, right_id, max_sum};
	return e;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	for(int &x : v){ cin >> x; }

	elements ele = mcss(v);
	cout << "Left id: " << ele.min_id << " | Right id: " << ele.max_id << " | Sum: " << ele.sum << '\n';
	
	return 0;
}