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
#include <vector>

using namespace std;

class People{
public:
    string name;
    int k,e,s;
    People(){
        
    };
    void init(string p,int k,int e,int s){
        this->name = p;
        this->k = k;
        this->e = e;
        this->s = s;
    };
    void change_People(People p){
        this->name = p.name;
        this->k = p.k;
        this->e = p.e;
        this->s = p.s;
    }
};

int main()
{
    int N;
    cin>>N;
    vector<People> pp;
    for(int i=0;i<N;i++){
        string p_name;
        int k,e,s;
        cin>>p_name>>k>>e>>s;
        People p;
        p.init(p_name,k,e,s);
        pp.push_back(p);
    }
    for(int i=0;i<N-1;i++){
        int min_idx = i;
        for(int j=i+1;j<N;j++){
            if(pp[j].k<pp[min_idx].k) //최솟값 idx를 저장
                min_idx = j;
        }
        if(i!=min_idx) //시작 idx와 최솟값 idx가 동일하지 않으면 swap //swap은 딱 한번만
        {
            People tmp = pp[i];
            pp[i].change_People(pp[min_idx]);
            pp[min_idx].change_People(tmp);
        }
    }
    for(int i=0;i<N;i++){
        string p_name;
        p_name = pp[i].name;
        cout<<p_name<<"\n";
    }
    return 0;
}