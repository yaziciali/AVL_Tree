/**
* @file DogruKuyrugu.cpp
* @description Doğru Kuyruğu sınıfı
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
            if (dugum == NULL ) return 0;
            if (dugum->yaprakmi()){
                
                return 0;
            }
            else
            {
                int solyukseklik = 0 ;
                int sagyukseklik = 0 ;

                if (dugum->sol != NULL) solyukseklik = ygetir(dugum->sol);
                if (dugum->sag != NULL) sagyukseklik = ygetir(dugum->sag);

                if (solyukseklik > sagyukseklik) return solyukseklik + 1; 
                else return sagyukseklik + 1;
            }
            
        }

        Dugum* Avl::solCocukIleDegistir(Dugum *altDugum){
            if (altDugum == NULL ) return NULL;
            Dugum *tmp = altDugum->sol;
            altDugum->sol = tmp->sag;
            tmp->sag = altDugum;
            altDugum->yukseklik = ygetir(altDugum);
            tmp->yukseklik = max(ygetir(tmp->sol),altDugum->yukseklik)+1 ;
            return tmp;

        }

        Dugum* Avl::sagCocukIleDegistir(Dugum *altDugum){
            if (altDugum == NULL ) return NULL;
            Dugum *tmp = altDugum->sag;
            altDugum->sag = tmp->sol;
            tmp->sol = altDugum;
            altDugum->yukseklik = ygetir(altDugum);
            tmp->yukseklik = max(ygetir(tmp->sag),altDugum->yukseklik)+1 ;
            return tmp;
        }

		Dugum* Avl::ekle(Dugum  *altDugum,  DogruKuyrugu *yeni){
            
            if (altDugum==NULL)
            {

                altDugum = new Dugum(yeni);
                dugumsayisi++;
                if (dugumsayisi == 1 ) this->kok = altDugum;

                //cout <<" altDugum NULL iken: " << *altDugum->veri << " dugumsayisi " << dugumsayisi << endl;
            } else if (yeni->tuzunluk < altDugum->veri->tuzunluk)
            {
                 //cout <<" SOLA EKLE: " << yeni->tuzunluk  << " : " << altDugum->veri->tuzunluk << " ; "  <<  altDugum->sol << endl;
                altDugum->sol = ekle(altDugum->sol,yeni);
                if ((ygetir(altDugum->sol) - ygetir(altDugum->sag))  == 2 )
                {
                    if (yeni->tuzunluk < altDugum->sol->veri->tuzunluk)
                    {
                     //   cout <<" Sol cocuk ile değiştir " << endl;
                        altDugum = solCocukIleDegistir(altDugum);
                    } else{
                     //   cout <<" SAĞ sonra SOL cocuk ile değiştir " << endl;
                        altDugum->sol = sagCocukIleDegistir(altDugum->sol);
                        altDugum = solCocukIleDegistir(altDugum);
                    }
                    
                }
                
            } else if (yeni->tuzunluk > altDugum->veri->tuzunluk) {
               // cout <<" SAGA EKLE: " << yeni->tuzunluk  << " : " << altDugum->veri->tuzunluk << " ; "  <<  altDugum->sag << endl;
                altDugum->sag = ekle(altDugum->sag,yeni);
                
                if ((ygetir(altDugum->sag) - ygetir(altDugum->sol))  == 2 )
                {
                    if (yeni->tuzunluk < altDugum->sag->veri->tuzunluk)
                    {
                         //cout <<" SAG cocuk ile değiştir " << endl;
                        altDugum = sagCocukIleDegistir(altDugum);
                    } else{
                       // cout <<" SOL sonra SAG cocuk ile değiştir " << endl;
                        altDugum->sag = solCocukIleDegistir(altDugum->sag);
                        altDugum = sagCocukIleDegistir(altDugum);
                    }
                    
                }
            }
            

            if (altDugum != NULL ) 
            {
                altDugum->yukseklik = ygetir(altDugum);
             //    cout <<"Yükseklik: " << altDugum->yukseklik << endl;
            }

            return altDugum;
            
        }
        


		void Avl::postOrder(Dugum *altDugum){
            if(altDugum != NULL){
                postOrder(altDugum->sol);
                postOrder(altDugum->sag);
                cout <<"Dugum: " << *altDugum->veri << endl;
            }
        }


