    #include <iostream>
    #include <string.h>    
    #include <windows.h>
    #include <conio.h>    
    using namespace std;
    
    #define X 20
    #define Y 10
    #define WIDTH 40
    
    // gia lap ham gotoxy trong Windows
    void gotoxy(short xx, short yy)
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);        
        COORD c = { xx, yy };
        SetConsoleCursorPosition(h, c);
        SetConsoleTextAttribute(h, 12);
    }

    int main()
    {
       char s[500];
       char t[500];
       char u[500];       
       cout<< "Nhap chuoi: "; gets(s);
       memset(t, ' ', WIDTH);
       t[WIDTH] = 0;
       strcat(s, t);
       strcat(t, s);
             
       int i = 0, n = strlen(t); 
       while(_kbhit()== 0)
       {
          strcpy(u, &t[i]);
          u[WIDTH] = 0;
          i++;
          if (i == n - WIDTH) i= 0;

          gotoxy(X, Y); cout<< u;
          Sleep(100);
       }
       return 0;
    }

