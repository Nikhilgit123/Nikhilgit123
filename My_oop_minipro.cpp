# include <iostream>
# include <windows.h>
# include <dos.h>
# include <time.h>
# include <conio.h>

# define SCREEN_WID 90
# define SCREEN_HID 26
# define WIN_WID 70

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = {' ','+','+',' ',
                   '+','+','+','+',
                   ' ','+','+',' ',
                   '+','+','+','+'};
int carPos = WIN_WID/2;
int score = 0;

void gotoxy(int x,int y)
{
    CursorPosition.X=x;
    CursorPosition.Y = y;

    SetConsoleCursorPosition(console,CursorPosition);

    }
    void SetCursor(bool visible,DWORD size)
    {
        if(size == 0)
        size = 20;

        CONSOLE_CURSOR_INFO lpCuror;
        lpCuror.bVisible = visible;
        lpCuror.dwSize = size;
        SetConsoleCursorInfo(console,&lpCuror);


    }
    void drawBorder()
    {
        for(int i=0;i<SCREEN_HID;i++)
        {
            for(int j=0;j<17;j++)
            {
                gotoxy(0+j,i);
                cout<<"$";
                gotoxy(WIN_WID-j,i);
                cout<<"$";


            }
        }
        for(int i=0;i<SCREEN_HID;i++)
        {
            gotoxy(SCREEN_WID,i);
            cout<<"+";

        }
    }
    void genEnemy(int ind)
    {
        enemyX[ind]=17 + rand()%(33);
    }
    void drawEnemy(int ind)
    {
        if(enemyFlag[ind]==true)
        {
            gotoxy(enemyX[ind],enemyY[ind]);
            cout<<"****";
            gotoxy(enemyX[ind],enemyY[ind]+1);
            cout<<"**";
            gotoxy(enemyX[ind],enemyY[ind]+2);
            cout<<"****";
            gotoxy(enemyX[ind],enemyY[ind]+3);
            cout<<"**";
        }
    }
    void eraseEnemy(int ind)
    {
        if(enemyFlag[ind]==true)
        {
            gotoxy(enemyX[ind],enemyY[ind]);
            cout<<"    ";
            gotoxy(enemyX[ind],enemyY[ind]+1);
            cout<<"    ";
            gotoxy(enemyX[ind],enemyY[ind]+2);
            cout<<"    ";
            gotoxy(enemyX[ind],enemyY[ind]+3);
            cout<<"    ";
        }
    }
    void resetEnemy(int ind)
    {
        eraseEnemy(ind);
        enemyY[ind] =1;
        genEnemy(ind);

    }
    void drawcar()
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                gotoxy(j+carPos,i+22);
                cout<<car[i][j];

            }
        }
    }
    void eraseCar()
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                gotoxy(j+carPos,i+22);
                cout<<"   ";

            }
        }
    }
    int collision()
    {
        if(enemyY[0]+4 >= 23)
        {
            if(enemyX[0]+4 - carPos >= 0 && enemyX[0]+4 - carPos < 9)
            {
                return 1;

            }
        }
        return 0;
    }
    void gameover()
    {
        system("cls");
        cout<<endl;
        cout<<"\t\t---------------------------------------------------"<<endl;
        cout<<"\t\t-----------------------------Game over-----------------"<<endl;
        cout<<"\t\t---------------------------------------------------------"<<endl<<endl;
        cout<<"\t\t press any key to go back";
        getch();

    }
    void updatescore()
    {
        gotoxy(WIN_WID + 7,5);
        cout<<"score:"<<score<<endl;
    
    }
    void play()
    {
        carPos = -1 + WIN_WID/2;
        score =0;
        enemyFlag[0]=1;
        enemyFlag[1]=0;
        enemyY[0]=enemyY[1]=1;

        system("cls");
        drawBorder();
        updatescore();
        genEnemy(0);
        genEnemy(1);

        gotoxy(WIN_WID +7,2);
        cout<<"Car game";
        gotoxy(WIN_WID + 6,4);
        cout<<"-------------------";
        gotoxy(WIN_WID + 6,4);
        cout<<"-------------------";
        gotoxy(WIN_WID + 6,6);
        cout<<"-------------------";
        gotoxy(WIN_WID + 7,12);
        cout<<"controle";
        gotoxy(WIN_WID + 7,13);
        cout<<"-----------";
        gotoxy(WIN_WID + 2,14);
        cout<<" A key - left";
        gotoxy(WIN_WID + 2,15);
        cout<<"D key - right";

        gotoxy(8,15);
        cout<<"press any key to start";
        getch();
        gotoxy(18,5);
        cout<<"                                   ";
        while(1)
        {
            if(kbhit())
            
            {
                char ch = getch();
                if(ch=='a'||ch=='A')
                {
                    if(carPos>18)
                    carPos -=4;

                }
                if(ch=='d'||ch=='D')
                {
                    if(carPos<50)
                    carPos +=4;

                }
                if(ch ==27)
                {
                    break;
                }

            }
            drawcar();
            drawEnemy(0);
            drawEnemy(1);
            if(collision() == 1 )
            {
                gameover();
               
                return ;
            }
            Sleep(50);
            eraseCar();
            eraseEnemy(0);
            eraseEnemy(1);

            if(enemyY[0]==10)
            if(enemyFlag[1]==0)
            enemyFlag[1]=1;

            if(enemyFlag[0]==1)
            enemyY[0]+=1;

            if(enemyFlag[1]==1)
            enemyY[1]+=1;

            if(enemyY[0] > SCREEN_HID-4)
            {
                resetEnemy(0);
                score++;
                updatescore();

            }
        }



    }
    int main()
    {
        SetCursor(0,0);
        srand((unsigned)time(NULL));
        do 
        {
            system("cls");
            gotoxy(10,5);
            cout<<"------------------------------------------------------------------------------";
            gotoxy(10,6);
            cout<<"                         car game(BY NIKHIL)           ";
            gotoxy(10,7);
            cout<<"------------------------------------------------------------------------------------";
            gotoxy(10,9);
            cout<<"1.start game";
            gotoxy(10,10);
            cout<<"2.quit";
            gotoxy(10,13);
            cout<<"Select option";
            char op = getche();
            if(op=='1') play();
            else if(op =='2') exit(0);
        }
        while(1);
       return 0;        
    }