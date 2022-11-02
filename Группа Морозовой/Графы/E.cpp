#include <iostream>
using namespace std;
int main()
{
    int a, b, n, m;
    cin >> n >> m;
    int A[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = 0;
    while(cin >> a >> b)
    {
        A[a - 1][b - 1] = 1;
        A[b - 1][a - 1] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}