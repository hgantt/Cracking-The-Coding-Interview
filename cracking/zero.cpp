
#include <iostream>

using namespace std;

#define N 3

void print(int array[N][N]);
void zero(int array[N][N]);

int main (int argc, char * argv[]) {


	int array[N][N] = {{2, 4, 5 }, { 1, 0, 1}, {3, 1, 1}};


	print(array);
	cout << endl;
	zero(array);
	print(array);

}

// NOT WORKING
void zero(int array[N][N]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (array[i][j] == 0) {
				
			}
		}
	}

}

void print(int array[N][N]) {
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout << array[i][j] << " "; 
        cout << '\n'; 
    } 
} 