

#include <iostream>

using namespace std;

string URLify(string s);

int main(int argc, char * argv[]) {


	string s1 = "Hi my name is David";

	cout << URLify(s1) << endl;

	return 0;

}


string URLify(string s) {

	string toInsert = "%20";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			s.erase(s.begin() + i);
			s.insert(i, toInsert);
		}
	}
	return s;
}