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
    
    Coder k;
    std::string a;
    while(1){
    std::cout << "Podaj: ";
    std::cin >> a;
    k.encodeData(k.loadData(a));
    std::cout << k.getResult() << "\n";
    }
    
//    Decoder k;
//    std::string str;
//    std::cout << "Wprowadź slowo informacyjne: ";
//    std::cin >> str;
//
//    //std::cout << k.formatOutputData(k.decodeData(k.loadData(str)));
//    if(k.isCorrect()) {
//        std::cout << "Kod poprawny";
//    } else {
//        std::cout << "Kod bledny";
//    }
//
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
