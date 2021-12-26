/**
* @file nokta.cpp
* @description Doğru Kuyruğu sınıfı için oluşturulan nokta düğümü
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
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