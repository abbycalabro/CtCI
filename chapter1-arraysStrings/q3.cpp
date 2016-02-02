#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void URLify(string str, int trueLength) {
	int newLength = str.length();
	string copy(str.length(), ' ');
	
	for(int i = trueLength - 1; i >= 0; i--) {
		if(str[i] == ' ') {
			copy[newLength - 1] = '0';
			copy[newLength - 2] = '2';
			copy[newLength - 3] = '%';
			newLength -= 3;
		}
		else {
			copy[newLength - 1] = str[i];
			newLength--;
		}
	}
	cout << "URLified string: " << copy << endl;
}


int main(int argc, char* argv[]) {
	string str = "oh hello there!    ";
	int trueLength = 15;

	URLify(str, trueLength);

	return 0;
}
