// 27_2178.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_CNT 102

int g_maze[MAX_CNT][MAX_CNT];
int g_count[MAX_CNT][MAX_CNT];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int y = 1; y <= N; y++)
    {
        string str;
        cin >> str;
        for (int x = 1; x <= M; x++)
        {
            g_maze[y][x] = str[x-1] - '0';
        }
    }

    queue<pair<int,int>> i_queue;
    g_count[1][1] = 1;

    i_queue.push(pair<int,int>(1,1));

    while (i_queue.size() > 0)
    {
        pair<int,int> pa = i_queue.front();
        i_queue.pop();
        if (g_maze[pa.first][pa.second])
        {
            int move_count = g_count[pa.first][pa.second] + 1; // 판단 위치 기준 +1움직일 수 있는 타일에 대한 거리 비교

            if (g_maze[pa.first][pa.second + 1])
                if (g_count[pa.first][pa.second + 1] > move_count || g_count[pa.first][pa.second + 1] == 0)
                {
                    g_count[pa.first][pa.second + 1] = move_count;
                    i_queue.push(pair<int, int>(pa.first, pa.second + 1));
                }

            if (g_maze[pa.first][pa.second - 1])
                if (g_count[pa.first][pa.second - 1] > move_count || g_count[pa.first][pa.second - 1] == 0)
                {
                    g_count[pa.first][pa.second - 1] = move_count;
                    i_queue.push(pair<int, int>(pa.first, pa.second - 1));
                }

            if (g_maze[pa.first + 1][pa.second])
                if (g_count[pa.first + 1][pa.second] > move_count || g_count[pa.first + 1][pa.second] == 0)
                {
                    g_count[pa.first + 1][pa.second] = move_count;
                    i_queue.push(pair<int, int>(pa.first+1, pa.second));
                }

            if (g_maze[pa.first - 1][pa.second])
                if (g_count[pa.first - 1][pa.second] > move_count || g_count[pa.first - 1][pa.second] == 0)
                {
                    g_count[pa.first - 1][pa.second] = move_count;
                    i_queue.push(pair<int, int>(pa.first-1, pa.second));
                }
        }
    }

    cout << g_count[N][M] << "\n";
    return 0;
}