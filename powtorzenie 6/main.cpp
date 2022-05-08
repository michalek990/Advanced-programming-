#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
//wypisanie vektora int
void print(int &el)
{
    cout<<el<<", ";
}
//wypisanie wektora str
void printS(string &el)
{
    cout<<el<<", ";
}
//dodanie gwiazdek
void dodaj_g(string &el)
{
    el=el+"**";
}
//obliczenie sumy cyfr
int suma_c(int liczba)
{
    int suma=0;
    do
    {
        suma=suma+liczba%10;
        liczba=liczba/10;
    }while(liczba!=0);
    return suma;
}
//obliczenie ilosci cyfr
int liczba_c(int liczba)
{
    int suma=0;
    do
    {
        suma++;
        liczba=liczba/10;
    }while(liczba!=0);
    return suma;
}
//funkcja do sort przez sume cyfr
bool funkcja(int i, int j)
{
    if(suma_c(i)>suma_c(j))
    {
        return 1;
    }else return 0;
}
//funkcja do sort przez ilosc cyfr
bool funkcja2(int i, int j)
{
    if(liczba_c(i)>liczba_c(j))
    {
        return 1;
    }else return 0;
}
//spr czy podzielna przez 3
bool isEven(int x)
{
    if(x%3==0)
        return true;
    else
        return false;
}
//zamiana elementow w wektorze
void zastap(int &el)
{
    el=-el;
}
//czy jakis element wektora jest rowny zero
bool zero(int x)
{
    if (x==0) return true;
    else return false;
}
int main()
{

    vector<int>vec={4,5,2,1,5,6,8,9,111,12,4443,212,0,1,2,3};


    //zad4.4
    for_each(vec.begin(),vec.end(),print);
    cout<<endl;
    sort(vec.begin(),vec.end(), funkcja);
    reverse(vec.begin(),vec.end());
    for_each(vec.begin(),vec.end(),print);
    cout<<endl;

    sort(vec.begin(),vec.end(), funkcja2);
    for_each(vec.begin(),vec.end(),print);
    cout<<endl;

    //zad podzielna przez 3
    cout<<"Liczb podzielnych przez 3 w wektorze jest: ";
    cout<<count_if(vec.begin(), vec.end(), isEven)<<endl;

    //zastap liczba przeciwna kazdy element w wektorze
    for_each(vec.begin(),vec.end(),zastap);
    for_each(vec.begin(),vec.end(),print);
    cout<<endl;

    //ile razy w wektorze wystapilo zero
    cout<<endl<<"Zero wystapilo: "<<count_if(vec.begin(),vec.end(),zero);
    cout<<endl;

    //dodaj gwiazdki do napisów w wektorze
    vector<string>nap={"lalal","dadad","sususus","kkkk"};
    for_each(nap.begin(),nap.end(),printS);
    cout<<endl;
    for_each(nap.begin(),nap.end(),dodaj_g);
    for_each(nap.begin(),nap.end(),printS);

    //policz srednia w wektorze
    vector<float>vecf={2.0, 2.0};
    float sumaf = 0;

    for(int i=0; i<vecf.size(); i++)
    {
        sumaf+=vecf[i];
    }

    cout<<endl<<"Srednia: "<< sumaf/vecf.size()<<endl;

    //czy wszystkie liczby od 1 do 3 zostaly uzyte w wektorze
    vector<int>vec2={0,1,2,3,4};

    for(int i=0; i<=3; i++)
    {
        if (binary_search(vec2.begin(),vec2.end(),i))
            continue;
        else
        {
            cout<<"Nie wszystkie liczby wystapily w wektorze"<<endl;
            exit(1);
        }
    }
    cout<<"Wszystkie liczby wstapily w wektorze"<<endl;

    //czy wszystkie znaki alfabetu wystapily w wektorze
    vector<char>alfa={'a','b','c'};
    cout<<"Czy 'a' wystapilo w wektorze?"<<binary_search(alfa.begin(),alfa.end(),'a')<<endl;
    for(int i=97; i<=99; i++)
    {
        if (binary_search(alfa.begin(),alfa.end(),((char)i))){
            continue;
        }
        else
        {
            cout<<"Nie wszystkie znaki alfabetu wystapily w wektorze"<<endl;
            exit(1);
        }

    }
    cout<<"Wszystkie znaki alfabetu wystapily w wektorze"<<endl;




    return 0;
}
