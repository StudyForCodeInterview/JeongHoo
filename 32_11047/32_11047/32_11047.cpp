// 32_11047.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> coin_vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coin_vec[i];
    }

    int sum = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        int div = K / coin_vec[i];
        if (div != 0)
        {
            K -= coin_vec[i] * div;
            sum += div;
         }

        if (K == 0)
            break;
    }
    
    cout << sum << "\n";

    return 0;
}