#include<iostream>
using namespace std;
int main()
{
    int n;
    string f = "YES";
    cin >> n;
    int A[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;j++)
            cin >> A[i][j];
    for(int i = 0; i < n; i++)
    {
        if(A[i][i] == 1)
        {cout << "NO";return 0;}
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(A[i][j] != A[j][i])
                f = "NO";
    cout << f;
}