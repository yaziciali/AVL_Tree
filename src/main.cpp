/**
* @file main.cpp
* @description Uygulama çift yönlü bir bağıl liste oluşturur. Veri.txt dosyasını okur.
*              Satırlar ekleme için "E(2#Mehmet Can)" formatında ve silme için "S(3) formatında olmalıdır.
*              Satır başı E ile başlıyor ise ( ile # arasındaki indeks numarasını alır.
*               # ile ) harfleri arasındaki texti okur. Verilen indekse göre bağıl listeye texti ekler.
*               Satır başı S ile başlıyorsa ( ve ) harfleri arasındaki indeks numarasını alarak. 
*               İlgili indeksi bağıl listeden siler. Satırlar bitince listeyi ekranda gösterir.
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>

#include <sstream>
#include <iostream>

#include "dogrukuyrugu.hpp"
#define FILENAME "Noktalar.txt"
using namespace std;

int main(int argc, char const *argv[])
{

    string line;
    ifstream dataFile(FILENAME);
    int lineNumber = 1 ;
    int insertIndex = 0 ;
    int delIndex = 0 ;
    string newitem = "";

    while (getline(dataFile, line))
    {
        DogruKuyrugu noktalar;
        cout << line << endl ;
        std::stringstream  lineStream(line);
        int value;
        int xyz[3];
        int dindex = 0 ;
        // Sayıları teker teker oku
        while(lineStream >> value)
        {
            cout << value << endl ;
            xyz[dindex] = value;
            dindex++;
            if (dindex==3){
                Nokta *yeni = new Nokta(xyz[0],xyz[1],xyz[2]);
                noktalar.ekle(yeni);
                dindex=0;
                cout << noktalar << endl ;;
            }
            
        }
        lineNumber++;
        
    }






    return 0;
}
