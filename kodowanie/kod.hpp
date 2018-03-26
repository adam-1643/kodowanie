//
//  kod.hpp
//  kodowanie
//
//  Created by Adam Stanislawski on 26.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#ifndef kod_hpp
#define kod_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

class Kod {
    static const int n = 8;
    static const int k = 3;
    const int gen[n-k+1] = {
        //1,      //x^6
        1,      //x^5
        1,      //x^4
        0,      //x^3
        0,      //x^2
        1,      //x^1
        1,      //x^0
    };
    
    int genMatrix[k][n];
   // std::vector<int> remainder[k] = {std::vector<int>(n,-1)};
    
    bool correct = 0;
    bool correctable = 0;
    std::vector<int> message = std::vector<int>(k,-1);
    std::vector<int> code = std::vector<int>(n,-1);
    int checkValidity();
    bool isDataValid(std::vector<int> data, bool type);
    void formatData();
    std::vector<int> division(std::vector<int> poly1, std::vector<int> poly2);
public:
    Kod();
    std::vector<int> loadData(std::string data);
    std::vector<int> encodeData(std::vector<int> data);
    std::vector<int> decodeData(std::vector<int> data);
    bool isCorrect();
    bool isCorrectable();
};

#endif /* kod_hpp */
