#include"Sequence.h"
#include<string>
#include<iostream>
#include<fstream>
#include<memory.h>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<vector>
using namespace std;
//char* Sequence::longestp=NULL;
//int Sequence::longestn=0;

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


int cmp(const void *a,const void *b)
{
	//char* &p=Sequence::longestp;
	//int &n=Sequence::longestn;
	mark A=*((mark*)(a)),B=*((mark*)(b));
	int i;
	for(i=0;i<A.n&&i<B.n;++i)
	{
		if((*(A.p+i))!=(*(B.p+i)))
		{
			/*if(i>n)
			{
				n=i;
				p=A.p;
			}*/
			return (*(A.p+i))-(*(B.p+i));
		}
	}
	//if(i>n) n=i,p=A.p;
	return A.n-B.n;
}

string Sequence::longestRepeated()
{
	mark *m=(mark*)new mark[Length+5];
	char *sp=(char*)s.data();
	for(int i=0;i<Length;++i)
	{
		m[i].p=sp+i;
		m[i].n=Length-i;
	}
	//Sequence::longestp=NULL;
	//Sequence::longestn=0;
	qsort(m,Length,sizeof(m[0]),cmp);
	//string *sstemp=new string(Sequence::longestp,Sequence::longestn);
	//delete []m;
	//return *sstemp;
	/*for(int i=0;i<Length;++i)
	{
		for(int j=0;j<m[i].n;++j) cout<<*(m[i].p+j);
		cout<<endl;
	}*/
	int pos = 0, lon = 0;
	for (int i = 0; i < Length-1; ++i)
	{
		int j;
		for (j = 0;j<m[i].n&&j<m[i+1].n; ++j)
		{
			if ((*(m[i].p + j)) != (*(m[i + 1].p + j)))
			{
				if (j > lon) lon = j, pos = i;
				break;
			}
		}
		if (j > lon) lon = j, pos = i;
	}
	string *stemp = new string(m[pos].p, lon);
	delete []m;
	return *stemp;
}



















