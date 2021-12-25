/**
* @file nokta.cpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/

#include "nokta.hpp"

Nokta::Nokta  (int x, int y , int z, Nokta *prev, Nokta *next){
    this->x = x;
    this->y = y;
    this->z = z;
    this->orjineyakinlik = sqrt(x*x + y*y + z*z);
    this->next = next;
    this->prev = prev;
}