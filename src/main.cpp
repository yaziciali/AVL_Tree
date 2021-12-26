/**
* @file main.cpp
* @description Uygulama açılışta Noktalar.txt dosyasını okur. 
*              x,y,z koordinatları verilen noktaları DogruKuyrugu sınıfına kaydeder.
*              Aralarındaki uzunluğuda ölçerek toplar ve aynı sınıftaki tuzunluk değişkenine kaydeder.
*               Her bir satırdan oluşan yeni DogruKuyrugu nesnelerini AVL ağacına ekler.
*               Ve son olarak yeni oluşan bu ağacı postorder metodu ile ekrana gösterir.
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 2
* @date 25.12.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <fstream>
#include <string>

#include <sstream>
#include <iostream>

#include "dogrukuyrugu.hpp"
#include "avl.hpp"
#include "definitions.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

    string line;
    ifstream dataFile(FILENAME);
    int lineNumber = 1 ;
    int insertIndex = 0 ;
    int delIndex = 0 ;
    string newitem = "";
    Avl *agac = new Avl();

    while (getline(dataFile, line))
    {
        DogruKuyrugu *noktalar = new DogruKuyrugu();
        // cout << lineNumber << ". SATIR: " << line << endl ;
        std::stringstream  lineStream(line);
        int value;
        int xyz[3];
        int dindex = 0 ;
        // Sayıları teker teker oku
        while(lineStream >> value)
        {
            //cout << value << endl ;
            xyz[dindex] = value;
            dindex++;
            if (dindex==3){
                Nokta *yeni = new Nokta(xyz[0],xyz[1],xyz[2]);
                noktalar->ekle(yeni);
                dindex=0;
                //cout << noktalar << endl ;;
            }
            
        }
        // cout << lineNumber << ". satirdaki dogrularin toplam mesafesi: " << noktalar->toplamUzunluk() << "  " << endl;
        
        agac->ekle(agac->kok,  noktalar);
        // cout << lineNumber << ". SATIR EKLENDİ: " << *noktalar << "  " << endl;
        lineNumber++;
    }


agac->postOrder(agac->kok);

agac->bellektemizle(agac->kok);
//agac->yazdir(agac->kok);

    return 0;
}
