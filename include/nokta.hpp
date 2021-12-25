/**
* @file nokta.hpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <cmath>
using namespace std;

class Nokta{
    public:
    int x;
    int y;
    int z;
    int orjineyakinlik;
    Nokta *next;
    Nokta *prev;
    Nokta  (int x, int y , int z, Nokta *prev=NULL, Nokta *next=NULL);

};

#endif