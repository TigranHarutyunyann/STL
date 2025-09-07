#include <iostream>
#include <set>
using namespace std;

int main() {
	int size;
	cout << "Enter a size: ";
	cin >> size;
		
    set<int> mm;
	cout << "Enter a elements: ";
	for(int i=0; i<size; i++){
		int n;
		cin >> n;
		mm.insert(n);
	}
	cout << "Size is: "  << mm.size();
    
    return 0;
}
