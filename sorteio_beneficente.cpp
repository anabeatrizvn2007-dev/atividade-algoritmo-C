
#include <iostream>
#include <string>
using namespace std;

int main() {
    int numeros[12];
    int distintos[12], ocorrencias[12];
    int vetorPares[12];
    int qtdDistintos = 0, qtdPares = 0;

    string produtos[100];
    float precos[100];
    int qtdProdutos = 0;

    cout << "Digite 12 numeros inteiros:\n";

    for (int i = 0; i < 12; i++) {
        cin >> numeros[i];
    }

    // Contagem dos numeros
    for (int i = 0; i < 12; i++) {
        bool encontrado = false;

        for (int j = 0; j < qtdDistintos; j++) {
            if (numeros[i] == distintos[j]) {
                encontrado = true;
                ocorrencias[j]++;
                break;
            }
        }

        if (!encontrado) {
            distintos[qtdDistintos] = numeros[i];
            ocorrencias[qtdDistintos] = 1;
            qtdDistintos++;
        }
    }

    // Numeros com ocorrencias pares
    for (int i = 0; i < qtdDistintos; i++) {
        if (ocorrencias[i] % 2 == 0) {
            vetorPares[qtdPares] = distintos[i];
            qtdPares++;
        }
    }

    // Ordenar numeros pares em ordem decrescente
    for (int i = 0; i < qtdPares - 1; i++) {
        for (int j = i + 1; j < qtdPares; j++) {
            if (vetorPares[i] < vetorPares[j]) {
                int temp = vetorPares[i];
                vetorPares[i] = vetorPares[j];
                vetorPares[j] = temp;
            }
        }
    }

    // Cadastro de produtos
    for (int i = 0; i < qtdDistintos; i++) {
        if (ocorrencias[i] % 2 != 0 && distintos[i] > 0) {
            cout << "\nNumero " << distintos[i]
                 << " apareceu " << ocorrencias[i] << " vezes.\n";

            for (int j = 0; j < distintos[i]; j++) {
                if (qtdProdutos >= 100) {
                    cout << "Limite de produtos atingido.\n";
                    break;
                }

                cout << "Nome do produto: ";
                cin.ignore();
                getline(cin, produtos[qtdProdutos]);

                cout << "Preco unitario: R$ ";
                cin >> precos[qtdProdutos];

                qtdProdutos++;
            }
        }
    }

    // Ordenar produtos por nome
    for (int i = 0; i < qtdProdutos - 1; i++) {
        for (int j = i + 1; j < qtdProdutos; j++) {
            if (produtos[i] > produtos[j]) {
                swap(produtos[i], produtos[j]);
                swap(precos[i], precos[j]);
            }
        }
    }

    cout << "\nNumeros informados:\n";
    for (int i = 0; i < 12; i++) {
        cout << numeros[i] << " ";
    }

    cout << "\n\nOcorrencias:\n";
    for (int i = 0; i < qtdDistintos; i++) {
        cout << distintos[i] << " aparece "
             << ocorrencias[i] << " vez(es).\n";
    }

    cout << "\nProdutos cadastrados:\n";
    for (int i = 0; i < qtdProdutos; i++) {
        cout << produtos[i] << " - R$ " << precos[i] << endl;
    }

    cout << "\nNumeros com ocorrencias pares (decrescente):\n";
    for (int i = 0; i < qtdPares; i++) {
        cout << vetorPares[i] << " ";
    }

    return 0;
}

