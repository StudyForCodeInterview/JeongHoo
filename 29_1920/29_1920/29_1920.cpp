// 29_1920.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> data_vec(N);
    for (int i = 0; i < N; i++)
    {
        cin >> data_vec[i];
    }

    sort(data_vec.begin(), data_vec.end());

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int data;
        cin >> data;

        int start_index = 0;
        int end_index = N - 1;

        bool flag = false;
        while (start_index <= end_index)
        {
            int mid_index = (start_index + end_index) / 2;

            if (data > data_vec[mid_index])
            {
                start_index = mid_index + 1;
            }
            else if (data < data_vec[mid_index])
            {
                end_index = mid_index - 1;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0; 
}
