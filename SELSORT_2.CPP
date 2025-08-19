#include <iostream>
#include <string.h>
using namespace std;

struct SinhVien
{
	int MaSV;
	char Ten[10];
};

void InMang(SinhVien a[], int n)
{
   for(int i=0; i< n; i++)
     cout<<a[i].MaSV<<" - "<<a[i].Ten<<endl;
}

void SelectionSort(SinhVien a[], int n) 
{
	for(int i = 0; i< n-1; i++)	
	{
	    int k = i;
	    for(int j = i+1; j< n; j++)
		 	if (strcmp(a[j].Ten, a[i].Ten) < 0)
				k = j;
	    if (k!=i) swap(a[k], a[i]);
	}
}

void InsertionSort(SinhVien a[], int n) 
{
	int i, j;
	SinhVien x;
	for(i = 1; i< n; i++)
	{
	    x = a[i];
	    j= i-1;
	    while(j>=0 && strcmp(a[j].Ten,  x.Ten) > 0)
	    {
     	 	a[j+1] = a[j];
		 	j--;	
	    }
       a[j+1] = x;
	}
}

int main()
{
	SinhVien a[100];
	int n, i, j;

	n = 4;
	a[0].MaSV = 6210; strcpy(a[0].Ten, "Nam");
	a[1].MaSV = 6211; strcpy(a[1].Ten, "Ha");
	a[2].MaSV = 6212; strcpy(a[2].Ten, "Tuan");
	a[3].MaSV = 6213; strcpy(a[3].Ten, "An");
	
	cout<<"Truoc khi sap xep: "<<endl;
	InMang(a, n);

	InsertionSort(a, n);

   cout<<endl<<"Sau khi sap xep: "<<endl;
   InMang(a, n);

}
