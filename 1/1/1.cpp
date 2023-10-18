// 1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    int N;

    cin >> N;

    char data;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        sum += data - '0';
    }

    cout << sum << "\n";

    return 0;
}

