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
protected:
    static const int n = 7;     //długość słów kodowych
    static const int k = 4;     //długość słów informacyjnych
    int t = 0;                  //zdolność korekcyjna
    const int gen[n-k+1] = {    //wielomian generujący
        //1,                  //x^10
        //0,                  //x^9
       // 1,                  //x^8
       // 1,                  //x^7
       // 1,                  //x^6
       // 0,                  //x^5
      //  1,                  //x^4
        1,                  //x^3
        0,                  //x^2
        1,                  //x^1
        1,                  //x^0
    };
    
    int genMatrix[k][n];        //macierz generująca kod systematyczny
    int matrixH[n][n-k];        //macierz H transponowana
    
    std::string result;         //wynik operacji
    std::string errorMessage;   //wiadomość o błędzie, jeśli wystąpił
    
    std::vector<int> message;   //wektor ciągu informacyjnego
    std::vector<int> code;      //wektor ciągu kodowego

    virtual bool isDataValid(std::vector<int> data) {return true;};         //sprawdzanie poprawności wprowadzanych danych
    virtual void formatData() {};                                           //formatowanie wyniku na tekst
    
    std::vector<int> division(std::vector<int> poly1, std::vector<int> poly2);      //dzielenie wielomianów binarnie
public:
    Kod();
    std::vector<int> loadData(std::string data);        //formatoawnie danych z tekstu na wektor
    void formatOutputData(std::vector<int> data);       //formatowanie danych z wektora na tekst
    void createGenMatrix();                             //tworzenie macierzy generującej
    void createMatrixH();                               //tworzenie macierzy H transponowanej
    
    std::string getResult();                            //pobieranie danych ze słowem lub błędem
    int calcT();
};

#endif /* kod_hpp */
