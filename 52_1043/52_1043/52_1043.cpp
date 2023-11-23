// 52_1043.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

void Union(int a, int b);
int Find(int a);

vector<vector<int>> g_party;
vector<int> g_parent;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer_count = 0;

    int N, M;
    int know_cnt;
    cin >> N >> M;

    g_party = vector<vector<int>>(M + 1);
    g_parent = vector<int>(N + 1);
    cin >> know_cnt;
    
    vector<int> know_men;
    if (know_cnt == 0)
    {
        cout << M << "\n";
        return 0;
    }

    for (int i = 0; i < know_cnt; i++)
    {
        int know_num;
        cin >> know_num;
        
        know_men.push_back(know_num);
    }

    for (int i = 1; i < g_party.size(); i++)
    {
        int come_cnt;
        cin >> come_cnt;

        for (int j = 0; j < come_cnt; j++)
        {
            int come_num;
            cin >> come_num;
            g_party[i].push_back(come_num);
        }
    }

    for (int i =0 ; i < g_parent.size(); i++)
    g_parent[i] = i;

    for (int i = 1; i < g_party.size(); i++)
    {
        bool flag = true;;

        if (g_party[i].size() > 1)
        {
            int first = g_party[i][0];
            for (int j = 1; j < g_party[i].size(); j++)
            {

                Union(first, g_party[i][j]);
            }
        }
    }
    
    for (int i = 1; i < g_party.size(); i++)
    {
        bool flag = true;

        for (int j = 0; j < g_party[i].size(); j++)
        {
            for (int k = 0; k < know_men.size(); k++)
            {
                if (Find(g_party[i][j]) == Find(know_men[k]))
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            answer_count++;
    }
    cout << answer_count << "\n";

    return 0;
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a != b)
        g_parent[b] = a;
}
int Find(int a)
{
    if (a == g_parent[a])
        return a;

    return g_parent[a] = Find(g_parent[a]);
}