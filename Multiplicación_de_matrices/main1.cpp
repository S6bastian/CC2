#include <iostream>

using namespace std;

void print(int (*)[3]);
void multiplication(int (*)[3], int (*)[3], int (*)[3]);
void reset(int (*)[3]);

int main()
{
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    int R[3][3];

    multiplication(A, B, R);
    print(R);

    return 0;
}

void print(int (*R)[3])
{
    cout << "{";
    for (int(*r)[3] = R; r < R + 3; r++)
    {
        cout << " {";
        for (int *rr = *r; rr < *(r + 1); rr++)
        {
            cout << " " << *rr;
        }
        cout << " }";
    }
    cout << " }" << endl;
}

void multiplication(int (*A)[3], int (*B)[3], int (*R)[3])
{
    reset(R);
    int(*a)[3] = A, (*b)[3] = B, (*r)[3] = R;
    int *aa = *a, *bb = *b, *rr = *r;

    while (*a < *(A + 3))
    {
        *rr += *aa * (*bb);
        rr++;
        bb++;

        // Repeticion en fila
        if (rr == *(r + 1))
        {
            aa++;
            b++;
            bb = *b;
            rr = *r;
        }

        // Cambio de fila
        if (b == B + 3)
        {
            a++;
            aa = *a;
            b = B;
            bb = *b;
            *r++;
            rr = *r;
        }
    }

}

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