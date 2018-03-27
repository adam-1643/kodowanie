//
//  decoder.cpp
//  kodowanie
//
//  Created by Adam Stanislawski on 27.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#include "decoder.hpp"

Decoder::Decoder() {
    createGenMatrix();
    createMatrixH();
}

std::vector<int> Decoder::checkValidity() {
    for(int i = 0; i < n-k; i++) {
        for(int j = 0; j < n; j++) {
            syndrome.at(i) += code.at(j)*matrixH[j][i];
        }
        syndrome.at(i) = syndrome.at(i)%2;
    }
    
    for(int i = 0; i < n-k; i++) {
        if(syndrome.at(i) == 1) {
            noOfErrors++;
        }
    }
    
    if(noOfErrors == 0) {
        correct = 1;
    }
    if(noOfErrors <= t) {
        correct = 0;
        doCorrection();
    }
    if(noOfErrors > t) {
        correct = 0;
        tryCorrection();
    }
    
    return syndrome;
}

bool Decoder::isCorrect() {
    return correct;
}

bool Decoder::isCorrectable() {
    return correctable;
}

void Decoder::doCorrection() {
    for(int i = k; i < n; i++) {
        code.at(i) = ( code.at(i) + syndrome.at(i-k) ) % 2;
    }
}

void Decoder::tryCorrection() {
    
}

bool Decoder::isDataValid(std::vector<int> data) {

    if(data.size() != n) {
        errorMessage = "Błędna długość słowa kodowego!";
        return false;
    }
    
    for(int i = 0; i < data.size() ; i++) {
        if(data.at(i) != 0 && data.at(i) != 1) {
            errorMessage = "Błędny znak w ciągu kodowym!";
            return false;
        }
    }
    
    return true;
}

void Decoder::formatData() {
    
    for(int i = 0; i < k; i++) {
        message.at(i) = message.at(i)%2;
    }
    formatOutputData(message);
}

std::vector<int> Decoder::decodeData(std::vector<int> data) {
    
    reset();
    if(!isDataValid(data)) {
        result = errorMessage;
        return std::vector<int>(1,-1);
    }
    code = data;
    
    checkValidity();
    formatData();
    return message;
}

void Decoder::reset() {
    code = std::vector<int>(n,0);
    message = std::vector<int>(k,0);
    correct = 1;
    correctable = 1;
    noOfErrors = 0;
    syndrome = std::vector<int>(n-k,0);
}

