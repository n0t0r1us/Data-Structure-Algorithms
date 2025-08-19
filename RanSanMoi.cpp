#include <iostream>
using namespace std;

#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define MAX 100

// khai báo kieu du lieu la 1 toa do tren man hinh
struct ToaDo
{
    int x, y;       
};

int n;            // chieu dai con ran  
ToaDo r[MAX];     // Mang toa do cua con ran, r[0]: duoi, r[n-1]: dau
ToaDo moi;        // toa do moi
int dx, dy;       // huong di hien tai: dx=1, dy=0 : sang phai
                  //                    dx=-1, dy=0 : sang trai
                  //                    dx=0, dy=1 : sang xuong
                  //                    dx=0, dy=-1 : sang len

// Gia lap ham gotoxy tren moi truong Windows
void gotoxy(short xx, short yy)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { xx, yy };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// In ky tu c tai toa do t
void In(ToaDo t, char c)
{
    gotoxy(t.x, t.y);
    cout<< c;
}

// Dau ran co an trung duoi khong?
// return 1: co;
// return 0: khong
int AnDuoi()
{
    for(int i = 0; i< n-1; i++)
       if (r[i].x == r[n-1].x && r[i].y == r[n-1].y)
          return 1;
    return 0;
}

// Dau ran co va vao tuong khong?
// return 1: co;
// return 0: khong
int DungThanh()
{
    if (r[n-1].x < 0 || r[n-1].x > 79 || 
        r[n-1].y < 0 || r[n-1].y > 24) 
        return 1;
    else
        return 0;
}

// Kiem tra xem moi co nam tren minh con ran khong?
// return 1: co;
// return 0: khong
int MoiNamTrenConRan()
{
    for(int i = 0; i<= n; i++)
       if (r[i].x == moi.x && r[i].y == moi.y)
          return 1;
    return 0;
}

int main()
{
   int c, i, j;
   
   n = 3;                     // dau tien, con ran dai 3 nut
   r[0].x = 5; r[0].y = 5;
   r[1].x = 6; r[1].y = 5;
   r[2].x = 7; r[2].y = 5;
   dx = 1; dy = 0;            // huong di ban dau la sang phai
   
   srand((unsigned) time(NULL));
   moi.x = rand() % 80;       // sinh ngau nhien vi tri cua moi  
   moi.y = rand() % 25;
   
   for(i=0; i<n; i++)         // in con ran ra man hinh
      In(r[i], 'o');
   In(moi, 'o');              // in moi ra man hinh
   
   do{                        // vong lap nay lap den khi nhan phim Esc  
       while(!_kbhit())       // trong khi chua nhan phim thi di chuyen con ran 
       {
          // neu dau ran va vao moi                              
          if (r[n-1].x + dx == moi.x && r[n-1].y + dy == moi.y)
          {
             r[n++] = moi;    // an moi, moi tro thanh dau ran  
             do{
                moi.x = rand() % 80;       // sinh ra moi khac
                moi.y = rand() % 25;
                r[n].x = r[n-1].x + dx;
                r[n].y = r[n-1].y + dy;                
             } while (MoiNamTrenConRan());  // moi phai dam bao nam ngoai con ran
             In(moi, 'o');                                     
             Sleep(30);
          }
          else                            // neu dau ran khong va vao moi
          {                                                                
              In(r[0], ' ');              // xoa duoi
              
              for(i=0; i<n-1; i++)        // di chuyen con ran
                  r[i]= r[i+1];
              r[n-1].x += dx;             // vi tri moi cua dau ran
              r[n-1].y += dy;                              
    
              if (AnDuoi() || DungThanh())
              {
                  gotoxy(0, 0);              
                  cout<<"Ban da thua";
                  getchar();
                  return 1;
              }
              
              // in dau
              In(r[n-1], 'o');
              Sleep(100);
          }
       }
       
       c = getch();  // lay ma cua phim duoc nhan
       if (c == 72 && dy == 0) { dx = 0; dy = -1; }  // phim mui ten len
       if (c == 75 && dx == 0) { dx = -1; dy = 0; }  // phim mui ten qua trai
       if (c == 77 && dx == 0) { dx = 1; dy = 0; }   // phim mui ten qua phai            
       if (c == 80 && dy == 0) { dx = 0; dy = 1; }   // phim mui ten xuong                   
   }while (c!= 27);     // nhan Esc: ket thuc
          
   return 1;
}

