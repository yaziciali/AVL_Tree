/**
* @file iterator.hpp
* @description Bağıl liste için oluşturulan nodelar arası gezebilmek için oluşturulan iterator yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "node.hpp"
class Iterator{
    public:
    Node *current;
    Iterator();
    Iterator(Node *item);
    bool hasNoItem() const;
    bool hasNext() const;
    void moveNext();
    void movePrev();

};

#endif