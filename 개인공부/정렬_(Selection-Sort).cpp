/*Selection Sorting(선택 정렬)
  : 배열에서 최소값인 원소를 찾고 배열의 시작 원소와 교환(swap)해서 정렬하는 방식
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

void selection_sorting(int list[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_idx = i;
        //최소값 찾기
        for(int j=i+1;j<n;j++)
        {
            if(list[j]<list[min_idx]) //최솟값 idx를 저장
                min_idx = j;
        }
        if(i!=min_idx) //시작 idx와 최솟값 idx가 동일하지 않으면 swap //swap은 딱 한번만
        {
            int tmp = list[min_idx];
            list[min_idx] = list[i];
            list[i] = tmp;
        }
    }
}

int main(){
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    selection_sorting(list,n);
    list_print(list,n);
    return 0;
}