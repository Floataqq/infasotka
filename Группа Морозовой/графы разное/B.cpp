#include <iostream>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    int a[100];
    for (int i = 0; i < n; i++) a[i] = 0;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        a[x - 1]++;
        a[y - 1]++;
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;   
}
