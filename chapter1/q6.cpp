#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string compressedString(string str) {
	string newStr = "";
	char currentChar = str[0];
	int count = 0;

	for(int i = 0; i < str.length(); i++) {
		//if same consecutive char and not end of str
		if(str[i] == currentChar && i != str.length() - 1)
			count++;
		else {
			//if end of str
			if(i == str.length() - 1) {
				newStr += currentChar + to_string(++count);
			}
			//else append char and count to newStr, update currentChar and count
			else {
				newStr += currentChar + to_string(count);
				currentChar = str[i];
				count = 1;
			}
		}
	}

	if(newStr.length() > str.length())
		return str;
	else
		return newStr;
}

int main(int argc, char* argv[]) {
	string ans1 = compressedString("aabcccccaaa");
	string ans2 = compressedString("aBcDEffG");

	cout << "compressedString('aabcccccaaa') should return a2b1c5a3: " << ans1 << endl;
	cout << "compressedString('aBcDEffG') should return original string: " << ans2 << endl;	

	return 0;
}
