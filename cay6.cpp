#include <stdio.h>

struct nut {
  int info;
  nut *left,*right;	
};

typedef nut Node;

Node *goc,*goc1;

void khoitao(Node *&goc)
{ goc=NULL;
}
void mocnut(Node *&goc,int x)
{  if (goc==NULL)
     { goc=new Node;
       goc->info=x;
       goc->left=NULL;
       goc->right=NULL;
	 }
	else
	   if (goc->info>=x)
	     mocnut(goc->left,x);
	   else
	     mocnut(goc->right,x);	  
}
void taocay(Node *&goc)
{ int tam;
   do{ printf("\n Nhap 1 so nguyen,0:dung ");
       scanf("%d",&tam);
       if (tam!=0)
          mocnut(goc,tam);
   	 }while (tam!=0);
}
void duyetLNR(Node *goc)
{  if (goc!=NULL)
     { duyetLNR(goc->left);
       printf("%3d",goc->info);
       duyetLNR(goc->right);
	 }
}
int dem3(Node *goc)
{  if (goc==NULL) return 0;
   else
     if (goc->info %3==0)
       return 1+dem3(goc->left)+dem3(goc->right);
     else
	   return dem3(goc->left)+dem3(goc->right);
}
int max(int a,int b)
{if (a>b) return a;
   else return b;
 }
int chieucao(Node *goc)
 { if (goc==NULL) return 0;
    else
    return 1+max(chieucao(goc->left),chieucao(goc->right));
 }
 void saochep(Node *goc,Node *&goc1)
 { if (goc==NULL) goc1=NULL;
   else
    {goc1=new Node;
     goc1->info=goc->info;
     saochep(goc->left,goc1->left);
     saochep(goc->right,goc1->right);
	}
 }
 void inmuci(Node *goc,int muc, int i)
 { if (goc!=NULL)
      if (muc==i)
         printf("%3d",goc->info);
      else
	    { inmuci(goc->left,muc+1,i);
	      inmuci(goc->right,muc+1,i);
		   }   
 }
 int tongmuci(Node *goc,int muc, int i)
 { if (goc==NULL) return 0;
   else
    if (muc==i) return goc->info;
    else
    return tongmuci(goc->left,muc+1,i)+tongmuci(goc->right,muc+1,i);
 }
int main()
{khoitao(goc);khoitao(goc1);
 taocay(goc);
 printf("\n Ket qua duyet \n");
 duyetLNR(goc);
 /*printf("\n So nut chia het cho 3: %d \n",dem3(goc));
 printf("\n Chieu cao cay: %d \n",chieucao(goc));
 saochep(goc,goc1);
 printf("\n cay goc 1: \n");
 duyetLNR(goc1);*/
 printf("\n Cac nut muc 3: \n");
 inmuci(goc,1,3);
 printf("\n Tong cac nut o muc 3: %d \n",tongmuci(goc,1,3));
 return 0;
}