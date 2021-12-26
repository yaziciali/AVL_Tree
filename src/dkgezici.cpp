/**
* @file dkgezici.cpp
* @description Doğru Kuyruğu için gezici sınıfı fonksiyonları
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#include "definitions.hpp"
#include "dkgezici.hpp"

    DkGezici::DkGezici(){
        this->simdiki = NULL;
    }
    DkGezici::DkGezici(Nokta *n){
        this->simdiki = n;
    }
    bool DkGezici::noktaVarmi(){
        return this->simdiki != NULL;
    }
    bool DkGezici::sonrakiVarmi(){
        return this->simdiki->next != NULL;
    }
    void DkGezici::ileri(){
        if(!noktaVarmi()) throw Error_NoItem;
        this->simdiki = this->simdiki->next;
    }
    void DkGezici::geri(){
        if(!noktaVarmi()) throw Error_NoItem;
        this->simdiki = this->simdiki->prev;
    }

     Nokta *DkGezici::sonaGit(){
         while (sonrakiVarmi())
         {
             ileri();
         }
         return simdiki;
     }