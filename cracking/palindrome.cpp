#include <iostream>

using namespace std;

bool isPalindrome(string s);

int main(int argc, char * argv[]) {

	if (argc != 2) {
		cout << "Call with a string\n";
	}

	if (isPalindrome(argv[1]))
		cout << "Is a palindrome\n";
	else
		cout << "Is not a palindrome\n";

	return 0;
}


// a palindrome has 1 or 0 occurences of single chars
bool isPalindrome(string s) {

	sort(s.begin(), s.end());


	int singles = 0;
	int count = 0;
	while (count < s.length()) {
		// if found a single
		if (s[count] != s[count+1]) {
			singles++;
		}
		else if (s[count] == s[count+1]) {
			count++;
		}
		count++;
	}
	
	if (singles > 1) 
		return false;
	return true;


}
