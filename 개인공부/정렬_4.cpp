/*국영수

1초 256MB

문제 요약: 학생 N명의 이름과 국,영,수 점수가 주어진다. 
          아래와 같은 조건으로 학생의 성적을 정렬하여 이름을 출력해라
        
         1) 국어 점수가 감소하는 순서
         2) 국어 점수가 같다면 영어 점수가 증가하는 순서로
         3) 국어, 영어 점수가 같다면 수학 점수가 감소하는 순서로
         4) 모든 점수가 같으면 이름 사전 순 증가로
입력: 
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100 
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100 
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90

풀이: 
*/


#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int N;
    cin>>N;
    int People[N][4];
    for(int i=0;i<N;i++){
        string p_name;
        int k,e,s;
        cin>>p_name>>k>>e>>s;
        People[i][0]=p_name;
        People[i][1]=k;
        People[i][2]=e;
        People[i][3]=s;
    }
    
    return 0;
}