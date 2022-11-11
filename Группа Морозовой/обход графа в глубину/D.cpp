#include <iostream>
using namespace std;
int n;
int a[100][100] = {};
int visited[100] = {};

void dfs(int v, int color) {
    visited[v] = color;
    for (int j = 0; j < n; j++) {
        if (a[v][j] != 0 && visited[j] == 0) {
            dfs(j, -color);
        }

    }
}
int check_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0 && visited[i] == visited[j]) {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    int l, k, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l >> k;
        a[l - 1][k - 1]++;
        a[k - 1][l - 1]++;
    }
    for (int i = 0; i < n; i++)
        if (visited[i] == 0) dfs(i, 1);
    if (check_graph()) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                cout << i + 1 << ' ';
            }
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}
