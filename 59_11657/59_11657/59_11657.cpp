// 59_11657.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int64_t, int64_t, int64_t> td;

#define MAX INT64_MAX

vector<int64_t> D;
vector<td> edge;

bool Update();
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // N - NODE , M - EDGE;
    int N, M;

    cin >> N >> M;

    D = vector<int64_t>(N + 1, MAX);

    for (int64_t i = 0; i < M; i++)
    {
        int64_t A, B, C;
        cin >> A >> B >> C;

        edge.push_back(td(A, B, C));
    }
    D[1] = 0;

    int64_t cnt = 0;
    while (cnt < N - 1)
    {
        Update();

        cnt++;
    }

    if (Update()) // 음수 사이클 존재.
        cout << "-1\n";
    else
    {
        for (int64_t i = 2; i < D.size(); i++)
        {
            if (D[i] == MAX)
                cout << "-1\n";
            else
                cout << D[i] << "\n";
        }
    }
    
    return 0;
}
bool Update()
{
    bool bRet = false;
    for (int64_t i = 0; i < edge.size(); i++)
    {
        int64_t s = get<0>(edge[i]);
        int64_t e = get<1>(edge[i]);
        int64_t w = get<2>(edge[i]);

        if ((D[s] != MAX) && (D[e] > D[s] + w))
        {
            D[e] = D[s] + w;
            bRet = true;
        }
    }

    return bRet;
}

