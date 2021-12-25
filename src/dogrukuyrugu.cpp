/**
* @file DogruKuyrugu.cpp
* @description Doğru Kuyruğu sınıfı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/

#include "dogrukuyrugu.hpp"
#include "definitions.hpp"
    DogruKuyrugu::DogruKuyrugu(){
        this->kb = NULL;
        this->ks = NULL;
        sayi = 0;
    }

    DogruKuyrugu::~DogruKuyrugu(){ //Bellek temizliği

    if (this->bosmu()) return;

    DkGezici gezici = this->ilkiniAl();

    do {
        
        gezici.ileri();
        delete gezici.simdiki->prev;
    } while ( gezici.sonrakiVarmi());
    delete gezici.simdiki;

    }

    DogruKuyrugu::DogruKuyrugu(Nokta *n)
    {
        this->kb = n;
        this->ks = n;
        sayi = 1;
    }

    bool DogruKuyrugu::bosmu() {
        if (sayi == 0)
        {
            return true;
        } else {
            return false;
        }
        
    }
	int DogruKuyrugu::noktasayisi(){
        return sayi;
    }

    DkGezici DogruKuyrugu::ilkiniAl(){
        if(this->bosmu()) throw Error_isEmpty;

        return DkGezici(this->kb);  
    }

    DkGezici DogruKuyrugu::sonuAl(){
        if(this->bosmu()) throw Error_isEmpty;

        return DkGezici(this->ks);  
    }

	void DogruKuyrugu::ekle( Nokta  *yeninokta){
        bool eklendi = false;
        if (this->kb == NULL)
        {
        this->kb = yeninokta;
        this->ks = yeninokta;
        sayi = 1 ;
        } else
        {
            DkGezici gezici = this->ilkiniAl();
            while ( gezici.noktaVarmi() ){
                cout << "yeni_yakinlik: " << yeninokta->orjineyakinlik << " -> simdiki_yakinlik: " << gezici.simdiki->orjineyakinlik << endl;
            if (yeninokta->orjineyakinlik <= gezici.simdiki->orjineyakinlik)
            {
                yeninokta->prev = gezici.simdiki->prev;
                yeninokta->next = gezici.simdiki;
                
                

                if (yeninokta->prev == NULL)
                {
                    this->kb = yeninokta;
                } else {
                    gezici.simdiki->prev->next = yeninokta;
                }

                gezici.simdiki->prev = yeninokta;

                    this->ks = gezici.sonaGit();

                eklendi = true ;           
            }
            

            
             gezici.ileri(); //Bir sonraki nodea geç
            } 

            if (!eklendi) {
                DkGezici gezici = this->sonuAl();
                gezici.simdiki->next = yeninokta;
                yeninokta->prev = gezici.simdiki;
                this->ks = yeninokta;


            }
        }
        
        
    }


ostream& operator<<(ostream& screen, DogruKuyrugu& noktalar){
    if (noktalar.bosmu()) screen << Error_isEmpty;

    DkGezici gezici = noktalar.ilkiniAl();

    while ( gezici.noktaVarmi() ) {
        screen << gezici.simdiki->orjineyakinlik << " <--> "; 
        gezici.ileri(); //Bir sonraki nodea geç
    } 

    //screen << noktalar.simdiki->orjineyakinlik << endl ;
    return screen;
}


    DkGezici::DkGezici(){
        this->simdiki = NULL;
    }
    DkGezici::DkGezici(Nokta *n){
        this->simdiki = n;
    }
    bool DkGezici::noktaVarmi(){
        return this->simdiki != NULL;
    }
    bool DkGezici::sonrakiVarmi(){
        return this->simdiki->next != NULL;
    }
    void DkGezici::ileri(){
        if(!noktaVarmi()) throw Error_NoItem;
        this->simdiki = this->simdiki->next;
    }
    void DkGezici::geri(){
        if(!noktaVarmi()) throw Error_NoItem;
        this->simdiki = this->simdiki->prev;
    }

     Nokta *DkGezici::sonaGit(){
         while (sonrakiVarmi())
         {
             ileri();
         }
         return simdiki;
     }