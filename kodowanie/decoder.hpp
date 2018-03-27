//
//  decoder.hpp
//  kodowanie
//
//  Created by Adam Stanislawski on 27.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#ifndef decoder_hpp
#define decoder_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

#include "kod.hpp"

class Decoder : public Kod {
    
    int noOfErrors = 0;
    int swap = 0;

    std::vector<int> syndrome = std::vector<int>(n-k,0);
    
    std::vector<int> checkValidity();
    virtual bool isDataValid(std::vector<int> data);
    virtual void formatData();
    
    void cyclicSwap(bool dir);
    
    std::string convertToString(std::vector<int> data);
public:
    Decoder();
    std::vector<int> decodeData(std::vector<int> data);
    bool isCorrect();
    bool isCorrectable();
    void doCorrection();
    void tryCorrection();
    void reset();
    int getCode();
    std::string getCorrectCode();
};

#endif /* decoder_hpp */
