/**
* @file nokta.hpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include <cmath>
#include "dogrukuyrugu.hpp"
using namespace std;

class Dugum{
    public:
    DogruKuyrugu *veri;
    Dugum *sol;
    Dugum *sag;
    int yukseklik;
    int index;
    Dugum  ( DogruKuyrugu *veri, Dugum *sol=NULL, Dugum *sag=NULL);
    bool yaprakmi(); //Yaprak mı?
};

#endif