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
    
    int noOfErrors = 0;                 //liczba błędów
    int swap = 0;                       //liczba przesunięć cyklicznych
    std::vector<int> syndrome = std::vector<int>(n-k,0);        //wektor syndromu
    
    std::vector<int> checkValidity();   //sprawdzenie poprawności ciągu kodowego
    void cyclicSwap(bool dir);          //przesunięcie cykliczne
    void doCorrection();                //korekcja kodu
    
    std::string convertToString(std::vector<int> data);     //formatowanie wektora na tekst
    virtual bool isDataValid(std::vector<int> data);    //sprawdzanie poprawności wprowadzanych danych
    virtual void formatData();                          //formatowanie wyniku na tekst
public:
    Decoder();
    std::vector<int> decodeData(std::vector<int> data);     //dekodowanie danych
    void reset();                       //resetowanie danych
    int getCode();                      //pobieranie kodu operacji
    std::string getCorrectCode();       //pobieranie prawidłowego słowa kodowego
};

#endif /* decoder_hpp */
