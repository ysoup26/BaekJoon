/*Selection Sort(계수 정렬)
  : 
  : 
*/

#include <iostream>

using namespace std;

void list_print(int list[],int n)
{
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    cout<<"\n";
}

void count_sort(int list[],int n)
{
    
}

int main(){
    int n = 5;
    int list[n] = {5, 7 ,3 ,6 ,1};
    count_sort(list,n);
    list_print(list,n);
    return 0;
}