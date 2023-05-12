#include <iostream>

using namespace std;

void print(int *);
void swap(int *, int*);
void reposition(int *);

int main(){
    int A[]={1,0,3,7,89,0,345,0};
    reposition(A);
    print(A);

    return 0;
}

void print(int *A){
    cout<<"{";
    for(int *i=A; i<A+8; i++){
        cout<<" "<<*i;
    }
    cout<<" }"<<endl;
}
void swap(int *A, int*B){
    int tmp=*A;
    *A=*B;
    *B=tmp;
}

void reposition(int *A){
    int *start=A;
    int *end=A+8;
    for(int *i=A; i<end; i++){
        if(*i==0){
            for(int *j=i+1; j<end; j++){
                swap(j-1,j);
            }
        }
    }
}
