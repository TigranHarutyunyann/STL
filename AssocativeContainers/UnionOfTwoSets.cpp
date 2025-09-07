#include <iostream>
#include <set>
using namespace std;

int main() {
    int sizeSet1;
	cout << "enter a size of set one: ";
	cin >> sizeSet1;

	set<int> FirstSet;

	for(int i=0; i <sizeSet1; i++){
		int tmp;
		cin >> tmp;
		FirstSet.insert(tmp);
	}

    int sizeSet2;
	cout << "enter a size of set one: ";
	cin >> sizeSet2;

	for(int i=0; i <sizeSet2; i++){
		int tmp;
		cin >> tmp;
		FirstSet.insert(tmp);
	}

	cout << "Size is: " << FirstSet.size() << endl;
	return 0;
}
