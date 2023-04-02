#include <iostream>

using namespace std;

void swap_val(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(int* p, int* q) {
    int *n;
    n = q + (q - p);
    //cout<<n<<endl;
    cout << "[";
    for (int* i = p; i < n; i++) {
        cout << " " << *i;
    }
    cout << " ]" << endl;
}

void merge(int *p, int *q) {
    int *end;
    end = q + (q - p);
    
    while (q != end) {
        for (int* r = p; r < q; r++) {
            if (*r > *q) {
                swap_val(r, q);
            }
        }
        q++;
    }
    
}

int main() {
    int n;
    int A[] = { 4,6,10,22,34,40,42,1,3,11,21,23,39,41 };
    n = sizeof(A) / sizeof(int);
    merge(A, A + n/2);
    print_arr(A, A + n/2);

    return 0;
}