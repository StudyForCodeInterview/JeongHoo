// 69_14425.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> str_set;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    int ans_cnt = 0;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        str_set.insert(str);
    }

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        
        set<string>::iterator i_find = str_set.find(str);

        if (i_find != str_set.end())
            ans_cnt++;
    }
    
    cout << ans_cnt << "\n";
    
    return 0;
}