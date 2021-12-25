/**
* @file linkedList2.cpp
* @description Eleman ekleme ve çıkarmada bir dizi gibi davranan çift yönlü Bağıl liste yapısı
* @course BSM 207 - Veri Yapıları - 1. Öğretim A grubu
* @assignment 1
* @date 08.11.2021
* @author Ali YAZICI ali.yazici3@ogr.sakarya.edu.tr
*/
#include "linkedList2.hpp"
#include "definitions.hpp"

LinkedList2::LinkedList2(){
    this->count = 0;
}
bool LinkedList2::isEmpty() const{
    return this->count == 0;
}
int LinkedList2::getCount() const{
    return this->count;
}

string LinkedList2::getItem() const{
    return this->currentItem->item;
}	

Iterator LinkedList2::goFirst()  {
    if(this->isEmpty()) throw Error_isEmpty;
    this->currentItem = this->beginList;
    this->index = 0 ;
    return Iterator(this->currentItem);
}

Iterator LinkedList2::goLast()
{
    if(this->isEmpty()) throw Error_isEmpty;
    this->currentItem = this->endList;
    this->index = this->count - 1 ;
    return Iterator(this->currentItem);
}


void LinkedList2::addItem( const string&  newItem){

    if (this->count > 0 )
    {
        this->goLast();
 
        this->currentItem->next = new Node(newItem,this->currentItem); // Yeni Node'u son node'dan sonrasina bagla
        this->endList = this->currentItem->next ; //Eklenen son node olur

    } else {
        this->currentItem = new Node(newItem); 
        this->beginList = this->currentItem; //Yeni node tek olduğu için hem baş hem de sondur.
        this->endList = this->currentItem;
        this->index = 0;
    }

        
        this->count++;


    
}
void LinkedList2::addItem( const string&  newItem,int index){
    

            if(index >= this->count || index < 0 ) {
                this->addItem(newItem); 
                
            } else {
                Iterator tempIterator = this->goLast();
                this->addItem(this->currentItem->item); // Sona ekler, ama index currentItem olan kalır
                
                while (this->index != index)
                {
                  tempIterator.current->next->item = tempIterator.current->item; // Bir Sag tarafina kopyala
                    tempIterator.movePrev();
                    this->index--;
                } 
                tempIterator.current->next->item = tempIterator.current->item; // Son defa bir Sag tarafina kopyala
                tempIterator.current->item = newItem; // indexi bulunca newItem kopyalar
            } 
    

    
}

void LinkedList2::remove(){
    if(this->isEmpty()) throw Error_isEmpty;

    Iterator tempIterator  = this->goLast();
    Node *tempnode = this->endList;
    

    if (this->count > 1) {
        tempIterator.movePrev();
        tempIterator.current->next = NULL; // Yeni Node'u sonrasina bagla
        this->endList = tempIterator.current;
    }


    this->count--;
    
    delete tempnode;

}

void LinkedList2::remove(int index){
    if(this->isEmpty()) throw Error_isEmpty;


            if(index < this->count-1 && index >= 0 ) { //Index son item indexinden kucuk ise kopyalama yap
                Iterator tempIterator = this->goFirst();
                while (tempIterator.hasNext())
                {
                    if(this->index >= index) {
                        tempIterator.current->item = tempIterator.current->next->item;
                    }
                    tempIterator.moveNext();          
                    this->index++;
                }
            
            } 

    this->remove(); // index yok ise de sondan bir tane sil


}


void LinkedList2::clear(){
    while (!this->isEmpty()){
        this->remove();
    }

}

ostream& operator<<(ostream& screen, LinkedList2& item){
    if (item.isEmpty()) screen << Error_isEmpty;

    Iterator tempIterator = item.goFirst();

    for(;tempIterator.hasNext();tempIterator.moveNext()){
        screen << tempIterator.current->item << " <--> "; 
    }

    screen << tempIterator.current->item << endl ;
    return screen;
}