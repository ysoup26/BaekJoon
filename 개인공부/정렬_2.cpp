/*성적이 낮은 순서로 학생 출력하기

1초 128MB

문제 요약: N명의 학생 정보(이름, 학생 성적)가 있다.
          이때 성적이 낮은 순서대로 학생의 이름을 출력하라.

입력: N 
      학생1 학생1점수
      ...

풀이: 학생 배열과 점수 배열. 1차원 배열 2개를 선언해서, 
      점수 배열을 정렬 할 때 학생 배열도 동일하게 변경한다.

*/


#include <iostream>
#include <algorithm>

using namespace std;

void list_print(string list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void selection_sort(int score[],string student[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        //검사 범위 중 max값 찾기
        for(int j=i+1;j<n;j++)
        {
            if(score[min]>score[j])
            {
                min = j;
            }
        }
        //점수 배열과 학생 배열을 동일한 인덱스들로 swap함
        if(min != i)
        {
            int tmp_i = score[min];
            score[min] = score[i];
            score[i] = tmp_i;
            string tmp_s = student[min];
            student[min] = student[i];
            student[i] = tmp_s;
        }
    }
    
    
}

int main()
{
    int n;
    cin>>n;
    int score[n];
    string student[n];
    for(int i=0;i<n;i++)
    {
        int sc; 
        string st;
        cin>>st>>sc;
        student[i] = st;
        score[i] = sc;
    }
    selection_sort(score,student,n);
    list_print(student,n);
    return 0;
}