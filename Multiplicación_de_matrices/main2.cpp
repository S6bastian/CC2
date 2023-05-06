#include <iostream>

using namespace std;

void print(int (*)[3][3]);
void multiplication(int (*)[3][3]);
//void reset(int (*)[3][3]);

int main()
{
    int A[3][3][3] = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    multiplication(A);
    print(A);

    return 0;
}


void print(int(*A)[3][3]) {
    for (int i =0; i < 27; i++){
        cout << *(**A+i) << " ";
        if (i%3==2)
            cout<<endl;
        if (i%9==8)
            cout<<endl;
    }
}

/*
void print(int(*a)[3][3]) {
    int* p = **a;

    for (int i = 0; i < 27; i++) {
        if (i % 3 == 0) {
            cout << endl;
        }
        if (i % 9 == 0) {
            cout << endl;
        }
        cout << *(p + i) << " ";
    }
}


void print(int (*R)[3][3])
{
    cout << "{";
    for (int(*r)[3][3] = R; r < R + 3; r++)
    {
        cout << " {";
        for (int (*rr)[3] = *r; rr < *(r + 1); rr++)
        {
            cout << " {";
            for (int *rrr = *rr; rrr < *(rr+ 1); rr++)
            {
                cout << " " << *rrr;
            }
            cout << " }";
        }
        cout << " }";
    }
    cout << " }" << endl;
}
*/

void multiplication(int (*M)[3][3])
{
    int (*m)[3][3] = M;
    int *a=**m, *b=**(m+1), *r=**(m+2);

    while (a < b)
    {
        *r += *a * (*b);
        r++;
        b++;

        // Repeticion en fila
        if (r == *(*(m + 1)+1))
        {
            a++;
            *r-=3;
        }

        // Cambio de fila
        if (b == **(M+2))
        {
            //a++;
            b=**(M+1);
            m++;
            *r+=3;
        }
    }

}

/*

void reset(int (*R)[3])
{
    for (int(*r)[3] = R; r < R + 3; r++)
    {
        for (int *rr = *r; rr < *(r + 1); rr++)
        {
            *rr = 0;
        }
    }
}

*/