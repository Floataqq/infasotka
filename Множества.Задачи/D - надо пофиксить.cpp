#include <iostream>
#include <set>
#include <sstream>
using namespace std;
set<int> operator -(set<int> a, set<int> b)
{
    set<int> c;
    for(int i : a)
    {
        if(b.find(i) == b.end())
            c.insert(i);
    }
    return c;    
}
set<int> operator &(set<int> a, set<int> b)
{
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
    int n; cin >> n;
    set<int> a;
    for(int i = 1; i <= n + 1; i++)
        a.insert(i);
    while(n--)
    {
        set <int> z;
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        int x;
        while(ss >> x)
            z.insert(x);
        cin >> s;
        if(s == "YES")
            a = a & z;
        else if(s == "NO")
            a = a - z;
        else if(s == "HELP")
        {
            for(auto i : a)
                cout << i << " ";
            break;
        }
    }
}