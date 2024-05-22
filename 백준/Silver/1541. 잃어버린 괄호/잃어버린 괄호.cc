#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input_; 
    vector<int> integers; //두 배열다 vector로 선언하여 값 지우기를 용이하게
    vector<char> ops; 
    
    cin>>input_;
    //입력을 숫자와 연산으로 구분해서 각각 저장
    string add_="";
    for(int i=0;i<input_.length();i++){
        if(input_[i]=='-' || input_[i]=='+'){ 
            ops.push_back(input_[i]);
            integers.push_back(stoi(add_));  //이번 검증 단어가 연산자=기존에 쌓인 값들이 숫자
            add_="";
        }else{
            add_+=input_[i];
        }
    }
    integers.push_back(stoi(add_));  //마지막 숫자도 삽입(마지막 연산이 마지막숫자 앞에 있기 때문에)
    
    int sum = 0;
    int updated_idx=-1;          //업데이트할 idx를 기억해둠
    int ops_size = ops.size();
    int ops_idx=0;
    int integers_idx = 0;
    //덧셈 연산 우선 수행
    for(int i=0;i<ops_size;i++){ //ops 개수만큼 수행(내부에서 가변적으로 삭제되기 때문에 별도의 변수)
        //해당 계산에서 -는 무시
        if(ops[ops_idx]=='-'){
            updated_idx = -1;
            integers_idx++;
            ops_idx++;
            continue;
        }
        if(updated_idx == -1){ //연속 덧셈이 처음
            updated_idx = integers_idx;
        }
        integers[updated_idx]= integers[updated_idx]+integers[updated_idx+1]; //연속덧셈의 시작부분에 값을 합침
        ops.erase(ops.begin() + ops_idx);
        integers.erase(integers.begin() + updated_idx+1); //이후 부분은 vector에서 삭제
    }

    //배열 체크
    /*
    for(int i=0;i<integers.size();i++){
        cout<<integers[i]<<" ";
    }
    for(int i=0;i<ops.size()-1;i++){
        cout<<ops[i]<<" ";
    }
    cout<<"\n";
    */
    if(ops.size()>0){ //-연산이 존재할때: 그만큼 sum에서 빼줌
        sum = integers[0];
        for(int i=1;i<integers.size();i++){
            sum-=integers[i];
        }
    }else  //-연산이 존재하지 않을때: 이미 integers[0]에 합이 들어있음
        sum = integers[0];
    
    cout<<sum;
    return 0;
}