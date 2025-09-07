#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){

    int size;
	cout << "Enter a size: ";
	cin >> size;

	map<string, int> fruits;

	string arr[size];
	for(int i=0; i<size; i++){
		string fruit;
		cin >> fruit;
		arr[i]=fruit;
	}

	for(int i=0; i<size; i++){
		int count=0;
		for(int j=0; j<size; j++){
			if(arr[i]==arr[j]){
				count++;	
			}
		}
		fruits.insert({arr[i], count});
	}

	for(auto it : fruits){
		cout << it.first << " " << it.second << endl;
	}
	
	return 0;
}
