/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//선택정렬: 제일 간단. 중첩 for문을 이용해서 내림차순
int main()
{
    string input;
    int cnt=1;
    cin>>input;
    for(int i=0;i<input.length()-1;i++)
    {
        for(int j=i+1;j<input.length();j++)
        {
            if(input[i]<input[j])
            {
                char temp=input[i];
                input[i]=input[j];
                input[j]=temp;
            }
            cnt++;
        }
    }
    cout<<input;//<<" "<<cnt; 

    return 0;
}
