/**
* @file nokta.hpp
* @description Doğru Kuyruğu sınıfı için oluşturulan nokta düğümü
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef NOKTA_HPP
#define NOKTA_HPP
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