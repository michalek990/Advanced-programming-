#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;

//wypisanie kontenera
template <typename T>
void show(T &con)
{
    for(typename T::iterator it=con.begin();it!=con.end();it++)
    {
        cout<<*it<<" ";
    }cout<<endl;
}



//funkcja dla for_each'a
void add(int &el)
{
    el=el+10;
}
//funkcja dla count_if
bool isEven(int x)
{
    if(x%2 == 0)
    {
        return true;
    }else{
        return false;
    }
}


int main()
{
    //deklaracja wektora
    vector<int>vec={3,4,5,3,5,77,5,7456,3,45,21113,4,3554,68,9867,234};

    //wywolanie for_each'a
    for_each(vec.begin(),vec.end(),add);
    //wywolanie count_if
    cout<<count_if(vec.begin(),vec.end(),isEven)<<endl;
    cout<<count_if(vec.begin(),vec.end(),[](int x){if(x%2==0)return true;else
        return false;})<<endl;
    int sum=0;
    for_each(vec.begin(),vec.end(),[&sum](int el){if(el%2==0)sum+=1;});
    cout<<"Suma to: "<<sum<<endl;



    //wypisane wektora za pomoca funkcji lambda w for_each'u
    for_each(vec.begin(),vec.end(),[](int &el){cout<<el<<" ";});


    return 0;
}
