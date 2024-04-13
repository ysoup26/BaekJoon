/* 자물쇠와 열쇠

1초 128MB

문제 요약: 자물쇠와 열쇠가 있다.
           자물쇠는 NxN의 형태, 열쇠는 MxM의 형태일때, 
           열쇠를 회전하고 이동해서 자물쇠 열어야 하는데 결과에 따라 true false를 출력한다.
           단, 열쇠의 돌기와 자물쇠의 돌기가 만나면 안되고,
            자물쇠의 홈은 다 채워져야 한다.

입력: 
key와 lock의 2차원 배열들
0 0 0
1 0 0
0 1 1
1 1 1
1 1 0
1 0 1

true

풀이: 

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    return answer;
}

int main(){
    string s;
    cin>>s;
    cout<<solution(s);
    return 0;
}