#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string str1, string substring) {
	if(str1.find(substring) != string::npos)
		return true;
	else
		return false;
}	

bool isRotation(string str1, string str2) {
	//check that string lengths are equal and strings are not empty
	if(str1.length() == str2.length() && str1.length() > 0) {
		if(isSubstring(str2 + str2, str1))
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(int argc, char* argv[]) {
	cout << "Rotation should return 1: " << isRotation("abby", "bbya") << endl;
	cout << "Rotation should return 1: " << isRotation("waterfall", "llwaterfa") << endl;
	cout << "Non-rotation should return 0: " << isRotation("abby", "bbay") << endl;
	cout << "Strings of different length should return 0: " << isRotation("abby", "bbyay") << endl;

	return 0;
}
