#include <iostream>
#include <string>
using namespace std;

int main() {
	int size;
    cout << "Enter a size: ";
	cin >> size;

	string arr[size];
	for(int i=0; i<size; i++) {
		string el;
		cin >> el;
		arr[i]=el;
	}

	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(arr[i]==arr[j]){
				cout << arr[i] << endl;
				break;
			}
		}
	}

	
	return 0;
}
