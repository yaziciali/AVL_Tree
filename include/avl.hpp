/**
* @file avl.hpp
* @description AVL Ağacı sınıfı, duğümleri AVL yöntemine göre dengeler.
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef AVL_HPP
#define AVL_HPP
#include "dugum.hpp"


class Avl{
	private:
		int yukseklik;
        int dugumsayisi ;



	public:
        Dugum *kok; // Kök Düğüm
         double tuzunluk; // Toplam Uzunluk
		Avl();
        Avl(Dugum *n);
        ~Avl();


        int ygetir(Dugum  *dugum); //Düğümün güncel yüksekliğini getir
        Dugum* solCocukIleDegistir(Dugum* &altDugum);
        Dugum* sagCocukIleDegistir(Dugum* &altDugum);
		Dugum* ekle(Dugum  *altDugum,  DogruKuyrugu *yeni); // Düğümü koyacağı yeri arayarak oraya ekler, gerektiğinde dengeler
        void postOrder(Dugum *altDugum); // Post order yazdırma fonksiyonu
        int yazdir(Dugum *altDugum);
        void bellektemizle(Dugum *altDugum);
};



#endif