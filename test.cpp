#include"Sequence.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s="dna.txt";
	Sequence se(s);
	cout<<(se.longestConsecutive()).length();
}
