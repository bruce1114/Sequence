#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<string>
#include<iostream>
using namespace std;
typedef struct mark{
	int n;
	char *p;
}mark;

class Sequence{
private:
	string s;
	int dna[5];
	int Length;
public:
	//static char *longestp;
	//static int longestn;
	friend int cmp(const void*,const void*);
	Sequence(string);
	int length();
	int numberOf(char);
	string longestConsecutive();
	string longestRepeated();
};












#endif
