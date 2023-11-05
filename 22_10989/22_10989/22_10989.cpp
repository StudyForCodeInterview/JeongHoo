// 22_10989.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

// 기수 아닌 계수로

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> int_vec(10001);

    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;

        int_vec[data]++;
    }

    for (int i = 1; i < int_vec.size(); i++)
    {
        for (int j = 0; j < int_vec[i]; j++)
        {
            cout << i << "\n";
        }
    }
    
    return 0;
}