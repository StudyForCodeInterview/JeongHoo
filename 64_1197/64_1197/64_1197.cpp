// 64_1197.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<long long, long long, long long> td;
vector<td> s_tree;
vector<int> f_v;
void Union(int a, int b);
int Find(int a);

bool Compare(td a, td b)
{
    return get<2>(a) < get<2>(b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    f_v = vector<int>(V + 1);
    for (int i = 0; i < E; i++)
    {
        long long v, e, w;
        cin >> v >> e >> w;
        
        s_tree.push_back(td(v, e, w));
    }

    for (int i = 1; i < f_v.size(); i++)
    {
        f_v[i] = i;
    }

    sort(s_tree.begin(),s_tree.end(), Compare);

    int tot = 0;
    for (int i = 0; i < s_tree.size(); i++)
    {
        int s, w, e;
        s = get<0>(s_tree[i]);
        w = get<1>(s_tree[i]);
        e = get<2>(s_tree[i]);

        if (Find(s) != Find(w))
        {
            Union(s, w);
            tot += e;
        }
    }
    cout << tot << "\n";
    return 0;
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
    {
        f_v[b] = a;
    }
}

int Find(int a)
{
    if (f_v[a] == a)
        return a;

    return f_v[a] = Find(f_v[a]);
}
