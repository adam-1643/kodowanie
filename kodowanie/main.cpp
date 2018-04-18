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
#include "coder.hpp"
#include "decoder.hpp"

std::string kody[10] {
    "100100",
    "110111",
    "110001",
    "010111",
    "011010",
    "101111",
    "111100",
    "110011",
    "001010",
    "010101",
};

int main() {
    
    Decoder dec;
    std::string a;
    
    dec.printGenMatrix();
    dec.printMatrixH();
    
    while(1){
        
        std::cout << "Podaj: ";
        std::cin >> a;
        dec.decodeData(dec.loadData(a));
        
        if(dec.getCode() == 0) {
            std::cout << "Kod poprawny\n";
            std::cout << "Informacja: " << dec.getResult();
        }
        if(dec.getCode() == -2) {
            std::cout << "Zle wprowadzone\n";
            std::cout << dec.getResult();
        }
        if(dec.getCode() == -1) {
            std::cout << "Niekorygowalny\n";
            std::cout << dec.getResult();
        }
        if(dec.getCode() > 0)  {
            std::cout << "Korygowalny\n";
            std::cout << "Informacja: " << dec.getResult();
            std::cout << "\nPoprawny kod: " << dec.getCorrectCode();
        }
        
        std::cout << "\n";
        
    }
    
    return 0;
}
