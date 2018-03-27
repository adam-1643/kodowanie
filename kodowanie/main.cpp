//
//  main.cpp
//  kodowanie
//
//  Created by Adam Stanislawski on 26.03.2018.
//  Copyright © 2018 Adam Stanislawski. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "kod.hpp"
#include "coder.hpp"
#include "decoder.hpp"

int main() {
    
    Decoder k;
    std::string a;
    while(1){
        std::cout << "Podaj: ";
        std::cin >> a;
        k.decodeData(k.loadData(a));
        
        if(k.getCode() == 0) {
            std::cout << "Kod poprawny\n";
            std::cout << k.getResult();
        }
        if(k.getCode() == -2) {
            std::cout << "Zle wprowadzone\n";
            std::cout << k.getResult();
        }
        if(k.getCode() == -1) {
            std::cout << "Niekorygowalny\n";
            std::cout << k.getResult();
        }
        if(k.getCode() > 0)  {
            std::cout << "Korygowalny\n";
            std::cout << k.getResult();
            std::cout << "\n" << k.getCorrectCode();
        }
        
        std::cout << "\n";
        
    }
    
    return 0;
}
