/*위에서 아래로

1초 128MB

문제 요약: 크기 상관없이 나열되어 있는 수열을 내림차순으로 정렬한다.

입력: N 
     N개의 숫자들

풀이: 내림차이기때문에 기존 오름차방식을 수정하거나,
      sort_reverse를 사용한다.
*/


#include <iostream>
#include <algorithm>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void selection_sort(int list[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int max_ = i;
        //검사 범위 중 max값 찾기
        for(int j=i+1;j<n;j++)
        {
            if(list[max_]<list[j])
            {
                max_ = j;
            }
        }
        if(max_ != i)
        {
            int tmp = list[max_];
            list[max_] = list[i];
            list[i] = tmp;
        }
    }
    
    
}

int main()
{
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    selection_sort(list,n);
    //sort(list,list+n);
    //reverse(list,list+n); //sort함수: 배열시작과 배열시작+개수
    list_print(list,n);
    return 0;
}