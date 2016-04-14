#include <iostream>
using namespace std;
class arbore
{
public:
	struct nod
	{
		int cheie, hs, hd;
		nod *st, *dr, *parinte;
	};
	arbore()
	{
		nod* st = NULL;
		nod* dr = NULL;
		int cheie = 0;
		int h = 0;
	}
	void inaltime(nod *a)
	{
		nod *x = NULL, *y = NULL;
		x = a;
		if(x->st!=NULL)
			while(x->st!=NULL)
			{
				y = x->st;
				x->hs++;
				x = y;
			}
		else if(x->dr!=NULL)
			while(x->dr!=NULL)
			{
				y = x->dr;
				x->hd++;
				x = y;
			}
	}
	int factor(nod *a)
	{
		inaltime(a);
		return a->hd - a->hs;
	}
	void insertie(nod *k)
	{
		nod *radacina, *nodcurent, *pcurent;
		bool ok = 0;
		if (radacina != NULL)
		{
			nodcurent = radacina;
			if (k->cheie < nodcurent->cheie)
			{
				inaltime(nodcurent);
				while (nodcurent)
				{
					if (factor(nodcurent) != -2 || factor(nodcurent) != 2)
					{
						pcurent = nodcurent;
						nodcurent = nodcurent->st;
					}
					else if (factor(nodcurent) == 2)
						rotatiest(nodcurent);
					else if (factor(nodcurent) == -2)
						rotatiedr(nodcurent);
				}
				nodcurent->cheie = k->cheie;
			}
			else
			{	
				inaltime(nodcurent);
				while (nodcurent)
				{
					pcurent = nodcurent;
					nodcurent = nodcurent->dr;
				}
				nodcurent->cheie = k->cheie;
			}
		}
		else
			radacina = k;
	}
	nod* rotatiedr(nod *k)
	{
		nod* temp = k->st;
		k->st = temp->dr;
		temp->dr = k;
		inaltime(k);
		inaltime(temp);
		return temp;
	}
	nod* rotatiest(nod *k)
	{
		nod* temp = k->dr;
		k->dr = temp->st;
		temp->st = k;
		inaltime(k);
		inaltime(temp);
		return temp;
	}
	nod* afisare(nod *k)
	{
		if(k!=NULL)
		{
			nod *nodcurent=k, *pcurent=k->parinte;
			while(nodcurent)
			{
				cout<<nodcurent->cheie<< endl;
				if(nodcurent->st!=NULL)
				{
					pcurent=nodcurent;
					nodcurent=nodcurent->st;
				}
				else if(nodcurent->dr!=NULL)
				{	
					pcurent=nodcurent;
					nodcurent=nodcurent->dr;
				}
				else 
				{
					nodcurent=pcurent;
					pcurent=pcurent->parinte;
				}
			}
		}
	}
};
