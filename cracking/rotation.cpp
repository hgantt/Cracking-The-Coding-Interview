#include <iostream>
#include <string>
using namespace std;

bool rotation(string s1, string s2);

int main (int argc, char * argv[]) {

	if (argc != 3) {
		cout << "fix\n";
		exit(1);
	}


	if (rotation(argv[1], argv[2]))
		cout << "Yes\n";
	else
		cout << "No\n";

	return 0;


}



bool rotation(string s1, string s2) {

	string x = "";

	size_t i = 0;

	for (i = 0; i < s2.length(); i++) {
		// is everything to the right of s2[i] is a substring of s1
		if (s1.find(s2.substr(i, s2.length() - i)) != std::string::npos) {
			x = s2.substr(i, s2.length() - i);
			break;
		}
	}

	x = x + s2.substr(0, i);

	cout << x << endl;

	if (x == s1) return true;
	return false;

}