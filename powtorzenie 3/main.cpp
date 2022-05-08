#include <iostream>
#include <vector> //biblioteka do uzywania wektora
#include <algorithm> //biblioteka algorytmow kontenera

using namespace std;

class Typowa_klasa
{
private:
    int tpowa_zmienna;
public:
    void typowa_funkcja()
    {

    }
};

//wypisanie vectora funkcja
template <typename T>
void show(T &con)
{
    for(typename T::iterator it=con.begin();it!=con.end(); it++)
    {
        cout<<*it<<" ";
    }cout<<endl;
}
//wypisanie z gwiazdkami
void print(int& el)
{
    cout<<el<<"***";
}
//dodawanie do elementow
void add10(int& el)
{
    el=el+10;
}
//parzyste
bool isEven(int x)
{
    if(x%2 == 0)
        return true;
    else
        return false;
}

int main()
{
    vector<int> vec; //deklaracja wektora przechowujacego liczby calkowite

    vec.push_back(1); //dodawanie liczby na koniec
    vec.push_back(2); //dodawanie liczby na koniec
    vec.push_back(3); //dodawanie liczby na koniec


    //pierwszy sposob dostepu do elementow wektora za pomoca operatora[]
    cout<<"Operator[]"<<endl;
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }cout<<endl;

    //drugi sposob dostepu do elementow wektora za pomoca metody at
    cout<<"At"<<endl;
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;

    //trzeci sposob dostepu do elementow wektora za pomoca iteratora. zmienna it
    //zmienna it przechowuje adres, a wiec do uzykania wartosi uzywamy *
    cout<<"Iterator: "<<endl;
    vector <int>::iterator it;
    for(it=vec.begin(); it!= vec.end(); it++)
    {
        cout<<*it<<" ";
    }cout<<endl;

    //uzyskanie dostepu do pierwszego elementu za pomoca funkcji begin
    //ktora zwraca terator lub za pomoca funkcji front, ktora zwraca wartosc
    cout<<"begin() "<< *vec.begin()<<endl;
    cout<<"front() "<<vec.front()<<endl;

    //uzyskanie dostepu do ostatniego elementu za pomoca funkcji end. ktora zwraca
    //iterator lub za pomoca funkcji back, ktora zwaca wartosc
    cout<<"end() "<< *(vec.end()-1)<<endl;
    cout<<"back() "<< vec.back()<<endl;

    show(vec);
    vec.pop_back(); //usuniecie ostatniego elementu
    show(vec);
    vec.erase(vec.begin()+1,vec.begin()+2); //usuniecie elementow z zakresu
    show(vec);
    vec.insert(vec.begin()+1,100); //wstawienie elementu pod wskazany adres
    show(vec);
    vec.clear(); //wyczyszczenie zawartosci kontenera
    show(vec);


    //kontener vector z zadeklarowanym rozmiarem i wypelnieniem
    vector<float>vec2(5,8.2);
    show(vec2);
    vec2.push_back(3.10); //dodanie elementu na koniec vectora
    show(vec2);

    //operacje na vectorze przykladowe
    vector<int>num={3,6,3,8,9,1,3}; //kontener wypelniony liczbami
    show(num);

    //sortowanie wszystkich elementow
    sort(num.begin() ,num.end());
    show(num);

    //wyszukanie liczby 3
    cout<<"binary search"<<endl;
    cout<<binary_search(num.begin() ,num.end() ,3)<<endl;

    //zliczenie ile razy wystepuje liczba 3
    cout<<"count"<<endl;
    cout<<count(num.begin() ,num.end() , 3)<<endl;
    show(num);

    //odwrocenie kolejnosci kontenera czesci
    cout<<"reverse"<<endl;
    reverse(num.begin() ,num.begin()+4);
    show(num);

    //zmiana kolejnosci elementow w kontenerze
    cout<<"random_shuffle"<<endl;
    random_shuffle(num.begin() ,num.end());
    show(num);

    //wyszukanie elementu maksymalnego, funkcja zwraca iterator st¹d trzeba
    //u¿yæ operatora * aby wy³uskaæ wartoœæ
    cout<<"max element"<<endl;
    cout<<*max_element(num.begin() ,num.end())<<endl;
    show(num);

    cout<<"merge"<<endl;
    vector<int>num2(4,6);
    vector<int>res(num.size()+num2.size());
    sort(num.begin() ,num.end());
    merge(num.begin() ,num.end() , num2.begin() , num2.end(), res.begin());

    show(res);


    //for_each, count_if
    for_each(num.begin(), num.end() , print);
    for_each(num.begin(), num.end() , add10);
    cout<<endl;
    for_each(num.begin() , num.end() , print);
    cout<<endl;
    cout<<count_if(num.begin(), num.end(), isEven);


    vector<int> num3={2, -6, 7, 3, 0, 8, -9, -2};
    for_each(num3.begin(),num3.end(),print);
    int howMany=count_if(num3.begin(),num3.end(),bind2nd(greater<int>(), 0));
    cout<<endl<<"wersja1: wartosc > 0 "<<howMany<<endl;


    greater<int> f;
    howMany=count_if(num3.begin(), num3.end(),bind2nd(f, 0));
    cout<<"wersja2: wartosc > 0 "<<howMany<<endl;

    cout<<"Przed sortowaniem" <<endl;
    for_each(num3.begin(),num3.end(),print);
    sort(num3.begin(),num3.end(), greater<int>());
    cout<<endl<<"Po sortowaniu"<<endl;
    for_each(num3.begin(),num3.end(),print);
    return 0;
}
