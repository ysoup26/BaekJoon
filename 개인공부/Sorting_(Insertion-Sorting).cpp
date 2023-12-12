/*Insertion Sorting(삽입 정렬)
  : 원소를 하나씩 삽입하는 것처럼 정렬하는 알고리즘. 
  : 삽입시 이전 원소들과 비교하여 작다면 이전 원소를 뒤로 보내고 해당 원소가 앞으로 간다.
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

void insertion_sorting(int list[],int n)
{
    for(int i=1;i<n;i++)
    {
        int new_ = list[i];
        int j;
        for(j=i-1;j>=0 && list[j]>new_;j--) //new_가 앞의 원소보다 작아야 for문 수행
        {
            //앞의 원소를 뒤로 보냄
            list[j+1] = list[j];
        }
        //마지막에 new_를 최종 위치로
        list[j+1] = new_; //for문이 종료되거나 중단될 때 마지막에서 j--했기 때문에 j++
        //list_print(list,n);
    }
}

int main(){
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    insertion_sorting(list,n);
    list_print(list,n);
    return 0;
}