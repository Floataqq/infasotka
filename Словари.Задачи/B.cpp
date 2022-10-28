#include <iostream>
#include <map>
#define int long long
using namespace std;
signed main()
{
    map<string, map<string, int>> a;   //словарь с тремя полями
    string s1, s2; int s;
    while(cin >> s1 >> s2 >> s)
        a[s1][s2] += s;   //создаем словарь вида имя : товар : количество
    for(auto [i, j] : a)
    {
        //i - имя, j - словарь с товарами по этому имени
        cout << i << ":" << endl; //выводим имя
        for(auto [u, v] : j) //u - имя товара, v - количство этого товара
            cout << u << " " << v << endl; //выводим товары
    }
    return 0;
}