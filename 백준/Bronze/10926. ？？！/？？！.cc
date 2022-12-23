//모든 입력에 대해 ??!을 붙여주는 문제임.
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string id;
    cin>>id;
    id+="?\?!";
    cout<<id; //삼중자를 구별할 수 있는가
    return 0;    
}