#include<iostream>
#include<string>
#include"vector.h"
using namespace std;



int main()
{
   {

    vector<int> v(5);

    v.push_back(20);
    v.push_back(30);

    cout<<v;

    vector<int> v2;

   // Copy Assgnment operator called
   
    v2=v;

    cout<<v2;



   } 


   {
     vector<char> s;

    s.push_back('a');
    s.push_back('b');
    s.push_back('c');

    cout<<s;

    cout<<s.capacity()<<endl;

   }
}