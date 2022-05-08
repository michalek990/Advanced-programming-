#include "Prezent.h"
#include <iostream>
#include <set>
Prezent::Prezent(string id1,int wiek_gorny1,int wiek_dolny1){
    id=id1;
    wiek_gorny=wiek_gorny1;
    wiek_dolny=wiek_dolny1;
}
Prezent::Prezent(){

}
string Prezent::getId(){
    return id;
}
int Prezent::getwiek_gorny(){
    return wiek_gorny;
}
int Prezent::getwiek_dolny(){
    return wiek_dolny;
}
void Prezent::pokaz_prezenty(){
    cout<<getId()<<" od "<<getwiek_dolny()<<"-"<<getwiek_gorny()<<" lat"<<endl;
}
