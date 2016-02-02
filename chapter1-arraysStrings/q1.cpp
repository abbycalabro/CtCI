//Time complexity O(n), where n = length of the string
//Solution on pg 192

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

bool isUnique(string input) {
	bool char_arr[128];
	int ascii_val;

	//set all array vals false
	for(int i = 0; i < sizeof(char_arr); i++) {
		char_arr[i] = false;
	}

	for(int i = 0; i < input.length(); i++) {
		ascii_val = (int)input[i];

		if(char_arr[ascii_val]) {
			return false;
		}	
		char_arr[ascii_val] = true;
	}
	return true;
}


int main() {
	string unique = "abcde";
	string dup = "Abby";

	cout << unique << " should return 1: " << isUnique(unique) << endl;
	cout << dup << " should return 0: " << isUnique(dup) << endl;

	return 0;
}
