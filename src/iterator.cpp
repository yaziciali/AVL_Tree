/**
* @file iterator.cpp
* @description Bağıl liste için oluşturulan nodelar arası gezebilmek için oluşturulan iterator yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/

#include "iterator.hpp"
#include "definitions.hpp"
    Iterator::Iterator(){
        this->current = NULL;
    }

    Iterator::Iterator(Node *item)
    {
        this->current = item;
    }

    bool Iterator::hasNoItem() const{
        return this->current == NULL;
    }

    bool Iterator::hasNext() const{
        return this->current->next != NULL;
    }

    void Iterator::moveNext(){
        if(hasNoItem()) throw Error_NoItem;
        this->current = this->current->next;
    }
    void Iterator::movePrev(){
        if(hasNoItem()) throw Error_NoItem;
        this->current = this->current->prev;
    }