/**
* @file avl.cpp
* @description AVL Ağacı fonksiyonları, duğümleri AVL yöntemine göre dengeler.
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/

#include "avl.hpp"
#include "definitions.hpp"


		Avl::Avl(){
            yukseklik = 0 ;
            dugumsayisi = 0 ;
            kok = NULL;
        }
        Avl::Avl(Dugum *n){
            yukseklik = 0 ;
            dugumsayisi = 0 ;
            kok = n;          
        }
        Avl::~Avl(){
            delete kok ;
        }



        int Avl::ygetir(Dugum  *dugum ){ // Güncel Yükseklik değerini döndür.
            if (dugum == NULL ) return -1;
            if (dugum->yaprakmi()){
                
                return 0;
            }
            else
            {
                int solyukseklik = 0 ;
                int sagyukseklik = 0 ;

                solyukseklik = ygetir(dugum->sol);
                sagyukseklik = ygetir(dugum->sag);

                if (solyukseklik > sagyukseklik) 
                    return solyukseklik + 1; 
                else 
                    return sagyukseklik + 1;
            }
            
        }

         Dugum* Avl::solCocukIleDegistir(Dugum* &altDugum){
            if (altDugum == NULL ) return NULL;

            Dugum *tmp = altDugum->sol;
            altDugum->sol = tmp->sag;
            tmp->sag = altDugum;

            return tmp;

        }

        Dugum* Avl::sagCocukIleDegistir(Dugum* &altDugum){
            if (altDugum == NULL ) return NULL;

            Dugum *tmp = altDugum->sag;
            altDugum->sag = tmp->sol;
            tmp->sol = altDugum;
            

            return tmp;
        }

		Dugum* Avl::ekle(Dugum  *altDugum,  DogruKuyrugu *yeni){
            
            if (altDugum==NULL)
            {

                altDugum = new Dugum(yeni);
                dugumsayisi++;
                if (dugumsayisi == 1 ) this->kok = altDugum;
                altDugum->index = dugumsayisi;

                return altDugum;

            } else if (yeni->tuzunluk < altDugum->veri->tuzunluk)
            {
                //  cout <<" SOLA EKLE: " << yeni->tuzunluk  << " : " << altDugum->veri->tuzunluk << " ; "  <<  altDugum->sol << endl;
                 Dugum *tmpsol = ekle(altDugum->sol,yeni);
                if (tmpsol != NULL) altDugum->sol = tmpsol;

                if ((ygetir(altDugum->sol) - ygetir(altDugum->sag))  == 2 )
                {
                    Dugum *tmp1 = altDugum;

                    if (yeni->tuzunluk <= altDugum->sol->veri->tuzunluk)
                    {

                        // cout <<" Sol cocuk ile değiştir " << endl;
                        Dugum *tmpsol1 = solCocukIleDegistir(altDugum);
                        if (tmpsol1 != NULL) altDugum = tmpsol1;

                        
                    } else{
                        // cout <<" SAĞ sonra SOL cocuk ile değiştir " << endl;
                        Dugum *tmpsol2 = sagCocukIleDegistir(altDugum->sol);
                        if (tmpsol2 != NULL) altDugum->sol = tmpsol2;
                        Dugum *tmpsol3 = solCocukIleDegistir(altDugum);
                        if (tmpsol3 != NULL) altDugum = tmpsol3;
                    }

                    if (this->kok == tmp1)
                    {
                        // cout <<" KOK Degistir: " << endl;
                        // cout <<"eskisi: " << this->kok->veri->tuzunluk  << endl;
                        this->kok = altDugum;
                        // cout <<"yenisi: " << this->kok->veri->tuzunluk  << endl;
                    }
                }
                
            } else if (yeni->tuzunluk > altDugum->veri->tuzunluk) {
                // cout <<" SAGA EKLE: " << yeni->tuzunluk  << " : " << altDugum->veri->tuzunluk << " ; "  <<  altDugum->sag << endl;
                Dugum *tmpsag = ekle(altDugum->sag,yeni);
                if (tmpsag != NULL) altDugum->sag = tmpsag;

                if ((ygetir(altDugum->sag) - ygetir(altDugum->sol))  == 2 )
                {
                    Dugum *tmp2 = altDugum;
                 if (yeni->tuzunluk > altDugum->sag->veri->tuzunluk)
                    {
                        //  cout <<" SAG cocuk ile değiştir " << endl;
                         Dugum *tmpsag1 = sagCocukIleDegistir(altDugum);
                        if (tmpsag1 != NULL) altDugum = tmpsag1;
                    } else{
                        // cout <<" SOL sonra SAG cocuk ile değiştir " << endl;

                        Dugum *tmpsag2 = solCocukIleDegistir(altDugum->sag);
                        if (tmpsag2 != NULL) altDugum->sag = tmpsag2;

                        Dugum *tmpsag3 = sagCocukIleDegistir(altDugum);
                        if (tmpsag3 != NULL) altDugum = tmpsag3;
                    }
                    
                    if (this->kok == tmp2) 
                    {
                        // cout <<" KOK Degistir: " << endl;
                        // cout <<"eskisi: " << this->kok->veri->tuzunluk  << endl;
                        this->kok = altDugum;
                        // cout <<"yenisi: " << this->kok->veri->tuzunluk  << endl;
                    }
                    
                }
            } 
            
            
         return altDugum;
            
   
        }
        


		void Avl::postOrder(Dugum *altDugum){
            if(altDugum != NULL){
                postOrder(altDugum->sol);
                postOrder(altDugum->sag);
                cout << *altDugum->veri << endl;
            }
        }

		int Avl::yazdir(Dugum *altDugum){
            if(altDugum != NULL){
                


                int tmp = altDugum->veri->tuzunluk ;
                if (altDugum == this->kok) cout << "KOK: " << tmp << "  " ;
                else cout << "DUGUM: " << tmp << "  " << endl ;
                cout << "Yükseklik: " << ygetir(altDugum) << "  " << endl ;
                cout << "YAPRAK MI: " << altDugum->yaprakmi() << "  " << endl ;
                cout << "INDEX: " << altDugum->index << "  " << endl ;

                yazdir(altDugum->sol);
                yazdir(altDugum->sag) ;
                cout << "-- SAG SOL YAZILDI --" << endl;

                return tmp;
            }
        }

		void Avl::bellektemizle(Dugum *altDugum){
            if(altDugum != NULL){
                bellektemizle(altDugum->sol);
                bellektemizle(altDugum->sag);
                altDugum->veri->bellektemizle();
                delete altDugum;
            }
        }