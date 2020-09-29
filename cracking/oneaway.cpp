#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


bool oneAway(string s1, string s2);


int main (int argc, char * argv[]) {

	if (argc != 3) {
		cout << "Call with two strings.\n";
		exit(1);
	}

	if (oneAway(argv[1], argv[2])) {
		cout << "They are one away.\n";
	} else {
		cout << "They are not one away.\n";
	}

	return 0;
}



bool oneAway(string s1, string s2) {

	int x = s1.length() - s2.length();

	// check for length
	if (abs(x) > 1)
		return false;


	int difference = 0;
	int left = 0;
	int right = 0;

	while (left < s1.length() and right < s2.length()) {
		if (s1[left] != s2[right]) {
			difference++;
			
			if (s1[left+1] == s2[right]) {
				left++;
			} else if (s1[left] == s2[right + 1]) {
				right++;
			}

		}
		left++;
		right++;
	}
	difference += s1.length() - left;
	difference += s2.length() - right;
	return difference < 2;

}