// 0.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000000

int num_array[MAX];

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> num_array[i];

    sort(num_array, num_array + N);
       
    for (int i = 0; i < N; i++)
        cout << num_array[i] <<"\n";

    return 0;
}
