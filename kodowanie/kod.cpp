//
//  kod.cpp
//  kodowanie
//
//  Created by Adam Stanislawski on 26.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#include "kod.hpp"

Kod::Kod() {
    
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

bool Kod::isCorrect() {
    return correct;
}

bool Kod::isCorrectable() {
    return correctable;
}

bool Kod::isDataValid(std::vector<int> data, bool type) {
    
    if(type == 0) {
        if(data.size() != k) return false;
    }
    if(type == 1) {
        if(data.size() != n) return false;
    }
    
    for(int i = 0; i < data.size() ; i++) {
        if(data.at(i) != 0 && data.at(i) != 1) return false;
    }
    
    return true;
}

void Kod::formatData() {
    
    for(int i = 0; i < n; i++) {
        code.at(i) = code.at(i)%2;
    }
    
//    for(int i = 0; i < n; i++) {
//        message.at(i) = message.at(i)%2 + 1;
//    }
    
}

std::vector<int> Kod::encodeData(std::vector<int> data) {
    
    if(!isDataValid(data, 0)) {
        return std::vector<int>(1,-1);
    }
    code = std::vector<int>(n,0);
    
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n-k+1; j++) {
            if(data.at(k-1-i) == 1 && gen[n-k-j] == 1) code.at(n-1-i-j)++;
        }
    }
    formatData();
    return code;
}

std::vector<int> Kod::decodeData(std::vector<int> data) {
    
    if(!isDataValid(data, 1)) {
        return std::vector<int>(1,-1);
    }
        
    return message;
}

std::vector<int> Kod::loadData(std::string data) {
    
    std::vector<int> vec;
    
    for(int i = 0; i < data.size(); i++) {
        vec.push_back(data.at(i) - '0');
    }
    
    return vec;
}

std::vector<int> Kod::division(std::vector<int> poly1, std::vector<int> poly2) {
    
    int l = poly1.size();
    int g = poly2.size();
    
    for(int i = 0; i < l-g+1; i++) {
        if(poly1.at(i) == 0) continue;
        for(int j = 0; j < g; j++) {
            poly1.at(j+i) = (poly1.at(j+i) + poly2.at(j)) % 2;
        }
    }
    
//    for(int i = 0; i < l; i++) {
//        std::cout << poly2.at(i) << " ";
//    }
//
//    std::cout << std::endl;
    return poly1;
}

