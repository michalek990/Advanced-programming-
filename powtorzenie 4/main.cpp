#include <iostream>
#include <map> //biblioteka map

using namespace std;

//wypisanie mapy
void showMap( map<string, int> m)
{
    cout<<endl<<"m: "<<endl;
    map<string, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        cout<< it->first <<"  "<<it->second<<endl;
    }
    cout<<endl;
}

//wyszukanie po wartosci w mapie funkcja
map<string, int>::iterator searchByValue(map<string,int>& m,int val)
{
    map<string, int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second==val)
        {
            break;
        }
    }
    return it;
}



int main()
{
    map<string,int> m; //stworzenie mapy ktorym kluczem bedzie string a wartoscia int

    //dodanie do mapy z apomoca pair
    m.insert(pair<string,int>("Kowalski", 4500));
    //drugi sposob za pomoca make_pair
    m.insert(make_pair("Nowak",2000));
    //trzeci sposob za pomoca operatora[]
    m["Adamiak"]=3000;

    showMap(m); //wypisanie mapy

    //wyszukanie wartosci na podstawie klucza
    int salary=m.find("Kowalski")->second;
    cout<<"Zarobki Kowalskiego: "<<salary<<endl;

    m.erase("Adamiak");//usuniecie elementu na podstawie klucza

    showMap(m);
    cout<< "Czy jest Kowalski?"<<m.count("Kowalski")<<endl;

    //dostanie sie do elementu mapy
    pair<string, int> el=*m.end();
    cout<<"Klucz: "<<el.first<<" "<<" war: "<<el.second<<endl;

    //wyszukanie po wartosci
    map<string,int>::iterator it = searchByValue(m, 2000);
    if(it != m.end())
        cout<<"Element znaleziony: "<<it->first<<" "<<it->second<<endl;
    else
        cout<<"Brak elementu"<<endl;



    return 0;
}
