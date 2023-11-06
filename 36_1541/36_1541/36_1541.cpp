// 36_1541.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    //문자열 파싱 너무 싫다.
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> str;

    int sum = 0;
    bool flag = true;

    string sub_str;

    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] == '-' || str[i] == '+' || str[i] == '\0')
        {
            if (flag)
                sum += stoi(sub_str);
            else
                sum -= stoi(sub_str);

            if(str[i] == '-')
                flag = false;
            sub_str.clear();
        }
        else
            sub_str += str[i];
    }
    cout << sum << "\n";

    return 0;
}