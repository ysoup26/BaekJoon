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

Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan

풀이: 기존 sort함수를 응용한다. 
     sort는 매개함수 지정이 가능한데, 학생들을 비교하는 함수를 넣어주면 간단하게 문제를 풀 수 있다.
     두개의 stdudent를 비교할때 해상 함수를 호출하는 방식이다.
 
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    int kr,en,math;
};

int cmd_student(Student s1,Student s2){
    if (s1.kr == s2.kr && s1.en == s2.en && s1.math == s2.math) return s1.name < s2.name; //4)이름 오름차
    if (s1.kr == s2.kr && s1.en == s2.en) return s1.math > s2.math; //3)수학 내림차
    if (s1.kr == s2.kr) return s1.en < s2.en; //2)영어 오름차
    return s1.kr > s2. kr; //1)국어 내림차
}

int main()
{
    int N;
    cin>>N;
    vector<Student> ss;
    //학생 입력
    for(int i=0;i<N;i++){
        Student s;
        cin>>s.name>>s.kr>>s.en>>s.math;
        ss.push_back(s);
    }
    sort(ss.begin(),ss.end(),cmd_student);
    for(int i=0;i<N;i++){
        string name;
        name = ss[i].name;
        cout<<name<<"\n";
    }
    return 0;
}