#include "node.h"
#include <iostream>

int main() {
    // Creación de los punteros a las filas de la matriz
    uint8_t** data = new uint8_t*[3];
    for (int i = 0; i < 3; i++) {
        data[i] = new uint8_t[3];
    }

    // Inicialización de los valores de la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = 1;
        }
    }
  
    // Creación de un objeto de tipo Node
    Node* node = new Node(data);
    node->toString();
    return 0;
}

