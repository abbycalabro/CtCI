#include <iostream>

using namespace std;

const int SIZE = 4;

void rotateMatrix(int n, int matrix[SIZE][SIZE]) {
	/*
	 * for i = 0 to n:
	 * temp = top[i]
	 * top[i] = left[i]
	 * left[i] = bottom[i]
	 * bottom[i] = right[i]
	 * right[i] = temp
	*/
	
	for(int layer = 0; layer < n / 2; ++layer) {
		int first = layer;
		int last = n - 1 - layer;
		cout << "LAYERS: first = " << first << ", last = " << last << endl;
		for(int i = first; i < last; ++i) {
			int offset = i - first;
			cout << "Offset = " << offset << endl;
			int top = matrix[first][i];
			
			//left to top
			matrix[first][i] = matrix[last - offset][first];
			//bottom to left
			matrix[last - offset][first] = matrix[last][last - offset];
			//right to bottom
			matrix[last][last - offset] = matrix[i][last];
			//top to right
			matrix[i][last] = top;
		}
	}
}

void printMatrix(int matrix[SIZE][SIZE]) {
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int main(int argc, char* argv[]) {
	int val = 10;
	int matrix[SIZE][SIZE];

	//populate and print matrix
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) 
			matrix[i][j] = val++; 
	}
	
	printMatrix(matrix);
	rotateMatrix(SIZE, matrix);
	cout << endl;
	printMatrix(matrix);

	return 0;
}
