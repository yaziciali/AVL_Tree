/**
* @file dugum.cpp
* @description AVL Ağaç sınıfı için düğüm sınıfı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
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

    if (sol == NULL && sag  == NULL) {

        return true;
    }  
    else
    {

        return false;
    }
    
    
}