#include <iostream>
#include <limits.h>
using namespace std;
void d(int** a, int* way, int* visited, int n) {
	while (true) {
		int imin = -1;
		int minval = INT_MAX;
		for (int i = 0; i < n; i++) { 
			if (way[i] < minval && visited[i] == 0) {
				minval = way[i];
				imin = i;
			}
		}
		if (imin == -1) return; 
		for (int j = 0; j < n; j++) { 
			if (a[imin][j] > 0) {
				if (way[j] > way[imin] + a[imin][j]) {
					way[j] = way[imin] + a[imin][j];
				}
			}
		}
		visited[imin] = 1;
	}
}
int main() {//единственное отличие от предыдущей задачки - матрица смежности не симметрична
    int n; cin >> n;
    int* b = new int[n];
	int* way = new int[n];
    int* visited = new int[n];
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        a[i] = new int[n];
		way[i] = INT_MAX;
		visited[i] = 0;
    }
	way[0] = 0;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1] = b[x - 1];
        a[y - 1][x - 1] = b[y - 1];
    }
	d(a, way, visited, n);
	if (way[n - 1] == INT_MAX)
		cout << -1;
	else
		cout << way[n - 1];
	return 0;
}
