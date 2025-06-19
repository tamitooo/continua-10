#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include "smatching.h"
#include "suffixtree.h"

using namespace std;

const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";  // solo letras minúsculas


string generarTexto(size_t N){    
    string resultado = "";
    for (size_t i = 0; i < N; i++)
        resultado += alfabeto[rand() %  alfabeto.size()];
    return resultado;
}

vector<int> testInocente(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();
    vector<int> result = execInocente(Texto, Patron);
    auto end = std::chrono::steady_clock::now();

    //show the elapsed time
    cout << "Inocente: elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
    return result;
}

vector<int> testBoyerMoore(string Texto, string Patron)
{    
    auto start = std::chrono::steady_clock::now();
    vector<int> result = execBoyerMoore(Texto, Patron);
    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "BoyerMoore: elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
    return result;
}

vector<int> testSuffixTree(string Texto, string Patron)
{    
    Nodo* raiz = construirArbol(Texto);

    auto start = std::chrono::steady_clock::now();
    vector<int> result = buscarPatron(raiz, Patron);   
    auto end = std::chrono::steady_clock::now();
    
    //show the elapsed time
    cout << "SuffixTree: elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
    return result;
}

void verificarResultado(vector<int> result1, vector<int> result2)
{
    if(result1.size() != result2.size())
        cerr <<"Error!! el resultado no es el mismo\n";
    for(int i=0;i<result1.size();i++)
        if(result1[i] != result2[i])
            cerr <<"Error!! el resultado no es el mismo\n";
}

int main()
{    
    srand(time(NULL));    
    size_t N = 1000;//100,1000,10000,100000,1000000
    int m = 10;
    string Texto = generarTexto(N);
    string Patron = generarTexto(m);    
    
    vector<int> result1 = testInocente(Texto, Patron);
    vector<int> result2 = testBoyerMoore(Texto, Patron);
    vector<int> result3 = testSuffixTree(Texto, Patron);
    verificarResultado(result1, result2);
    verificarResultado(result1, result3);

    return 0;
}