
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int m,A_m,B_m;
        int P, Q, R, S, W;
        cin>>P>>Q>>R>>S>>W;
        
        A_m = W* P;
        if(W>R)
        {    
        	B_m = Q + (W - R) * S;
        }else
            B_m = Q;
        m = (A_m<B_m) ? A_m : B_m ;
		cout<<"#"<<test_case<<" "<<m<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}