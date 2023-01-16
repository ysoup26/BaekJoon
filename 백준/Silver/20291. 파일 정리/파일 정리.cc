#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;
//c++은 split 함수가 없음
int main()
{
    int N;
    cin>>N;
    map<string,int> ex;
	//입력 읽고 확장자만 저장해서 사전순 정렬까지
	for(int i=0;i<N;++i){
	    string f;
	    cin>>f;
	    f=f.substr(f.find('.')+1);
	    ex[f]++;
	}
	for(auto EX:ex)
	{
	    cout<<EX.first<<" "<<EX.second<<endl;
	} 
    return 0;
}