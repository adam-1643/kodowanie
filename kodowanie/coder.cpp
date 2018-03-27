//
//  coder.cpp
//  kodowanie
//
//  Created by Adam Stanislawski on 27.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#include "coder.hpp"

Coder::Coder() {
    createGenMatrix();
    createMatrixH();
}

std::vector<int> Coder::checkValidity() {
    for(int i = 0; i < n-k; i++) {
        for(int j = 0; j < n; j++) {
            syndrome.at(i) += code.at(j)*matrixH[j][i];
        }
        syndrome.at(i) = syndrome.at(i)%2;
    }
    correct = 1;
    correctable = 1;
    
    for(int i = 0; i < n-k; i++) {
        if(syndrome.at(i) == 1) {
            correct = 0;
            correctable = 0;
        }
    }
    
    return syndrome;
}

bool Coder::isCorrect() {
    return correct;
}

bool Coder::isCorrectable() {
    return correctable;
}

bool Coder::isDataValid(std::vector<int> data) {
    
    if(data.size() != k) return false;

    for(int i = 0; i < data.size() ; i++) {
        if(data.at(i) != 0 && data.at(i) != 1) return false;
    }
    
    return true;
}

void Coder::formatData() {
    
    for(int i = 0; i < n; i++) {
        message.at(i) = message.at(i)%2;
    }
}

std::vector<int> Coder::encodeData(std::vector<int> data) {
    
    if(!isDataValid(data)) {
        return std::vector<int>(1,-1);
    }
    code = std::vector<int>(n,0);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            if(data.at(j) == 1 && genMatrix[j][i] == 1) code.at(i)++;
        }
    }
    formatData();
    
    return code;
}

std::vector<int> Coder::loadData(std::string data) {
    
    std::vector<int> vec;
    
    for(int i = 0; i < data.size(); i++) {
        vec.push_back(data.at(i) - '0');
    }
    
    return vec;
}

std::vector<int> Coder::division(std::vector<int> poly1, std::vector<int> poly2) {
    
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

std::string Coder::formatOutputData(std::vector<int> data) {
    std::string output;
    
    for(int i = 0; i < data.size(); i++) {
        
        output.append(std::to_string(data.at(i)));
        
    }
    
    return output;
}
