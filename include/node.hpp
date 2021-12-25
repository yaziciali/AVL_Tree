/**
* @file node.hpp
* @description Bağıl liste için oluşturulan node yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
using namespace std;

class Node{
    public:
    int item;
    Node *next;
    Node *prev;
    Node (const string& item=string(), Node *prev=NULL, Node *next=NULL);

};

#endif