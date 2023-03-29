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
    int *p;
    int *q;

    n=sizeof(arr)/sizeof(arr[1]);
    //cout<<n<<endl;
    p=arr;
    q=arr+(n/2);
    //for(int i=0; i<n; i++){
    while(q<arr+n-1){
        if(p==q){
            q++;
            }
        if(*p<*q){
            p++;
        }
        else{
            swap_val(p,q);
            p++;
        }
        print_arr(arr);
    }

    //print_arr(arr);    

    return 0;
}

/*
for(int i=0; i<n; i++){

    if(p==q){
        q=arr+(n-1);
        }
    if(*p<*q){
        p++;
    }
    else{
        swap_val(p,q);
        p++;
    }
    print_arr(arr);
}
*/