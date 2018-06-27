#include"Sequence.h"
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	string s="dna.txt";
	Sequence se(s);
	cout<<se.length()<<endl;
	cout<<"A: "<<se.numberOf('A')<<endl;
	cout<<"T: "<<se.numberOf('T')<<endl;
	cout<<"C: "<<se.numberOf('C')<<endl;
	cout<<"G: "<<se.numberOf('G')<<endl;
	cout<<se.longestConsecutive().length()<<endl;
	cout<<se.longestRepeated()<<endl;
}
