/*Bubble Sorting(버블 정렬)
  : 가장 기본적이면서도, 가장 비효율적인 정렬 알고리즘 
  : 인접 원소 2개를 비교하고 교환(swap)해서 정렬하는 방식
  : O(n^2)의 시간 복잡도를 가짐
*/

#include <iostream>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void bubble_sorting(int list[],int n)
{
    for(int i=n-1;i>0;i--) //정렬이 완료된 부분(n, n-1, n-2, ...)을 제외하기 위한 for문
    {
        for(int j=0;j<i;j++)//배열 시작부터 끝까지 비교하기 위한 for문
        {
            if(list[j]>list[j+1]) //인접 원소 비교
            {
                int tmp = list[j];
                list[j] = list[j+1];
                list[j+1] = tmp;
            }
        }
        //list_print(list,n);
    }
}

int main(){
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    bubble_sorting(list,n);
    list_print(list,n);
    return 0;
}