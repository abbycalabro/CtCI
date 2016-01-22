#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool oneAway(string str1, string str2) {
	int i;
	int diff = 0;

	if(str1 == str2)
		return true;
	//if same length, count char differences
	else if(str1.length() == str2.length()) {
		for(i = 0; i < str1.length(); i++) {
			if(str1[i] != str2[i])
				diff++;
		}	
	}
	//if length different by 1, count char differences
	else if(str1.length() - str2.length() == 1) {
		for(i = 0; i < str1.length(); i++) {
			if(str1[i] != str2[i] ) {
				if(diff == 0)
					diff++;
				if(str2[i] != str1[i + 1])
					diff++;
			}
		}
	}
	else if(str2.length() - str1.length() == 1) {
		for(i = 0; i < str2.length(); i++) {
			if(str1[i] != str2[i]) {
				if(diff == 0)
					diff++;
				if(str1[i] != str2[i + 1])
					diff++;
			}
		}
	}
	//length difference greater than 1
	else
		diff = -1;

	if(diff > 1 || diff == -1)
		return false;
	else
		return true;
}

int main(int argc, char* argv[]) {
	cout << "pale vs bale: " << oneAway("pale", "bale") << endl;
	cout << "pale vs ple: " << oneAway("pale", "ple") << endl;
	cout << "pale vs pales: " << oneAway("pale", "pales") << endl;
	cout << "pale vs bake: " << oneAway("pale", "bake") << endl;
	cout << "buny vs bunny: " << oneAway("buny", "bunny") << endl;
	cout << "buny vs bunnys: " << oneAway("buny", "bunnys") << endl;
	cout << "sunnys vs bunny: " << oneAway("sunnys", "bunny") << endl;
	cout << "bunny vs sunnys: " << oneAway("bunny", "sunnys") << endl;

	return 0;
}
