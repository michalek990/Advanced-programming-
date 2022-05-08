#include <iostream>
#include "Dziecko.h"
#include "Prezent.h"
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void unikatAdres(vector<Dziecko> gowniak){
    set<string> s;
    string temp;
    for(int i=0;i<gowniak.size();i++){
        temp = gowniak[i].getUlica();
        s.insert(temp);
    }
    cout<<"Unikalne adresy to:"<<endl;
    set<int>::iterator itr;
    for (auto itr = s.begin();itr!=s.end();itr++)
    {
        cout<< *itr<<" ";
    }cout<<endl;
 }
 void zadanie3(vector<Dziecko> grzeczne, vector<Prezent> prezenty){

     for(int i=0;i<grzeczne.size();i++){
       for(int j=0;j<prezenty.size();j++){
            if(grzeczne[i].getWiek() == prezenty[j].getwiek_dolny() or grzeczne[i].getWiek() == prezenty[j].getwiek_gorny()){
                cout<<grzeczne[i].getImie()<<" prezent o id = "<<prezenty[j].getId()<<endl;
                prezenty.erase(prezenty.begin()+j);
            }
       }
     }

 }
int main()
{
    cout << "Hello world!" << endl;


    vector <Dziecko> gowniak;
    gowniak.push_back(Dziecko("Maja","grzeczne",7,"Ametystowa",11));
    gowniak.push_back(Dziecko("Kaja","grzeczne",5,"Ametystowa",11));
    gowniak.push_back(Dziecko("Jasio","niegrzeczne",7,"Ametystowa",11));
    gowniak.push_back(Dziecko("monia","grzeczne",4,"Bursztynowa",12));
    gowniak.push_back(Dziecko("RAfal","grzeczne",7,"Ametystowa",11));
    gowniak.push_back(Dziecko("Robert","grzeczne",5,"Ametystowa",11));
    gowniak.push_back(Dziecko("Adrian","niegrzeczne",7,"Ametystowa",11));
    gowniak.push_back(Dziecko("krystian","grzeczne",4,"Bursztynowa",12));

    for(int i= 0; i<gowniak.size();i++){
        gowniak[i].pokaz();
    }
    sort(gowniak.begin(),gowniak.end(),[](Dziecko el,Dziecko el2){if(el.getGrzeczne()=="grzeczne")return true;else return false;});
    cout<<"Po sortowaniu "<<endl;
    for(int i= 0; i<gowniak.size();i++){
        gowniak[i].pokaz();
    }

    unikatAdres(gowniak);

    vector<Dziecko> grzeczne;
    for(int i = 0; i<gowniak.size();i++){
        if(gowniak[i].getGrzeczne()=="grzeczne"){
            grzeczne.push_back(gowniak[i]);
        }
    }
    cout<<"Grzeczne dzieci: "<<endl;
     cout<<"############################################# "<<endl;
     for(int i= 0; i<grzeczne.size();i++){
        grzeczne[i].pokaz();
    }
    cout<<"############################################# "<<endl;
    vector<Prezent> prezenty;
    prezenty.push_back(Prezent("PZ021",1,0));
    prezenty.push_back(Prezent("PZ022",3,2));
    prezenty.push_back(Prezent("PZ023",5,4));
    prezenty.push_back(Prezent("PZ024",7,6));
    prezenty.push_back(Prezent("PZ025",9,8));
    prezenty.push_back(Prezent("PZ026",11,10));

/*
     cout<<"Prezenty: "<<endl;
     for(int i= 0; i<prezenty.size();i++){
        prezenty[i].pokaz_prezenty();
    }*/
    cout<<"Zadanie 3 "<<endl;
    zadanie3(grzeczne,prezenty);
    return 0;
}
