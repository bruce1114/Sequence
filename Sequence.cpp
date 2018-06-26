#include"Sequence.h"
#include<string>
#include<iostream>
#include<fstream>
#include<memory.h>
#include<cmath>
#include<algorithm>
#include<vector>
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


bool cmp(mark a,mark b)
{
	int i,j;
	for(i=0,j=0;i<a.n&&j<b.n;++i,++j)
	{
		if((*(a.p+i))!=(*(b.p+j))) return (*(a.p+i))<(*(b.p+j));
	}
	return 0;
}

string Sequence::longestRepeated()
{
	vector<mark>m;
	char *sp=(char*)s.data();
	for(int i=0;i<Length;++i)
	{
		mark temp;
		temp.p=sp+i;
		temp.n=Length-i;
		m.push_back(temp);
	}
	cout<<1<<endl;
	sort(m.begin(),m.end(),cmp);
	cout<<2<<endl;
}



















