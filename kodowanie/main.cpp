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

void division(std::vector<int> poly1, std::vector<int> poly2) {
    
    int l = poly1.size();
    int g = poly2.size();
    
    for(int i = 0; i < l-g+1; i++) {
        
        if(poly1.at(i) == 0) continue;
        
        for(int j = 0; j < g; j++) {
            poly1.at(j+i) = (poly1.at(j+i) + poly2.at(j)) % 2;
        }
        
    }
    
    for(int i = 0; i < l; i++) {
        std::cout << poly1.at(i) << " ";
    }

    std::cout << std::endl;
    
}

int main() {
    
    Kod k;
    std::string str;
    std::cout << "Wprowadź slowo informacyjne: ";
    std::cin >> str;
    
    std::cout << k.formatOutputData(k.encodeData(k.loadData(str)));
    if(k.isCorrect()) {
        std::cout << "Kod poprawny";
    } else {
        std::cout << "Kod bledny";
    }
    
   // std::string aa;
    //std::cin >> aa;
    //k.loadData(aa);
//    std::vector<int> a = std::vector<int>(1,1);
//
//    a = k.encodeData({1,0,1,1,0,1});
//
//    for(int i = 0; i < a.size(); i++)
//    {
//        std::cout << a.at(i) << " ";
//    }
//    std::cout << "\n";

    //division({1,1,0,1,1},{1,1,0,1});
    
    return 0;
}
