#include <iostream>
#include <limits.h>
using namespace std;
void d(int** a, int* way, int* visited, int n) {
	while (true) {
		int imin = -1;
		int minval = INT_MAX;
		for (int i = 0; i < n; i++) { //поиск вершины с минимальным путем
			if (way[i] < minval && visited[i] == 0) {
				minval = way[i];
				imin = i;
			}
		}
		if (imin == -1) return; //если такая вершина вообще есть и не посещена, то продолжить
		for (int j = 0; j < n; j++) { //пройти по массиву way и изменить время других дорог в меньшую сторону,если возможно 
			if (a[imin][j] > 0) {
				if (way[j] > way[imin] + a[imin][j]) {
					way[j] = way[imin] + a[imin][j];
				}
			}
		}
		visited[imin] = 1;
	}
}

int main() {
	int n, strt, fin; cin >> n >> strt >> fin;
	strt--; fin--;
	int** a = new int* [n];
	int* visited = new int[n];
	int* way = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		visited[i] = 0;
		way[i] = INT_MAX;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	way[strt] = 0;
	d(a, way, visited, n);
	if (way[fin] == INT_MAX) 
		cout << -1;
    else
	    cout << way[fin];
	return 0;
}
