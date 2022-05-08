#ifndef PREZENT_H_INCLUDED
#define PREZENT_H_INCLUDED
using namespace std;
#include <string>
#include <vector>
class Prezent{

private:
    string id;
    int wiek_gorny;
    int wiek_dolny;

public:
     Prezent(string id1,int wiek_gorny1,int wiek_dolny1);
     Prezent();
     void pokaz_prezenty();
    //void setImie(string imie1);
    //void setGrzeczne(string grzeczne1);
   // void setUlica(string ulica1);
  //  void setWiek(int wiek1);
   // void setNR_domu(int nr_domu1);
    string getId();
    int getwiek_gorny();
    int getwiek_dolny();



};

#endif // PREZENT_H_INCLUDED
