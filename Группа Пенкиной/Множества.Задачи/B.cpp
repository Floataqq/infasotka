#include <iostream>
#include <set>
using namespace std;
//идея - положить все координаты птиц в сет, тогда все
//птицы с одинаковыми координатами будут отображаться как 
//один элемент -> потом выведем размер сета и получим ответ!
int main()
{
    int n;
    cin >> n;
    set<int>a;
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        a.insert(x);
    }
    cout << a.size();
}