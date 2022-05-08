#ifndef DZIECKO_H_INCLUDED
#define DZIECKO_H_INCLUDED
using namespace std;
#include <string>
#include <vector>
class Dziecko{

private:
    string imie;
    string grzeczne;
    int wiek;
    string ulica;
    int nr_domu;
    vector <Dziecko> gowniak;
public:
     Dziecko(string name1,string grzeczne1,int wiek1,string ulica1, int nr_domu1);
     Dziecko();
    void pokaz();
    //void setImie(string imie1);
    //void setGrzeczne(string grzeczne1);
   // void setUlica(string ulica1);
  //  void setWiek(int wiek1);
   // void setNR_domu(int nr_domu1);
    string getImie();
    string getGrzeczne();
    string getUlica();
    int getWiek();
    int getNR_domu();



};


#endif // DZIECKO_H_INCLUDED
