#include <vector>
#include <iostream>
using namespace std;
bool* visited;
vector <int>* a;
int dfs(int p) {
	visited[p] = true;
	int counter = 1;
	for (auto i : a[p]) {
		if (!visited[i]) {
			counter += dfs(i);
		}
	}
	return counter;
}
int main() {
	int n, p, k; cin >> n >> p;
	a = new vector<int>[n];
	visited = new bool[n];
	p--;
	for (int i = 0; i < n; i++) visited[i] = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> k;
			if (k == 1) {
				a[i].push_back(j);
			}
		}
	cout << dfs(p);
	return 0;
}
