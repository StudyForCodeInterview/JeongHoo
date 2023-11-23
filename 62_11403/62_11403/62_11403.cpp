// 62_11403.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

#define MAX 100000001
vector<vector<int>> edge;

vector<int> D;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    edge = vector<vector<int>> (N+1);

    for (int i = 1; i < edge.size(); i++)
    {
        edge[i] = vector<int>(N + 1, MAX);
        for (int j = 1; j < edge[i].size(); j++)
        {
            int w;
            cin >> w;

            if (w != 0)
            edge[i][j] = w;
        }
    }

    for (int K = 1; K <= N; K++)
    {
        for (int S = 1; S <= N; S++)
        {
            for (int E = 1; E <= N; E++)
            {
                edge[S][E] = min(edge[S][E], edge[S][K] + edge[K][E]);
            }
        }
    }
    for (int i = 1; i < edge.size(); i++)
    {
        for (int j = 1; j < edge[i].size(); j++)
        {
            if (edge[i][j] != MAX)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }

    return 0;
}
