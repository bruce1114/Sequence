#include"Sequence.h"
#include<string>
#include<iostream>
#include<fstream>
#include<memory.h>
#include<cmath>
#include<algorithm>
using namespace std;

Sequence::Sequence(string filename)
{

	Length=0;
	memset(dna,0,sizeof(dna));
	fstream in(filename.data());
	string temp;
	while(in>>temp)
	{
		s+=temp;
		int l=temp.length();
		Length+=l;
		for(int i=0;i<l;++i)
		{
			switch(temp[i])
			{
			case 'A': {dna[1]++;break;}
			case 'T': {dna[2]++;break;}
			case 'C': {dna[3]++;break;}
			case 'G': {dna[4]++;break;}
			}
		}
	}
}
int Sequence::length()
{
	return Length;
}
int Sequence::numberOf(char base)
{
	switch(base)
	{
	case 'A': return dna[1];
	case 'T': return dna[2];
	case 'C': return dna[3];
	case 'G': return dna[4];
	}
}

string Sequence::longestConsecutive()
{
	char ch=s[0];
	int lon=1;
	int tlon=1;
	int pos=0;
	for(int i=1;i<Length;++i)
	{
		if(s[i]!=ch)
		{
			if(tlon>lon)
			{
				lon=tlon,pos=i-tlon;
				tlon=1,ch=s[i];
			}
			else tlon=1,ch=s[i];
		}
		else ++tlon;
	}
	if(tlon>lon) lon=tlon,pos=Length-tlon;
	return s.substr(pos,lon);
}
