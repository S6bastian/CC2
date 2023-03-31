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
}

void resta(int n1, int n2, int mod) {
    int result;
    result = n1 - n2;
    positivizador(result, mod);
}

int multiplicacion(int n1, int n2, int mod) {
    int result;
    result = n1 * n2;
    positivizador(result, mod);
    return result;
}

int inverso(int B, int A) { //B=n1 y A=mod
    int q, R = 0, P0 = 0, P1 = 1, Px, mod = A;
    while (R != 1) {
        q = A / B;
        R = A % B;
        Px = P0 - (q * P1);

        if (R == 0) {
            cout << "Inverso: " << endl;
            cout << "Este numero no tiene inversa modular" << endl;
            return 0;
        }

        A = B;
        B = R;
        P0 = P1;
        P1 = Px;
    }

    positivizador(Px, mod);
    return Px;
}

void encriptado(int key) {
    string text="";
    string aux_text="";
    int aux;

    ifstream plain("PLAIN.txt");
    getline(plain,text);
    cout<<text.size()<<endl;
    for(int i=0; i<text.size(); i++){
        aux=static_cast<int>(text[i]);
        aux=multiplicacion(aux,key,256);
        aux_text+=static_cast<char>(aux);
    }
    cout<<aux_text.size()<<endl;
    ofstream cifer("CIFER.txt");
    cifer<<aux_text;
}

void desencriptado(int key){
    string text="";
    string aux_text="";
    int aux;

    key=inverso(key,256);

    ifstream cifer("CIFER.txt");
    getline(cifer,text);
    cout<<text.size()<<endl;
    for(int i=0; i<text.size(); i++){
        aux=static_cast<int>(text[i]);
        aux=multiplicacion(aux,key,256);
        aux_text+=static_cast<char>(aux);
    }
    cout<<aux_text.size()<<endl;
    ofstream plainz("PLAINZ.txt");
    plainz<<aux_text;
}

int main() {
    int n1, mod, opc, key=21;
    bool itr=1;
    string text,a;
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
            encriptado(key);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Desencriptando..."<<endl;
            desencriptado(key);
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