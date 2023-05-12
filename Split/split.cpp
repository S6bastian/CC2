#include <iostream>

using namespace std;

bool even(int);
bool odd(int);
void swap(int, int);
void print(int *);
void split(int *, bool (*)(int));

int main(){
    int A[9]={1,2,3,4,5,6,7,8,9};
    split(A, even);
    print(A);
    
    return 0;
}

bool even(int x){
    return (x%2)==0;
}
bool odd(int x){
    return (x%2)!=0;
}
void swap(int *A, int *B){
    int tmp=*A;
    *A=*B;
    *B=tmp;
}
void print(int *A){
    cout<<"{";
    for(int *i=A; i<A+1; i++){
        cout<<" "<<*i;
    }
    cout<<" }"<<endl;
}


void split(int *A, bool (*pf)(int)){
    int *start=A;
    int *end=start+1;
    for(start; start<A-1;){
        if(pf(*start)){
            start++;
            end++;
        }
        else{
            for(int *i=end; i<A+1;i++){
                if(!*i%2==0){
                    swap(start,i);
                    break;
                }
            }
        }
    }
}

