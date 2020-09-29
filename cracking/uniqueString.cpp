


#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool isUnique (string s); // sorting
bool unique (string s);


int main(int argc, char * argv[]) {

	if (argc != 2) {
		cerr << "Call with string.\n";
		exit(1);
	}

	if (unique(argv[1])) {
		cout << "This is unique.\n";
	} else {
		cout << "This is not unique.\n";
	}

	return 0;
}

// WITHOUT ADDITIONAL DATA STRUCTURE!
bool isUnique (string s) {

	sort(s.begin(), s.end());

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == s[i-1]) {
			return false;
		}
	}
	return true;
}


// with hash table
bool unique (string s) {

	map <char, int> m;

	for (int i = 0; i < s.length(); i++) {
		if (m.find(s[i]) != m.end()) {
			return false;
		} else {
			m.insert(pair<char, int> (s[i], 1));
		}
	}
	return true;

}