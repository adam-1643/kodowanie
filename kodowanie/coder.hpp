//
//  coder.hpp
//  kodowanie
//
//  Created by Adam Stanislawski on 27.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#ifndef coder_hpp
#define coder_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

#include "kod.hpp"

class Coder : public Kod {
        
    virtual bool isDataValid(std::vector<int> data);
    virtual void formatData();

public:
    Coder();
    std::vector<int> encodeData(std::vector<int> data);
};

#endif /* coder_hpp */
