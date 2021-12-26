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
        tuzunluk = 0 ;
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
        this->xo = yeninokta->x;
        this->yo = yeninokta->y;
        this->zo = yeninokta->z;
        this->tuzunluk = 0 ;
        sayi = 1 ;
        } else
        {
            DkGezici gezici = this->ilkiniAl();
            while ( gezici.noktaVarmi() ){
            //    cout << "yeni_yakinlik: " << yeninokta->orjineyakinlik << " -> simdiki_yakinlik: " << gezici.simdiki->orjineyakinlik << endl;
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

                    // Dosyaya geliş sırasuna göre toplam uzunluk bulma kodu
                    this->tuzunluk += sqrt(pow(yeninokta->x - this->xo,2)+pow(yeninokta->y - this->yo,2)+pow(yeninokta->z - this->zo,2));
                    this->xo = yeninokta->x;
                    this->yo = yeninokta->y;
                    this->zo = yeninokta->z;
        }
        
        
    }

double DogruKuyrugu::toplamUzunluk(){

    return tuzunluk ;

/*  // Eski kod, öncelik sırasına göre toplam uzunluk bulma kodu 
   tuzunluk = 0;
    DkGezici gezici = this->ilkiniAl();

    while ( gezici.sonrakiVarmi()){
        gezici.ileri();
        
           cout << sqrt(pow(gezici.simdiki->x - gezici.simdiki->prev->x,2)+pow(gezici.simdiki->y - gezici.simdiki->prev->y,2)+pow(gezici.simdiki->z - gezici.simdiki->prev->z,2))<< " x1 :"  << gezici.simdiki->x  << " x2 :"  << gezici.simdiki->prev->x << " y1 :"  << gezici.simdiki->y << " y2 :"  << gezici.simdiki->prev->y << " z1 :"  << gezici.simdiki->z << " z2 :"  << gezici.simdiki->prev->z << endl;
           tuzunluk += sqrt(pow(gezici.simdiki->x - gezici.simdiki->prev->x,2)+pow(gezici.simdiki->y - gezici.simdiki->prev->y,2)+pow(gezici.simdiki->z - gezici.simdiki->prev->z,2));

        
    }
    return tuzunluk ; */
    
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


