/**
* @file node.cpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/

#include "node.hpp"

Node::Node (const string& item, Node *prev, Node *next){
    this->item = item;
    this->next = next;
    this->prev = prev;
}