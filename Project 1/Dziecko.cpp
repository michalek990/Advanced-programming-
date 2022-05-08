#include "Dziecko.h"
#include <iostream>
#include <set>
Dziecko::Dziecko(string imie1, string grzeczne1,int wiek1,string ulica1, int nr_domu1){
    imie = imie1;
    grzeczne = grzeczne1;
    wiek = wiek1;
    ulica = ulica1;
    nr_domu = nr_domu1;
}
Dziecko::Dziecko(){

}
string Dziecko::getImie(){
    return imie;
}
string Dziecko::getGrzeczne(){
    return grzeczne;
}
int Dziecko::getWiek(){
    return wiek;
}
string Dziecko::getUlica(){
    return ulica;
}
int Dziecko::getNR_domu(){
    return nr_domu;
}
void Dziecko::pokaz(){
    cout<<getImie()<<", "<<getGrzeczne()<<", "<<getWiek()<<", "<<getUlica()<<" "<<getNR_domu()<<endl;
}

