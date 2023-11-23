// 50_1717.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
void Union(int a, int b);
int Find(int i);
bool Check(int a, int b);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    parent = vector<int>(n + 1);
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        int flag, a, b;
        cin >> flag >> a >> b;
        if (flag)
        {
            // find
            if (Check(a, b))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        // 0 
        else
        {
            Union(a, b);
        }
    }
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        parent[b] = a;
}
int Find(int i)
{
    if (i == parent[i])
        return i;

    else
    {
        return parent[i] = Find(parent[i]);
    }
}
bool Check(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return true;
    return false;
}