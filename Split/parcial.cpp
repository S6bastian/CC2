#include <iostream>

using namespace std;

void print(int *);
void swap(int *, int*);
void reposition(int *); //poner todos los 0 al final sin cambiar orden de los otros numeros
void pairs(int *);//

int main(){
    int A[]={1,0,3,7,89,0,345,0};
    int B[]={4,3,3,4,3,6,78,9};
    
    reposition(A);
    print(A);

    pairs(B);
    print(B);

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

void pairs(int *A){
    int *start=A;
    int *end=A+8;
    int cont=1;
    while(cont!=0){
        cont=0;
        for(int *i=A; i<end; i++){
            if(*i==*(i+1)&&*i!=0){
                *i=0;
                *(i+1)=0;
                for(int *j=i+1; j<end; j++){
                    swap(j-1,j);
                }
                for(int *j=i+1; j<end; j++){
                    swap(j-1,j);
                }
                cont++;
            }
        }
    }
    
}