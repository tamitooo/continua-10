
#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int E = 26; // Number of children in the tree (for lowercase letters a-z)

struct Nodo {
    char valor;
    Nodo* hijos[E];
    bool esHoja;
    int posicion;
    Nodo(char v) : valor(v), esHoja(false), posicion(-1) {
        for (int i = 0; i < E; ++i)
            hijos[i] = nullptr;
    }
};

Nodo* construirArbol(string texto) {
    Nodo* raiz= new Nodo('/');
    int n = texto.size();
    for (int i = 0; i<n; ++i) {
        Nodo* nodo = raiz;
        for (int j = i; j < n; ++j) {
            int index =texto[j] - 'a';
            if (nodo->hijos[index]== nullptr){
                nodo->hijos[index]=new Nodo(texto[j]);
            }
            nodo = nodo->hijos[index];
        }
        nodo->esHoja = true;
        nodo->posicion = i;
    }
    return raiz;
}

void bajarPorRamas(Nodo* nodo, vector<int>& posiciones) {
    if (nodo ==nullptr)return;
    if (nodo->esHoja)
        posiciones.push_back(nodo->posicion);
    for (int i = 0; i < E; ++i)
        if (nodo->hijos[i])
            bajarPorRamas(nodo->hijos[i], posiciones);
}

vector<int> buscarPatron(Nodo* raiz, string patron) {
    int m =patron.size();
    Nodo* nodo=raiz;
    for (int i=0; i < m; ++i) {
        int index=patron[i] -'a';
        if (nodo->hijos[index] == nullptr)
            return {};
        nodo =nodo->hijos[index];
    }
    vector<int>posiciones;
    bajarPorRamas(nodo, posiciones);
    return posiciones;
}

