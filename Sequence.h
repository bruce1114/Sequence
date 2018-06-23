#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
#include<iostream>
using namespace std;

class Sequence{
private:
	string s;
	int dna[5];
	int Length;
public:
	Sequence(string);
	int length();
	int numberOf(char);
	string longestConsecutive();
};












#endif
