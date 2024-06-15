#include <iostream>
#include <string>

using namespace std;

int main(){
    while(!cin.eof()){
        string s;
        getline(cin,s,'\n'); // \n을 기준으로 한줄씩 입력받음
        cout<<s<<"\n";
    }
    return 0;
}