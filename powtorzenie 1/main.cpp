#include <iostream>
#include <set> //biblioteka set'a
#include <algorithm>

using namespace std;

//syswietlenie set'a
void show(set<int> s)
{
    set<int>::iterator itr;
    for (itr = s.begin();itr!=s.end();itr++)
    {
        cout<< *itr<<" ";
    }cout<<endl;
}

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(7);
    //s.insert(3);
    show(s);

    s.erase(s.begin(), s.find(4));
    show(s);
    s.erase(7);
    show(s);
    cout<<s.count(2)<<endl;

    set<int> s1={1,2,3,7};
    set<int> s2={-2,3,1,7,6};
    cout<<"s1: ";
    show(s1);
    cout<<"s2: ";
    show(s2);

    set<int>sUnion,sIntersec,sDiffer;//deklaracja nowych zbiorow
    //suma zbioru
    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(sUnion,sUnion.begin()));

    //iloczyn zbioru
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(sIntersec,sIntersec.begin()));

    //roznica zbiorow
    set_difference(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(sDiffer,sDiffer.begin()));

    show(sUnion);
    show(sIntersec);
    show(sDiffer);
    return 0;
}
