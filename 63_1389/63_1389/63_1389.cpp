// 63_1389.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#define MAX 1000000
using namespace std;

vector<vector<int>> D;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    D = vector<vector<int>>(N+1);

    for (int i = 1; i < D.size(); i++)
    {
        D[i] = vector<int>(N + 1, MAX);
        D[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        D[A][B] = 1;
        D[B][A] = 1;
    }
    
    for (int K = 1; K <= N; K++)
    {
        for (int S = 1; S <= N; S++)
        {
            for (int E = 1; E <= N; E++)
            {
                D[S][E] = min(D[S][E], D[S][K] + D[K][E]);
            }
        }
    }

    int ans_num = 1;
    int min_cnt = MAX;
    for (int i = 1; i < D.size(); i++)
    {
        int ans_cnt = 0;
        for (int j = 0; j < D[i].size(); j++)
        {
            if (D[i][j] == MAX)
                continue;   
            
            ans_cnt += D[i][j];
        }
        if (ans_cnt < min_cnt)
        {
            min_cnt = ans_cnt;
            ans_num = i;
        }
    }

    cout << ans_num;
    return 0;
}
