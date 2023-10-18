// 2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

#define MAX 1000
float score_array[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    float average = 0;
    float max_score = 0;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> score_array[i];
        if (score_array[i] > max_score)
            max_score = score_array[i];
    }

    for (int i = 0; i < N; i++)
    {
        average += score_array[i] * 100 / (N * max_score);
    }
    
    cout << average <<"\n";
}
