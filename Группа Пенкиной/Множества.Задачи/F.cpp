#include <iostream>
#include <set>
#define ll long long
using namespace std;
//идея - жадный алгоритм: надо всегда складывать две наименьшие по населению провинции 
//в одну, чтобы провести минимальное число замен
//long long потому что числа до 10^9
int main()
{
    ll n, sum = 0;
    cin >> n;
    multiset<ll>a; //может быть две провинции с одинаковым числом жителей
    for(ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        a.insert(x);
    }
    while(a.size() > 1) //когда остается одна провинция, наша цель достигнута
    {
        ll x = 0, y = 0;
        x = *a.begin(); 
        a.erase(a.begin());
        y = *a.begin(); 
        a.erase(a.begin()); //берем два минимальных эелемента и удаляем их из множества
        ll z = x + y;
        sum += z; //прибавляем к числу всех изменений паспортов те, что мы поменяли
        a.insert(z); //сливаем их в один и добавляем обратно во множество, 
                        //т.к. наша сумма может оказаться наименьшей из всех провинций
    }
    cout << sum;
}