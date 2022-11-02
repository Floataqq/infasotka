#include<iostream>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    int A[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;j++)
            cin >> A[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
            if(A[i][j] == 1)
                sum++;
    cout << sum;
}