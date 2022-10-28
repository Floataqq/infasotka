#include <iostream>
#include <set>
using namespace std;
//вместо перегрузок можно написать йункцию с таким же кодом, и вызвать ее: auto c = F(a, b);
//перегрузка оператора:
set<int> operator &(set<int> a, set<int> b)
{
    //пересечение
    set<int> c;
    for(int i : a)
    {
        if(b.find(i) == b.end())
            c.insert(i);
    }
    return c;    
}
set<int> operator /(set<int> a, set<int> b)
{
    //разность
    set<int> c;
    for(int i : a)
    {
        if(b.find(i) != b.end())
            c.insert(i);
    }
    return c;    
}

int main()
{
    int n, m;
    cin >> n >> m;
    set<int>a, b, c;
    while(n--)
    {
        int x;
        cin >> x;
        a.insert(x);
    }
    while(m--)
    {
        int x;
        cin >> x;
        b.insert(x);
    }
    //создаем множества кубиков у Ани и Бори
    //сначала надо вывести пересечение множеств, это и делаем
    c = a / b;
    cout << c.size() << endl;
    for(int i : c)
        cout << i << " ";
    //далее только те, что есть у Ани: это разность кубиков Ани и пересечения
    auto x = a & c;
    cout << endl;
    cout << x.size() << endl;
    for(int i : x)
        cout << i << " ";
    cout << endl;
    //то же самое, но с Борей
    auto y = b & c;
    cout << y.size() << endl;
    for(int i : y)
        cout << i << " ";
}