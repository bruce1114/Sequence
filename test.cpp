#include"Sequence.h"
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	string s="dna.txt";
	Sequence se(s);
	se.longestRepeated();
}
