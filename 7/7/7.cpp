// 7.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 15000
int material_array[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // N - 재료의 개수, M - 번호 합
    cin >> N >> M;

    int answer = 0;
    int start_index = 0;
    int end_index = N-1;
    
    for (int i = 0; i < N; i++)
        cin >> material_array[i];

    sort(material_array, material_array + N);
     
    do{
        if (material_array[start_index] + material_array[end_index] > M)
        {
            end_index--;
        }
        else if (material_array[start_index] + material_array[end_index] < M)
        {
            start_index++;
        }
        else // sum_ == M
        {
            end_index--;
            start_index++;
            answer++;
        }
    } while (start_index < end_index);

    cout << answer << "\n";
        return 0;
}