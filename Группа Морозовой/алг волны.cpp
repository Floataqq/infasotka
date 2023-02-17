
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    queue <pair<int, int>> q;
    vector <vector<int>> a(n + 2, vector<int>(m + 2, -1));
    vector <int> di = { 0, -1, 0, 1 };
    vector <int> dj = { -1, 0, 1, 0 };

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    int si, sj, fi, fj; cin >> si >> sj >> fi >> fj;
    a[si][sj] = 1;

    q.push({ si, sj });
    while (!q.empty() && a[fi][fj] == 0) {
        int i, j;
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            if (a[i + di[k]][j + dj[k]] == 0) {
                a[i + di[k]][j + dj[k]] = a[i][j] + 1;
                q.push({ i + di[k], j + dj[k] });
            }
        }
    }

    if (a[fi][fj] == 0) cout << "no way((";
    else {
        stack <pair<int, int>> s;
        int i = fi, j = fj;
        while (a[i][j] != 1) {
            for (int k = 0; k < 4; k++) {
                if (a[i + di[k]][j + dj[k]] == a[i][j] - 1) {
                    s.push({ i + di[k], j + dj[k] });
                    i += di[k];
                    j += dj[k];
                    break;
                }
            }
        }
        while (!s.empty()) {
            cout << s.top().first << ' ' << s.top().second << endl;
            s.pop();
        }
        cout << fi << ' '<<fj;
    }
    /* вывести, что в массиве
    for (auto row : a) {
        for (auto x : row) printf("%4d", x);
        cout << endl;
    }*/
    return 0;
}

/* пример на пример
5 4
-1 -1 0 0
0  0 0 0
0 -1 -1 -1
0 0 0 0
0 -1 0 -1
1 3 4 3
*/
/* пример на no way
5 4
-1 -1 0 0
0  0 0 0
-1 -1 -1 -1
0 0 0 0
0 -1 0 -1
1 3 4 3
*/
