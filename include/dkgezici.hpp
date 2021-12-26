/**
* @file nokta.hpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef DKGEZICI_HPP
#define DKGEZICI_HPP
#include "nokta.hpp"
using namespace std;

class DkGezici{
    public:
    Nokta *simdiki;
    DkGezici();
    DkGezici(Nokta *n);
    bool noktaVarmi() ;
    bool sonrakiVarmi() ;
    void ileri();
    void geri();
    Nokta *sonaGit();

};
#endif