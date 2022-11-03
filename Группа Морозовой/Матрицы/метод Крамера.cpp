#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void d(int**a, int*b, int n, int**c, int k) { 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		c[i][k] = b[i];
	}
}
void dopA0i(int**a, int**b, int n, int k) {
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i - 1][j] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = k; j < n; j++) {
			b[i][j] = b[i][j + 1];
		}
	}
}
double det(int**a, int n) { //считает определитель матрицы
	if (n == 1) return a[0][0];
	if (n == 2) return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	int d = 0;
	int **b = new int*[n];
	for (int i = 0; i < n; i++) b[i] = new int[n];

	for (int i = 0; i < n; i++) {
		dopA0i(a, b, n, i);
		d += a[0][i] * det(b, n - 1)*pow(-1, i);
	}
	for (int i = 0; i < n; i++) delete[]b[i];
	delete[]b;
	return d;
}


int main() {
	int n; cin >> n; //количество ур-ний
	int**a = new int*[n]; //коэфиценты 
	int**b = new int*[n]; //для вариантов для каждой переменной 
	int *c = new int[n]; //правые части ур-ний 
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		b[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}

		cin >> c[i];
	}
	
	int m = det(a, n);
	if (m != 0) { //если есть решения
		for (int i = 0; i < n; i++) {
			d(a, c, n, b, i);
			cout << det(b, n)/m << ' ';
		}

	}
	else {
		cout << 0;
	}
}
