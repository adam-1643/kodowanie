//
//  kod.cpp
//  kodowanie
//
//  Created by Adam Stanislawski on 26.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#include "kod.hpp"

Kod::Kod() {
}

void Kod::createGenMatrix() {
    std::vector<int> rem = std::vector<int>(n,-1);
    std::vector<int> genVec = std::vector<int>(n-k+1,1);
    
    //wektor z wielomianem generującym
    for(int i = 0; i < n-k+1; i++) {
        genVec.at(i) = gen[i];
    }
    
    // wartości początkowe macierzy generującej
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            genMatrix[i][j] = -1;
        }
    }
    
    for(int i = 0; i < k; i++) {
        
        //reszta z dzielenia x^n przez wielomian generujący
        rem = std::vector<int>(n-i,0);
        rem.at(0) = 1;
        rem = division(rem, genVec);
        
        //macierz generująca stworzona wg wzoru na macierz systematyczną z wielomianu
        for(int j = 0; j < n; j++) {
            genMatrix[i][j] = i == j ? 1 : 0;
            genMatrix[i][j]+= j >= i ? rem.at(j-i) : 0;
        }
    }
}

void Kod::createMatrixH() {

    //wiersze z macierzy generującej
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n-k; j++) {
            matrixH[i][j] = genMatrix[i][j+k];
        }
    }
    
    //macierz jednostkowa na koniec
    for(int i = k; i < n; i++) {
        for(int j = 0; j < n-k; j++) {
            matrixH[i][j] = i-k == j ? 1 : 0;
        }
    }
}

std::vector<int> Kod::loadData(std::string data) {
    
    std::vector<int> vec;
    for(int i = 0; i < data.size(); i++) {
        vec.push_back(data.at(i) - '0');
    }
    return vec;
}

std::vector<int> Kod::division(std::vector<int> poly1, std::vector<int> poly2) {
    
    int p1Size = int(poly1.size());
    int p2Size = int(poly2.size());
    
    //algorytm binarnego dzielenia wielomianów
    for(int i = 0; i < p1Size-p2Size+1; i++) {
        if(poly1.at(i) == 0) continue;

        for(int j = 0; j < p2Size; j++) {
            poly1.at(j+i) = (poly1.at(j+i) + poly2.at(j)) % 2;
        }
    }
    
    return poly1;
}

void Kod::formatOutputData(std::vector<int> data) {
    
    result = "";
    for(int i = 0; i < data.size(); i++) {
        result.append(std::to_string(data.at(i)));
    }
}

std::string Kod::getResult() {
    return result;
}

int Kod::calcT() {
    int ones[k] = {0};
    
    //liczenie odległości Hamminga dla wierszy niebędących wierszami macierzy jednostkowej
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n-k; j++) {
            if(matrixH[i][j] == 1) ones[i]++;
        }
    }
    
    //najmniejsza z odległości Hamminga jest odległością minimalną
    int min = ones[0];
    for(int i = 1; i < k; i++) {
        if(ones[i] < min) min = ones[i];
    }
    
    return min/2;
}

void Kod::printGenMatrix() {
    
    std::cout << "Macierz generująca:\n";
    for(int i = 0; i < n+3; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
    
    for(int i = 0; i < k; i++) {
        std::cout << "|";
        for(int j = 0; j < n; j++) {
            std::cout << genMatrix[i][j];
            if(j == k-1) std::cout << "|";
        }
        std::cout << "|\n";
    }
    
    for(int i = 0; i < n+3; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
    
}

void Kod::printMatrixH() {
    
    std::cout << "Macierz H transponowana: \n";
    for(int i = 0; i < n-k+2; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
    
    for(int i = 0; i < k; i++) {
        std::cout << "|";
        for(int j = 0; j < n-k; j++) {
            std::cout << matrixH[i][j];
        }
        std::cout << "|\n";
    }
    
    for(int i = 0; i < n-k+2; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
    
    for(int i = k; i < n; i++) {
        std::cout << "|";
        for(int j = 0; j < n-k; j++) {
            std::cout << matrixH[i][j];
        }
        std::cout << "|\n";
    }
    
    for(int i = 0; i < n-k+2; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
    
}

void Kod::printKodParam() {
    std::cout << "Kod (" << n << ", " << k << ", " << t << ")\n";
}




