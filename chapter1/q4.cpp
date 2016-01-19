#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool isPalindromePermutation(string str) {
	int alphabet[128], val, i;
	int odds = 0;
	int newLength = 0;

	//set array vals to 0
	for(i = 0; i < sizeof(alphabet) / sizeof(int); i++) {
		alphabet[i] = 0;
	}

	//count # of each char in string and track odd counts
	for(i = 0; i < str.length(); i++) {
		if(str[i] != ' ') {
			newLength++;
			val = (int)str[i];
			alphabet[val]++;

			if(alphabet[val] % 2 == 0)
				odds--;
			else
				odds++;
		}
	}

	//even length strings should have 0 odd counts, odd length strings should have exactly 1
	if(newLength % 2 == 0) {
		if(odds > 0)
			return false;
	}
	else {
		if(odds > 1)
			return false;
	}
	return true;
}

int main(int argc, char* argv[]) {
	string oddCaseTrue = "taco cat";
	string oddCaseFalse = "taco cats";
	string evenCaseTrue = "ab c abc";
	string evenCaseFalse = "ab c ab d";

	cout << "oddCaseTrue should return 1: " << isPalindromePermutation(oddCaseTrue) << endl;
	cout << "oddCaseFalse should return 0: " << isPalindromePermutation(oddCaseFalse) << endl;
	cout << "evenCaseTrue should return 1: " << isPalindromePermutation(evenCaseTrue) << endl;
	cout << "evenCaseFalse should return 0: " << isPalindromePermutation(evenCaseFalse) << endl;

	return 0;
}
