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

풀이: 조건이 여러개이기 때문에 선택 정렬 방식을 사용한다.
      선택할 학생을 정하기 위해 주어진 조건4개에 대한 if문 검사를 하며, 
      별도의 학생 클래스를 생성하여 swap과 초기화 등을 용의하게 구현했다.
*/


#include <iostream>
#include <vector>

using namespace std;

class Student{
public:
    string name;
    int kr,en,math;
    Student(){
        
    };
    void init(string n,int k,int e,int m){
        this->name = n;
        this->kr = k;
        this->en = e;
        this->math = m;
    };
    void change_student(Student s){
        this->name = s.name;
        this->kr = s.kr;
        this->en = s.en;
        this->math = s.math;
    }
};

int main()
{
    int N;
    cin>>N;
    vector<Student> ss;
    //학생 입력
    for(int i=0;i<N;i++){
        string s_name;
        int k,e,m;
        cin>>s_name>>k>>e>>m;
        Student s;
        s.init(s_name,k,e,m);
        ss.push_back(s);
    }
    //선택 정렬: 4가지 기준 체크
    for(int i=0;i<N-1;i++){
        int swap_idx = i;
        for(int j=i+1;j<N;j++){
            if(ss[j].kr > ss[swap_idx].kr)                     //1) 국어 점수가 감소하는 순서
                swap_idx = j;
            else if(ss[j].kr == ss[swap_idx].kr){              //2) 국어 점수가 같다면 
                if(ss[j].en < ss[swap_idx].en)                 //영어 점수가 증가하는 순서로
                    swap_idx = j;
                else if(ss[j].en == ss[swap_idx].en){          //3) 국어, 영어 점수가 같다면
                    if(ss[j].math > ss[swap_idx].math)         //수학 점수가 감소하는 순서로
                        swap_idx = j;
                    else if(ss[j].math == ss[swap_idx].math){  //4) 모든 점수가 같으면 
                        if(ss[j].name < ss[swap_idx].name)     //이름 사전 순 증가로
                            swap_idx = j;
                    }
                }
            }
        }
        //선택된 학생 idx와 시작 idx를 서로 swap 
        if(i!=swap_idx)
        {
            Student tmp = ss[i];
            ss[i].change_student(ss[swap_idx]);
            ss[swap_idx].change_student(tmp);
        }
    }
    for(int i=0;i<N;i++){
        string name;
        name = ss[i].name;
        cout<<name<<"\n";
    }
    return 0;
}