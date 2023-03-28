#include <iostream>

using namespace std;
void positivizador(int &n, int mod){

    if (n >= mod) {
        n %= mod;
    }
    if (n < 0) {
        n = n + mod;
    }
}

void suma(int n1, int n2, int mod) {
    int result;
    result = n1 + n2;
    positivizador(result, mod);

    cout << "Suma:" << endl;
    cout << n1 << " mod " << mod << " + " << n2 << " mod " << mod << " = " << result << " mod " << mod << endl;
}
void resta(int n1, int n2, int mod) {
    int result;
    result = n1 - n2;
    positivizador(result, mod);

    cout << "Resta:" << endl;
    cout << n1 << " mod " << mod << " - " << n2 << " mod " << mod << " = " << result << " mod " << mod << endl;
}
void multiplicacion(int n1, int n2, int mod) {
    int result;
    result = n1 * n2;
    positivizador(result, mod);

    cout << "Multiplicacion:" << endl;
    cout << n1 << " mod " << mod << " * " << n2 << " mod " << mod << " = " << result << " mod " << mod << endl;
}
/*
Ejemplo de 15 mod 26
Confirmamos si hay inversa y hallamos cocientes (q)
Pos(q)  A = q*B+R
0       26 = 1*15+11
1       15 = 1*11+4
2       11 = 2*4+3
3       4 = 1*3+1   <- Tenemos 1 de residuo, si hay inversa
        3 = 3*1+0
Hallamos inversa
P_i = P_(i-2)-q_(i-2)*P_(i-1)
P_0 = 0
P_1 = 1
P_2 = 0-1*1 = -1
P_3 = 1-1*-1 = 2
P_4 = -1-2*2 = -5
P_5 = 2-1*-5 = 7    <- Hallamos el inverso
*/

void inverso(int B, int A) { //B=n1 y A=mod
    int q, R = 0, P0 = 0, P1 = 1, Px, mod = A;
    while (R != 1) {
        q = A / B;
        R = A % B;
        Px = P0 - (q * P1);

        if (R == 0) {
            cout << "Inverso: " << endl;
            cout << "Este numero no tiene inversa modular" << endl;
            break;
        }

        A = B;
        B = R;
        P0 = P1;
        P1 = Px;
    }
    if (R != 0) {
        cout << "Inverso: " << endl;
        positivizador(Px, mod);
        cout << Px << " mod " << mod << endl;
    }
}

int main() {
    int n1, n2, mod;

    cout << "Calculadora de modulos" << endl;
    cout << "Ingrese el primer numero, segundo numero y modulo: " << endl;
    cin >> n1 >> n2 >> mod;
    cout << "--------------------------------------------------------------------------" << endl;
    suma(n1, n2, mod);
    cout << "--------------------------------------------------------------------------" << endl;
    resta(n1, n2, mod);
    cout << "--------------------------------------------------------------------------" << endl;
    multiplicacion(n1, n2, mod);
    cout << "--------------------------------------------------------------------------" << endl;
    inverso(n1, mod);

    return 0;
}