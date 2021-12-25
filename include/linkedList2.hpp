/**
* @file linkedList2.hpp
* @description Eleman ekleme ve çıkarmada bir dizi gibi davranan çift yönlü Bağıl liste yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "iterator.hpp"

class LinkedList2{
	private:
		Node *currentItem; // Current Item
		int count;
        int index;
		Node *beginList;
		Node *endList;

	public:
		LinkedList2();
		bool isEmpty() const;
		int getCount() const;
		string getItem() const;

		Iterator goFirst() ;
        Iterator goLast() ;

		void addItem( const string&  newItem);
		void addItem( const string&  newItem,int index);
		void remove();
		void remove(int index);

		void clear();
		friend ostream& operator<<(ostream& screen, LinkedList2& item);
};


#endif