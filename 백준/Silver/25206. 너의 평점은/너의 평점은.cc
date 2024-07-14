#include <iostream>
#include <map>
using namespace std;

//map을 이용해서 등급과 실제 값을 매치시킴
map<string,long double> subject_grades ={
    {"A+",4.5},
    {"A0",4.0},
    {"B+",3.5},
    {"B0",3.0},
    {"C+",2.5},
    {"C0",2.0},
    {"D+",1.5},
    {"D0",1.0},
    {"F",0.0},
};

//전공평점을 출력한다. 전공평점: sum(학점x과목평점)/학점 총합
//단순 cout이 아니라 형을 지켜서 출력시키는게 핵심
int main(){
    long double major_grade = 0.0;
    long double sum_credit = 0.0;
    //한줄씩 다루는 for문
    for(int i=0;i<20;i++){
        string s,k; 
        long double h;
        //과목명/학점/과목평점(등급) 입력 받기
        cin>>s>>h>>k;
        if(k == "P")
            continue;
        //학점 총합과 (학점x과목평점) 총합 갱신
        sum_credit+=h;
        major_grade+= (h*subject_grades[k]);
    }
    if(major_grade >0){
        major_grade = major_grade/sum_credit;
    }
    printf("%Lf",major_grade);
    //전공평점 출력하기
    return 0;
}