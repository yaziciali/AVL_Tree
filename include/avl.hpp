/**
* @file dogrukuyrugu.hpp
* @description Doğru Kuyruğu sınıfı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef AVL_HPP
#define AVL_HPP
#include "dugum.hpp"

class AvlGezici{
    public:
    Dugum *simdiki;
    AvlGezici();
    AvlGezici(Dugum *n);
    bool noktaVarmi() ;
    bool sonrakiVarmi() ;
    void ileri();
    void geri();
    Dugum *sonaGit();

};

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
		Dugum* ekle(Dugum  *altDugum,  DogruKuyrugu *yeni);
        void postOrder(Dugum *altDugum);
        int yazdir(Dugum *altDugum);
};



#endif