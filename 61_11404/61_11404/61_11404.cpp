// 61_11404.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000000
using namespace std;

vector<vector<int>> Cost;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    Cost = vector<vector<int>>(N + 1);
    
    for (int i = 1; i < Cost.size(); i++)
    {
        Cost[i] = vector<int>(N+1);
        fill(Cost[i].begin(), Cost[i].end(), MAX);
        Cost[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int start_city, end_city, cost;
        cin >> start_city >> end_city >> cost;

        if (cost < Cost[start_city][end_city])
            Cost[start_city][end_city] = cost;
    }

    for (int K = 1; K <= N; K++)
    {
        for (int S = 1; S <= N; S++)
        {
            for (int E = 1; E <= N; E++)
            {
                Cost[S][E] = min(Cost[S][E], Cost[S][K] + Cost[K][E]);
            }
        }
    }

    for (int i = 1; i < Cost.size(); i++)
    {
        for (int j = 1; j < Cost[i].size(); j++)
        {
            if (Cost[i][j] == MAX)
                cout << "0 ";
            else
                cout << Cost[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}


