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
    for(int i = 0; i < n-k+1; i++) {
        genVec.at(i) = gen[i];
    }
    for(int i = 0; i < k; i++) {
        
        for(int j = 0; j < n; j++) {
            genMatrix[i][j] = -1;
        }
    }
    
    for(int i = 0; i < k; i++) {
        
        rem = std::vector<int>(n-i,0);
        rem.at(0) = 1;
        rem = division(rem, genVec);
        
        for(int j = 0; j < n; j++) {
            genMatrix[i][j] = i == j ? 1 : 0;
            genMatrix[i][j]+= j >= i ? rem.at(j-i) : 0;
            std::cout << genMatrix[i][j];
            if(j == k-1) std::cout << "|";
        }
        std::cout << "\n";
    }
}

void Kod::createMatrixH() {
    std::cout << "\n-------\n\n";
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n-k; j++) {
            matrixH[i][j] = genMatrix[i][j+k];
            std::cout << matrixH[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "----\n";
    for(int i = k; i < n; i++) {
        for(int j = 0; j < n-k; j++) {
            matrixH[i][j] = i-k == j ? 1 : 0;
            std::cout << matrixH[i][j];
        }
        std::cout << "\n";
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
    
    int l = int(poly1.size());
    int g = int(poly2.size());
    
    for(int i = 0; i < l-g+1; i++) {
        if(poly1.at(i) == 0) continue;
        for(int j = 0; j < g; j++) {
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





