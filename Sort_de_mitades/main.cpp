#include <iostream>

using namespace std;

void swap_val(int *a, int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void print_arr(int *arr, int n=0){
    n=sizeof(arr);
    //cout<<n<<endl;
    cout<<"[";
    for(int *i=arr; i<arr+n; i++){
        cout<<" "<<*i;
    }
    cout<<" ]"<<endl;
}

int main(){
    int n;
    int arr[8]={1,5,7,13,2,6,10,20};
    //int arr[10]={3, 9, 15, 21, 27, 2, 8, 14, 20, 26};
    int *p;
    int *q;
    int *aux;

    n=sizeof(arr)/sizeof(arr[1]);
    p=arr;
    q=arr+(n/2);

    while(q<arr+n){
        if(*p<*q){
            p++;
        }
        else{
            cout<<"a"<<endl;
            aux=q;
            while(p!=q){
                swap_val(q,q-1);
                q--;
            }
            q=aux+1;
            p++;
        }
        if(p==q){
            q++;
        }
    }

    print_arr(arr);    

    return 0;
}
