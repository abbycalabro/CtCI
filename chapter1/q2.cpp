#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isPermutation(string str1, string str2) {
	int letters[128];
	int val, i;

	//check if string lengths match
	if(str1.length() != str2.length())
		return false;
	
	//set letters elements to 0
	for(i = 0; i < sizeof(letters) / sizeof(int); i++) {
		letters[i] = 0;
	}

	//iterate through str1, incrementing corresponding ascii value in letters[]
	for(i = 0; i < str1.length(); i++) {
		val = (int)str1[i];
		letters[val]++;
	}

	//iterate through str2, decrementing corresponding ascii value in letters
	for(i = 0; i < str2.length(); i++) {
		val = (int)str2[i];
		letters[val]--;
		//return false if char not in str1 found
		if(letters[val] < 0)
			return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	string str1 = "hello world";
	string str2 = "owolldreh l";
	string str3 = "not a match";
	string str4 = "world hello1";

	cout << "Perm strings should return 1: " << isPermutation(str1, str2) << endl;
	cout << "Non-perm strings should return 0: " << isPermutation(str1, str3) << endl;
	cout << "Strings with different lengths should return 0: " << isPermutation(str1, str4) << endl;

	return 0;
}
