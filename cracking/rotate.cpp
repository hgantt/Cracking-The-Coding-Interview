
#include <iostream>

using namespace std;

#define N 4 


void print(int array[N][N]);
void rotateIt(int array[N][N]);


int main(int argc, char * argv[]) {

    int arr[N][N] = { { 1, 2, 3, 4 }, 
                      { 5, 6, 7, 8 }, 
                      { 9, 10, 11, 12 }, 
                      { 13, 14, 15, 16 } }; 
    print(arr);
    cout << endl;        
    rotateIt(arr); 
    print(arr);
	return 0;

}



// function that rotates an image 90 degrees

void rotateIt(int array[N][N]) {

	for (int i = 0; i < N / 2; i++) {
		for (int j = i; j < N - i - 1; j++) {
			// a four way swap
			int temp = array[i][j];
			array[i][j] = array[N - 1 - j][i]; 
			array[N - 1 - j][i] = array[N - 1 - i][N - 1 - j]; 
            array[N - 1 - i][N - 1 - j] = array[j][N - 1 - i]; 
            array[j][N - 1 - i] = temp; 
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
