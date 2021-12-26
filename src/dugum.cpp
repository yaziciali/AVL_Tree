/**
* @file dugum.cpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/

#include "dugum.hpp"


Dugum::Dugum  (DogruKuyrugu *veri, Dugum *sol, Dugum *sag){
    this->veri = veri;
    this->sol = sol;
    this->sag = sag;
    this->yukseklik = 0;

}

bool Dugum::yaprakmi(){
    if (sol == NULL && sag == NULL) return true;
}