// 65_17472.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> pd;

vector<vector<int>> island;

vector<vector<pd>> adj;

vector<vector<bool>> visit;

vector<int> 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    adj = vector<vector<pd>>(N+1);

    for (int i = 1; i < adj.size(); i++)
    {
        
    }


    // // // // // // // // // // // // // // // // //
    island = vector<vector<int>>(N+2);
    
    visit = vector<vector<bool>>(N + 1);
    for (int i = 1; i < visit.size(); i++)
    {
        visit[i] = vector<bool>(N + 1, false);
    }

    island[0] = vector<int>(M + 1, 0);
    for (int i = 1; i < N+1; i++)
    {
        island[i] = vector<int>(M+2,0);
        for (int j = 1; j < M+1; j++)
        {
            cin >> island[i][j];
        }
    }
    return 0;
}
