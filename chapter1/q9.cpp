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
	if(str1.length() == str2.length()) {
		for(int	i = 0; i < str1.length(); i++) {
			if(str1[i] != str2[i]) {
				if(isSubstring(str2 + str2, str1))
					return true;
				else
					break;
			}
		}	
	}
	return false;
}

int main(int argc, char* argv[]) {
	cout << "Rotation should return 1: " << isRotation("abby", "bbya") << endl;
	cout << "Rotation should return 1: " << isRotation("waterfall", "llwaterfa") << endl;
	cout << "Non-rotation should return 0: " << isRotation("abby", "bbay") << endl;
	cout << "Strings of different length should return 0: " << isRotation("abby", "bbyay") << endl;

	return 0;
}
