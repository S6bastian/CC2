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
    split(A, odd);
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
    for(int *i=A; i<A+9; i++){
        cout<<" "<<*i;
    }
    cout<<" }"<<endl;
}


void split(int *A, bool (*pf)(int)){
    int *start=A;
    int *end=A+9;
    for(int *i=start; i<end;i++){
        if(!pf(*i)){
            for(int *j=i+1; j<end;j++){
                if(pf(*j)){
                    swap(i,j);
                    break;
                }
            }
        }   
    }
}

