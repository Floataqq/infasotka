#include <iostream>
#include <set>
using namespace std;
void go_through_graph(int** a, int n, bool* visited, int node) {
    visited[node] = true;
    for (int i = 0; i < n; i++) {
        if (a[node][i] and !visited[i]) {
            go_through_graph(a, n, visited, i);
        }
    }
}
int main()
{
    int n; cin >> n;
    bool flag = true;
    bool* visited = new bool[n];
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    go_through_graph(a, n, visited, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            flag = false;
            cout << "NO";
            break;
        }
    }
    if (flag) cout << "YES";
    
    return 0;
}
