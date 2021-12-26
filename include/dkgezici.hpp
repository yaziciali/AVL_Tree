/**
* @file dkgezici.hpp
* @description Doğru Kuyruğu için gezici sınıfı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
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