c
#include <iostream>
#include <string>

using namespace std;

string compress(string s);


int main(int argc, char * argv[]) {

	if (argc != 2) {
		cerr << "Call with a string\n";
		exit(1);
	}


	cout << compress(argv[1]) << endl;

	return 0;

}




string compress(string s) {

	string compressed = "";

	int countRepeats = 1;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[i+1]) {
			countRepeats++;
		} else {
			compressed.push_back(s[i]);
			compressed = compressed + to_string(countRepeats);
			countRepeats = 1;
		}
	}

	if (s.length() > compressed.length()) 
		return compressed;
	else 
		return s;

}
