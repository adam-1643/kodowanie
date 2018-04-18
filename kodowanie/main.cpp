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
    
    Decoder k;
    std::string a;
    
   // std::string codes[10];
   // Coder zz;
   // zz.dd();
//    for(int i = 0; i < 10; i++) {
//        zz.encodeData(zz.loadData(kody[i]));
//        codes[i] = zz.getResult();
//        std::cout << codes[i] << "\n";
//    }
//
//    for(int i = 0; i < 10; i++) {
//        k.decodeData(k.loadData(codes[i]));
//        //codes[i] = zz.getResult();
//        std::cout << k.getResult() << "\n";
//    }
    
    while(1){
        
        std::cout << "Podaj: ";
        std::cin >> a;
        k.decodeData(k.loadData(a));
        
        if(k.getCode() == 0) {
            std::cout << "Kod poprawny\n";
            std::cout << "Informacja: " << k.getResult();
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
            std::cout << "Informacja: " << k.getResult();
            std::cout << "\nPoprawny kod: " << k.getCorrectCode();
        }
        
        std::cout << "\n";
        
    }
    
    return 0;
}
