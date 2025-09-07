#include <iostream>
#include <set>
#include <vector>
using namespace std;


int main(){
	int size;
	cout << "Enter a size: ";
	cin >> size;

	set<int> nums;
	for(int i=0; i<size; i++){
		int n;
		cin >> n;
		nums.insert(n);
	}

	int MaxLength=0;
	for(auto it=nums.begin(); it!=nums.end(); it++){
		int num=*it;
		int current=num;
		int length=1;
		while(nums.find(current + 1) != nums.end()){
			current++; length++;
		}
 	MaxLength = max(length, MaxLength);
	}
	cout << "Max length is: " << MaxLength << endl;
	return 0;
}
