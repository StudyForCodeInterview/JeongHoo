// 16_1377.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int count = 1;

    vector<int> int_vec(N);

    for (int i = 0; i < N; i++)
    {
        cin >> int_vec[i];
    }
    

    for (int i = N-1; i > 0; i--)
    {
        if (int_vec[i - 1] > int_vec[i])
            count++;
    }
    cout << count << "\n";
    
    return 0;
}