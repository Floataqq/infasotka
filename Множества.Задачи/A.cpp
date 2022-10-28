#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<long long>a;
    int n; cin >> n;             
    while(n--)         //просто цикл который повторяет действия n раз
    {
        string st; int x;
        cin >> st;     
        if(st[0] == 'A')
        {cin >> x;a.insert(x);} //вставляет элемент х в a
        else if(st[0] == 'P')
        {
            cin >> x;
            if(a.find(x) == a.end())        //проверяет, есть ли х в а
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else if(st[0] == 'C')
            cout << a.size() << endl; //просто размер
    }
    return 0;
}