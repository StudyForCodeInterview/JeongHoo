// 28_1167.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

unsigned long long max_len = 0;

int far_index;
vector<vector<pair<int,int>>> int_vec;
vector<bool> visit_vec;

void DFS(int v, unsigned long long dist);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    int_vec = vector<vector<pair<int, int>>>(V + 1);
    visit_vec = vector<bool>(V + 1,false);
    for (int i = 0; i < V; i++)
    {
        int input,first,second;

        cin >> input;

        while (1)
        {
            cin >> first;
            if (first == -1)
                break;
            cin >> second;

            int_vec[input].push_back(pair<int, int>(first, second));
        }
    }
  
    DFS(1, 0); //int_vec[1].front().second);
    max_len = 0;
    DFS(far_index, 0);

    cout << max_len << "\n";
    return 0;
}

void DFS(int v, unsigned long long dist)
{
    if (visit_vec[v])
        return;

    visit_vec[v] = true;

    for (vector<pair<int, int>>::iterator iter = int_vec[v].begin(); iter != int_vec[v].end(); iter++)
    {
        DFS(iter->first, iter->second + dist);
    }

    if (max_len < dist)
    {
        far_index = v;
        max_len = dist;
    }

    visit_vec[v] = false;
}
