// вариант 16
# include <iostream>
#include <locale.h>
#include <math.h>
#include <random>
using namespace std;
std::random_device rd;
std::mt19937 gen(rd());

int random(int low, int high)
{
	std::uniform_int_distribution<> dist(low, high);
	return dist(gen);
}

int rev(int n) {
	int reverse = 0, rem;
	while (n > 0) {
		rem = n % 10;
		reverse = reverse * 10 + rem;
		n /= 10;
	}
	return reverse;
}

int main() {
	const int n = 7;
	int rows = n;
	int cols = n;
	int i,j,k,min=0;
	float avg = 0;

	int **ar1 = new int* [rows];
	for (int i = 0; i < rows; i++) {
			ar1[i] = new int[cols];
		}

	int **ar2 = new int* [rows];
	for (int i = 0; i < rows; i++) {
			ar2[i] = new int[cols];
		}

	int **ar3 = new int* [rows];
	for (int i = 0; i < rows; i++) {
			ar3[i] = new int[cols];
		}

	int **ar4 = new int* [rows];
	for (int i = 0; i < rows; i++) {
			ar4[i] = new int[cols];
		}

	cout << "input matrix A";
	cout << endl;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			ar1[i][j] = random(0,50);
			avg = avg + ar1[i][j];
		}
	}
	cout << endl;
	cout << "output matrix A";
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "avg A = " << avg/(n+n);
	cout << endl;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (ar1[i][j] % 2 != 0) {
				min = ar1[i][j];
			}
		}
	}

	for (i = 0; i < n; i++) {
		if ((min > ar1[i][n - i - 1]) && (ar1[i][n - i - 1] % 2 != 0)) {
			min = ar1[i][n - i - 1];
		}
	}
	for (i = 0; i < n; i++) {
		if ((min > ar1[0][i] && (ar1[0][i] % 2 != 0))) {
			min = ar1[0][i];
		}
	}
	for (i = 0; i < n; i++) {
		if ((min > ar1[n-1][i] && (ar1[n-1][i] % 2 != 0))) {
			min = ar1[n-1][i];
		}
	}
	for (i = 0; i < n; i++) {
		if ((min > ar1[i][0] && (ar1[i][0] % 2 != 0))) {
			min = ar1[i][0];
		}
	}
	for (i = 0; i < n; i++) {
		if ((min > ar1[i][n-1]) && (ar1[i][n - 1] % 2 != 0)) {
			min = ar1[i][n-1];
		}
	}

	cout << "min odd A = " << min;
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ar2[i][j] = rev(ar1[i][j]);
		}
	}
	cout << endl;
	cout << "reverse A";
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//C = A + B^2
	cout << "B * B =" << endl;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			ar3[i][j] = 0;
			for (int k = 0; k < n; k++)
				ar3[i][j] = ar3[i][j] + ar2[i][k] * ar2[k][j];
			cout << ar3[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ar4[i][j] = ar1[i][j] + ar3[i][j];
		}
	}
	cout << endl;
	cout << "C = A + B*B ";
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ar4[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < rows; i++) {
		delete [] ar1[i];
	}
	delete [] ar1;
	for (int i = 0; i < rows; i++) {
		delete[] ar2[i];
	}
	delete [] ar2;
	for (int i = 0; i < rows; i++) {
		delete[] ar3[i];
	}
	delete [] ar3;
	for (int i = 0; i < rows; i++) {
		delete[] ar4[i];
	}
	delete [] ar4;
}
