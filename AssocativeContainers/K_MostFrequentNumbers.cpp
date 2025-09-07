#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int nums, freq_count;
	cout<<"Enter a nums: ";
	cin >> nums;
	cout << "Enter a frequent count: ";
	cin >> freq_count;

	int arr[nums];
	for(int i=0; i<nums; i++){
		int n;
		cin >> n;
		arr[i]=n;
	}

	unordered_map<int,int> freq;
    for(int x : arr) {
        freq[x]++;
    }
    vector<pair<int,int>> v;
	for(auto &[num, f] : freq){
		v.push_back({num, f});
	}

	sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b){
        return a.second > b.second; 
    });

    for(int i = 0; i < freq_count && i < v.size(); i++) {
        cout << v[i].first << " ";
    }
    cout << endl;


	return 0;
}
