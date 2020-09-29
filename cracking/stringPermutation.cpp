

#include <iostream>

using namespace std;

bool isPerm(string s1, string s2);

int main (int argc, char * argv[]) {

	if (argc != 3) {
		cerr << "Call with two strings.\n";
		exit(1);
	}

	if (isPerm(argv[1], argv[2])) {
		cerr << "Is a permutation.\n";
	} else {
		cerr << "Is not a permutation.\n";
	}

	return 0;
}


// NEEDS REVISION
bool isPerm(string s1, string s2) {

	if (s1.length() != s2.length()) return false;

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	int i = 0;
	while (i < s1.length()) {
		if (s1[i] != s2[i]) return false;
		i++;
	}
	return true;
}