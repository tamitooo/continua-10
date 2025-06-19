#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// INOCENTE
vector<int> execInocente(string Texto, string Patron) {
    vector<int> posiciones;
    int n = Texto.size();
    int m = Patron.size();
    for (int i = 0; i <= n - m; i++) {
        int j =0;
        while (j < m && Texto[i + j] == Patron[j]){
            j++;
        }
        if (j==m){
            posiciones.push_back(i);
        }
    }
    return posiciones;
}

// BOYER MOORE
int* buildPositions(string Patron) {
    int* posiciones= new int[256];
    int m = Patron.size();
    for (int i = 0; i < 256;++i)
        posiciones[i] =-1;
    for (int i = 0; i<m; ++i)
        posiciones[(int)Patron[i]] =i;
    return posiciones;
}

vector<int> execBoyerMoore(string Texto, string Patron) {
    vector<int> posiciones;
    int n = Texto.size();
    int m = Patron.size();
    int* posicionesPatron = buildPositions(Patron);
    for (int j=0; j<= n-m;) {
        int i = m - 1;
        while (i >= 0 && Patron[i]==Texto[j + i])
            i--;
        if (i< 0) {
            posiciones.push_back(j);
            j++;
        } else {
            int salto= i - posicionesPatron[(int)Texto[j + i]];
            j += max(1, salto);
        }
    }
    delete[] posicionesPatron;
    return posiciones;
}