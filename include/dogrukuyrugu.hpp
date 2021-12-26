/**
* @file dogrukuyrugu.hpp
* @description Doğru Kuyruğu sınıfı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP
#include "nokta.hpp"
#include "dkgezici.hpp"


class DogruKuyrugu{
	private:
		int sayi;
        int xo; // Önceki X
        int yo; // Önceki y
        int zo; // Önceki z

		Nokta *kb; // Kuyruk Başlangıcı
		Nokta *ks; // Kuyruk Sonu

	public:
        int tuzunluk; // Toplam Uzunluk
		DogruKuyrugu();
        DogruKuyrugu(Nokta *n);
        ~DogruKuyrugu();
		bool bosmu();
		int noktasayisi();
        DkGezici ilkiniAl();
        DkGezici sonuAl();
		void ekle(Nokta  *yeninokta);
        double toplamUzunluk();
        

		friend ostream& operator<<(ostream& screen, DogruKuyrugu& item);

};



#endif