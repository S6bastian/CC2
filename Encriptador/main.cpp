#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

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

void encriptado(string text) {

    ifstream plain("PLAIN.txt");
    getline(plain,text);

    cout<<text<<endl;
    
}

int main() {
    int n1, mod, opc;
    bool itr=1;
    string text;
    while (itr) {
        system("cls");
        cout << "Opciones" << endl;
        cout << "1.Encripta" << endl;
        cout << "2.Desencripta" << endl;
        cout << "3.Salir" << endl;
        cin >> opc;
        switch (opc) {
        case 1:
            system("cls");
            cout << "Encriptando..."<<endl;
            encriptado(text);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Desencriptando..."<<endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Saliendo..."<<endl;
            itr=0;
            system("pause");
            break;
        }
    }
    return 0;
}


/*
Escribir y leer archivo https://www.w3schools.com/cpp/cpp_files.asp
*/