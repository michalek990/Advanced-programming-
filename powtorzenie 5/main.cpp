#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<iterator>
#include<string>

using namespace std;


pair<int, int> findDuplicatedValue(vector<int> vec){
    set<int> s1;
    pair<int,int> p;

    for(auto it=vec.begin(); it != vec.end(); it++){
        if(s1.count(*it))
            p.first = *it;
        else
            s1.insert(*it);
    }
    int sum = 0;
    for(auto it2 = s1.begin(); it2 != s1.end(); it2++){
        sum += *it2;
    }
    p.second = sum;
    return p;
}
template<typename T>
void exclusiveOR(set<T> a, set<T> b){
    set<T> setOR, setAND;
    set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(setOR, setOR.begin()));
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(setAND, setAND.begin()));
    for(auto it=setAND.begin(); it!=setAND.end(); it++)
        setOR.erase(*it);
    cout << "\nPo zastosowaniu alterantywy wykluczajacej\n";
    for(auto it=setOR.begin(); it!=setOR.end(); it++)
        cout << *it << "\t";
}
char findCharacter(string s1, string s2){
    map<char, int> m;
    for(int i=0; i < s1.length(); i++){
        m[s1[0]] = 1;
    }
    for(int i=0; i < s2.length(); i++){
        if(m.count(s2[i]))
            m[s2[i]] += 1;
        else
            m[s2[i]] = 1;
    }
    for(auto &it : m){
        if(it.second == 1)
            return it.first;
    }
    return '\0';
}

int main()
{
    cout << "Zadanie 1. Duplikat\n";
    vector<int> vec {1,2,6,2,-3,-5,7,8,10,18,84,16};
    pair <int, int> p = findDuplicatedValue(vec);
    cout << "Duplikat: " << p.first << endl;
    cout << "Suma unikatowych elementow: " << p.second << endl;





    cout << "\nZadanie 2. Alternatywa wykluczaj¹ca\n";
    set<int> s1 {1,2,3,4,5,6,7,9,10};
    set<int> s2 {1,3,4,5,0,8,10,11,12,13,15};
    cout << "Pierwszy zbior\n";
    for(set<int>::iterator it = s1.begin(); it != s1.end(); it++)
        cout << *it << "\t";
        cout << "\nDrugi zbior\n";
    for(set<int>::iterator it = s2.begin(); it != s2.end(); it++)
        cout << *it << "\t";
        exclusiveOR<int>(s1,s2);




    cout << "\nZadanie 3\n";
    cout << findCharacter("Ala ma kota", "Alka ma kota") << endl;
    return 0;
}
