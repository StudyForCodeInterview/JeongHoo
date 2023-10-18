// 4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#define MAX 1025

int num_array[MAX][MAX];
int sub_total_array[MAX][MAX];
int answer_array[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    int src_x, dest_x;
    int src_y, dest_y;
    cin >> N >> M;

    // 배열 입력
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> num_array[i][j];
        }
    }

    sub_total_array[1][1] = num_array[1][1];

    // 부분 합 계산
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            sub_total_array[i][j] = sub_total_array[i][j - 1] + sub_total_array[i-1][j] - sub_total_array[i-1][j-1]+ num_array[i][j];
        }
    }

    // 저장
    for (int i = 0; i < M; i++)
    {
        cin >> src_x >> src_y >> dest_x >> dest_y;

        cout << sub_total_array[dest_x][dest_y] - sub_total_array[src_x - 1][dest_y] - sub_total_array[dest_x][src_y - 1] + sub_total_array[src_x - 1][src_y - 1] << "\n";
    }    

    return 0;


}
