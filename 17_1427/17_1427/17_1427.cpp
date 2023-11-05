// 17_1427.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N;
    cin >> N;

    int len = N.length();
    vector<char> ch_vec(len);

    for (int i = 0; i < len; i++)
    {
        ch_vec[i] = N[i];
    }
    
    for (int i = 0; i < ch_vec.size(); i++)
    {
        char max = ch_vec[i];
        int max_index = i;
        for (int j = i + 1; j < ch_vec.size(); j++)
        {
            if (max < ch_vec[j])
            {
                max = ch_vec[j];
                max_index = j;
            }
        }
        
        char tmp = ch_vec[i];
        ch_vec[i] = max;
        ch_vec[max_index] = tmp;
    }
    for (int i = 0; i < ch_vec.size(); i++)
    {
        cout << ch_vec[i];
    }

}