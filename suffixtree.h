#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int E = 26; // Number of children in the tree (for lowercase letters a-z)

struct Nodo{
    char valor;
    Nodo* hijos[E];
    bool esHoja;
    int posicion;
    Nodo(char v) : valor(v), esHoja(false), posicion(-1) {
        for(int i = 0; i < E; ++i) {
            hijos[i] = nullptr;
        }
    }
};


Nodo* construirArbol(string texto){
    // TODO: Implementar la construccion del arbol sufijo
    return nullptr; 
}

vector<int> buscarPatron(Nodo* raiz, string patron){
    // TODO: Implementar la busqueda del patron en el arbol sufijo
    return {};
}

