#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "windows.h"
#include <WINDOWS.H>
#include <dos.h>
#include <WinBase.h>
int a[25][35];//记录下棋位置，以防止“吃子”现象发生，1代表白棋●，2代表黑棋○
int C[25][35]={0};//记录可消除棋子最长长度
int D[25][35]={100};//记录可消除棋子最短长度
int CF[25][35]={0};//记录最长方向12345678逆时针方向记录
int DF[25][35]={0};//记录最短方向12345678逆时针方向记录
int score1,score2;//双方的分数计数变量
int ND,pp=1;//难度调节变量
void position(int x,int y)
{
    COORD pos={x,y};
    HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(Out,pos);
}
int qipan()
{
    a[25][35]={0};
    int i,j,k=1;
    printf("   1   2   3   4   5   6   7   8   \n");//标示列数
    printf(" ┌─┬─┬─┬─┬─┬─┬─┬─┐\n");
    for(i=1;i<=15;i++)//输出表格
    {
        if(i%2!=0)
        {
            printf("%d",k++);//标示行数
            for(j=1;j<=17;j++)
            {
                if(j%2!=0)
                {
                    printf("│");
                }
                else if(j%2==0);
                {
                    printf(" ");
                }
            }
        }
        else if(i%2==0)
        {
            printf(" ");
            printf("├");
            for(j=1;j<=15;j++)
            {
                    if(j%2!=0)
                    {
                        printf("─");
                    }
                    else if(j%2==0)
                    {
                        printf("┼");
                    }
            }
            printf("┤");
        }
        printf("\n");
    }
    printf(" └─┴─┴─┴─┴─┴─┴─┴─┘\n");
    score1=score2=2;
    printf("白棋得分：%d\n",score1);
    printf("黑棋得分：%d\n",score2);
    position(15,14);//初始化棋盘
    printf("○");
    a[15][14]=2;
    position(15,16);
    printf("●");
    a[15][16]=1;
    position(19,14);
    printf("●");
    a[19][14]=1;
    position(19,16);
    a[19][16]=2;
    return 0;
}
void guize(int now,int x,int y)//定义规则函数
{
    int X,Y,K=0,i,j,X1,Y1,i1,K1=0;
            if(y+4<=22)//由当前位置向下找
            {
                for(Y=y+2;Y<=22;Y=Y+2)
                {
                    if(a[x][Y]==a[x][y])
                    {
                        for(i=y+2,K=0;i<Y;i=i+2)
                        {

                            K++;
                            a[x][i]=a[x][y];
                            position(x,i);
                            if(now==1)
                            printf("●");
                            else if(now==2)
                            printf("○");
                        }
                        break;
                    }
                    else if(a[x][Y]==0)
                    break;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(y-4>=8)//由当前位置向上找
            {
                for(Y=y-2;Y>=8;Y=Y-2)
                {
                    if(a[x][Y]==a[x][y])
                    {
                        for(i=y-2,K=0;i>Y;i=i-2)
                        {
                            K++;
                            a[x][i]=a[x][y];
                            position(x,i);
                            if(now==1)
                            printf("●");
                            else if(now==2)
                            printf("○");
                        }
                        break;
                    }
                    else if(a[x][Y]==0)
                    break;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(x+8<=31)//由当前位置向右找
            {
                for(X=x+4;X<=31;X=X+4)
                {
                    if(a[X][y]==a[x][y])
                    {
                        for(i=x+4,K=0;i<X;i=i+4)
                        {
                            K++;
                            a[i][y]=a[x][y];
                            position(i,y);
                            if(now==1)
                            printf("●");
                            else if(now==2)
                            printf("○");
                        }
                        break;
                    }
                    else if(a[X][y]==0)
                    break;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(x-8>=3)//从当前位置向左找
            {
                for(X=x-4;X>=3;X=X-4)
                {
                    if(a[X][y]==a[x][y])
                    {
                        for(i=x-4,K=0;i>X;i=i-4)
                        {
                            K++;
                            a[i][y]=a[x][y];
                            position(i,y);
                            if(now==1)
                            printf("●");
                            else if(now==2)
                            printf("○");
                        }
                        break;
                    }
                    else if(a[X][y]==0)
                    break;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(x+8<=31&&y-4>=8)//从当前位置向右上角找
            {
                Y=y-2;
                for(X=x+4;X<=31;X=X+4)
                {
                    if(a[X][Y]==a[x][y])
                    {
                        j=y-2;
                        for(i=x+4,K=0;i<X;i=i+4)
                        {
                            K++;
                            a[i][j]=a[x][y];
                            position(i,j);
                            if(now==1)
                            printf("●");
                            else if(now==2)
                            printf("○");
                            j=j-2;
                        }
                        break;
                    }
                    else if(a[X][Y]==0)
                    break;
                    Y=Y-2;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(x-8>=3&&y-4>=8)//从当前位置向左上方找
            {
                Y=y-2;
                for(X=x-4;X>=3;X=X-4)
                {
                    if(a[X][Y]==a[x][y])
                    {
                        j=y-2;
                        for(i=x-4,K=0;i>X;i=i-4)
                        {
                            K++;
                            a[i][j]=a[x][y];
                            position(i,j);
                            if(now==1)
                                printf("●");
                            else if(now==2)
                                printf("○");
                            j=j-2;
                        }
                        break;
                    }
                    else if(a[X][Y]==0)
                        break;
                    Y=Y-2;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(x+8<=31&&y+4<=22)//从当前位置向右下方找
            {
                Y=y+2;
                for(X=x+4;X<=31;X=X+4)
                {
                    if(a[X][Y]==a[x][y])
                    {
                        j=y+2;
                        for(i=x+4,K=0;i<X;i=i+4)
                        {
                            K++;
                            a[i][j]=a[x][y];
                            position(i,j);
                            if(now==1)
                                printf("●");
                            else if(now==2)
                                printf("○");
                            j=j+2;
                        }
                        break;
                    }
                    else if(a[X][Y]==0)
                        break;
                    Y=Y+2;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
            if(x-8>=3&&y+4<=22)//从当前位置向左下方找
            {
                Y=y+2;
                for(X=x-4;X>=3;X=X-4)
                {
                    if(a[X][Y]==a[x][y])
                    {
                        j=y+2;
                        for(i=x-4,K=0;i>X;i=i-4)
                        {
                            K++;
                            a[i][j]=a[x][y];
                            position(i,j);
                            if(now==1)
                                printf("●");
                            else if(now==2)
                                printf("○");
                            j=j+2;
                        }
                        break;
                    }
                    else if(a[X][Y]==0)
                        break;
                    Y=Y+2;
                }
                if(now==1&&K!=0)
                {
                    position(10,24);
                    printf("%d",score1=score1+K);
                    position(10,25);
                    printf("%d",score2=score2-K);
                }
                else if(now==2&&K!=0)
                {
                    position(10,25);
                    printf("%d",score2=score2+K);
                    position(10,24);
                    printf("%d",score1=score1-K);
                }
                K=0;
            }
}
void renren()
{
    int now=1;//当前下棋用户，1代表白棋●，2代表黑棋○
    char ch;//获取键盘信息变量
    int px,py,x,y,s=0,N;//棋子位置变量
    while(score1&&score2)
    {
        x=3;
        y=8;
        px=3;
        py=8;
        if(now==2)
        printf("●");
        else if(now==1)
        printf("○");
        while(ch=getch())
    {
        if(ch==72)
        {
            px=x;
            if(y-2>=8)
                py=y-2;
        }
        else if(ch==80)
        {
            px=x;
            if(y+2<=22)
                py=y+2;
        }
        else if(ch==75)
        {
            if(x-4>0)
                px=x-4;
            py=y;
        }
        else if(ch==77)
        {
            if(x+4<=31)
                px=x+4;
            py=y;
        }
        else if(ch==13)//按下ENTER键后
        {
                s++;
                if(s==60)
                {
                    break;
                    break;
                }
                if(now==1)
                a[x][y]=1;//标记此坐标已有白棋
                else if(now==2)
                a[x][y]=2;//标记此坐标已有黑棋
                int scor1,scor2;
                scor1=score1;
                scor2=score2;
                guize(now,x,y);
                if(scor1==score1&&scor2==score2)
                {
                    a[x][y]=0;
                    x=px;
                    y=py;
                    MessageBox( NULL , TEXT("不“吃子”，无效下棋，请重下，如果没有位置可以“吃子”，请按TAB键跳过，让对方下棋子") , TEXT("错误！") , MB_OK);
                    continue;
                }
                 if(now==1)//改变白棋分数
                {
                    position(10,24);
                    printf("%d",++score1);
                    position(x,y);
                }
                else if(now==2)//改变黑棋分数
                {
                    position(10,25);
                    printf("%d",++score2);
                    position(x,y);
                }
                if(now==1)//改变now值为下次循环做准备
                now=2;
                else if(now==2)
                now=1;

        }
        else if(ch==27)//按ESC键重玩
        {
            x=1;
            y=6;
            position(x,y);
            qipan();
            position(19,16);
            //printf("○");
            renren();
        }
        else if(ch==9)
        {
            position(px,py);
            printf(" ");
            position(3,8);
            if(now==1)
                now=2;
            else if(now==2)
                now=1;
             break;
        }
        else
            continue;
                position(x,y);//光标移动到旧位置
                if(a[x][y]==0)
                printf(" ");
                else if(a[x][y]==1)//防止吃子现象发生
                printf("●");
                else if(a[x][y]==2)
                printf("○");
                x=px;
                y=py;
                position(px,py);//把光标移动到新位置
                if(ch==13)
                {
                    break;
                }
                else if(ch!=13)
                {
                    if(now==2)//在新位置输出棋子
                    printf("○");
                    else if(now==1)
                    printf("●");
                }

    }

    }
    if(score1>score2)
    {
        MessageBox( NULL , TEXT("恭喜！白棋获胜！") , TEXT("胜利了！") , MB_OK);
    }
    else if(score2>score1)
    {
        MessageBox( NULL , TEXT("恭喜！黑棋获胜！") , TEXT("胜利了！") , MB_OK);
    }
    else if(score1==score2)
    {
        MessageBox( NULL , TEXT("平局！") , TEXT("你好") , MB_OK);
    }
}
void chang(int I1,int J1,int max)
{
    if(CF[I1][J1]==1)//向右方下入棋子
     {
         if(a[I1+max*4+4][J1]==0)
         {
             position(I1+max*4+4,J1);
             Sleep(1000);
             printf("○");
             a[I1+max*4+4][J1]=2;
             guize(2,I1+max*4+4,J1);
             position(10,25);
             printf("%d",++score2);
         }
     }
     else if(CF[I1][J1]==3&&a[I1][J1-2*max-2]==0)//向上方下入棋子
     {
         position(I1,J1-2*max-2);
         Sleep(1000);
         printf("○");
         a[I1][J1-max*2-2]=2;
         guize(2,I1,J1-max*2-2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(CF[I1][J1]==5&&a[I1-max*4-4][J1]==0)//向左方下入棋子
     {
         position(I1-max*4-4,J1);
         Sleep(1000);
         printf("○");
         a[I1-max*4-4][J1]=2;
         guize(2,I1-max*4-4,J1);
         position(10,25);
         printf("%d",++score2);
     }
     else if(CF[I1][J1]==7&&a[I1][J1+max*2+2]==0)//向下方下入棋子
     {
         position(I1,J1+max*2+2);
         Sleep(1000);
         printf("○");
         a[I1][J1+max*2+2];
         guize(2,I1,J1+max*2+2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(CF[I1][J1]==2&&a[I1+max*4+4][J1-max*2-2]==0)//向右上方下入棋子
     {
         position(I1+max*4+4,J1-max*2-2);
         Sleep(1000);
         printf("○");
         a[I1+max*4+4][J1-max*2-2]=2;
         guize(2,I1+max*4+4,J1-max*2-2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(CF[I1][J1]==4&&a[I1-max*4-4][J1-max*2-2]==0)//向左上方下入棋子
     {
         position(I1-max*4-4,J1-max*2-2);
         Sleep(1000);
         printf("○");
         a[I1-max*4-4][J1-max*2-2]=2;
         guize(2,I1-max*4-4,J1-max*2-2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(CF[I1][J1]==6&&a[I1-max*4-4][J1+max*2+2]==0)//向左下方下入棋子
     {
         position(I1-max*4-4,J1+max*2+2);
         Sleep(1000);
         printf("○");
         a[I1-max*4-4][J1+max*2+2]=2;
         guize(2,I1-max*4-4,J1+max*2+2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(CF[I1][J1]==8&&a[I1+max*4+4][J1+max*2+2]==0)//向右下方下入棋子
     {
         position(I1+max*4+4,J1+max*2+2);
         Sleep(1000);
         printf("○");
         a[I1+max*4+4][J1+max*2+2]=2;
         guize(2,I1+max*4+4,J1+max*2+2);
         position(10,25);
         printf("%d",++score2);
     }
}
void duan(int I2,int J2,int min)
{
    if(DF[I2][J2]==1)//向右方下入棋子
     {
         if(a[I2+min*4+4][J2]==0)
         {
             position(I2+min*4+4,J2);
             Sleep(1000);
             printf("○");
             a[I2+min*4+4][J2]=2;
             guize(2,I2+min*4+4,J2);
             position(10,25);
             printf("%d",++score2);
         }
     }
     else if(DF[I2][J2]==3&&a[I2][J2-2*min-2]==0)//向上方下入棋子
     {
         position(I2,J2-2*min-2);
         Sleep(1000);
         printf("○");
         a[I2][J2-min*2-2]=2;
         guize(2,I2,J2-min*2-2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(DF[I2][J2]==5&&a[I2-min*4-4][J2]==0)//向左方下入棋子
     {
         position(I2-min*4-4,J2);
         Sleep(1000);
         printf("○");
         a[I2-min*4-4][J2]=2;
         guize(2,I2-min*4-4,J2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(DF[I2][J2]==7&&a[I2][J2+min*2+2]==0)//向下方下入棋子
     {
         position(I2,J2+min*2+2);
         Sleep(1000);
         printf("○");
         a[I2][J2+min*2+2];
         guize(2,I2,J2+min*2+2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(DF[I2][J2]==2&&a[I2+min*4+4][J2-min*2-2]==0)//向右上方下入棋子
     {
         position(I2+min*4+4,J2-min*2-2);
         Sleep(1000);
         printf("○");
         a[I2+min*4+4][J2-min*2-2]=2;
         guize(2,I2+min*4+4,J2-min*2-2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(DF[I2][J2]==4&&a[I2-min*4-4][J2-min*2-2]==0)//向左上方下入棋子
     {
         position(I2-min*4-4,J2-min*2-2);
         Sleep(1000);
         printf("○");
         a[I2-min*4-4][J2-min*2-2]=2;
         guize(2,I2-min*4-4,J2-min*2-2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(DF[I2][J2]==6&&a[I2-min*4-4][J2+min*2+2]==0)//向左下方下入棋子
     {
         position(I2-min*4-4,J2+min*2+2);
         Sleep(1000);
         printf("○");
         a[I2-min*4-4][J2+min*2+2]=2;
         guize(2,I2-min*4-4,J2+min*2+2);
         position(10,25);
         printf("%d",++score2);
     }
     else if(DF[I2][J2]==8&&a[I2+min*4+4][J2+min*2+2]==0)//向右下方下入棋子
     {
         position(I2+min*4+4,J2+min*2+2);
         Sleep(1000);
         printf("○");
         a[I2+min*4+4][J2+min*2+2]=2;
         guize(2,I2+min*4+4,J2+min*2+2);
         position(10,25);
         printf("%d",++score2);
     }
}
void xuanze()
{
     int i,j,max=0,min=1000;
     for(i=3;i<=31;i=i+4)
     {
         for(j=8;j<=22;j=j+2)
         {
             if(a[i][j]==2)
             {
                 int I,J,s=0,p=0;
                 if(j+4<=22)//从当前位置向下数数
                 {
                     for(J=j+2;J<=22;J=J+2)
                     {
                          if(a[i][J]==1)
                          s++;
                          else if(a[i][J]==0)
                          {
                              p=1;
                              break;
                          }
                          else if(a[i][J]==2)
                          break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=7;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=7;
                         }

                     }
                     s=0;
                     p=0;
                 }
                 if(j-4>=8)//从当前位置向上数数
                 {
                     p=0;
                     for(J=j-2;J>=8;J=J-2)
                     {
                         if(a[i][J]==1)
                         s++;
                         else if(a[i][J]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[i][J]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=3;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=3;
                         }
                     }
                     s=0;
                     p=0;
                 }
                 if(i+8<=31)//从当前位置向右数数
                 {
                     p=0;
                     for(I=i+4;I<=31;I=I+4)
                     {
                         if(a[I][j]==1)
                         s++;
                         else if(a[I][j]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[I][j]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=1;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=1;
                         }
                     }
                     s=0;
                     p=0;
                 }
                 if(i-8>=3)//从当前位置向左数数
                 {
                     p=0;
                     for(I=i-4;I>=3;I=I-4)
                     {
                         if(a[I][j]==1)
                         s++;
                         else if(a[I][j]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[I][j]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=5;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=5;
                         }
                     }
                     s=0;
                     p=0;
                 }
                 if(i+8<=31&&j-4>=8)//从当前位置向右上方数数
                 {
                     p=0;
                     J=j-2;
                     for(I=i+4;I<=31;I=I+4,J=J-2)
                     {
                         if(a[I][J]==1)
                         s++;
                         else if(a[I][J]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[I][J]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=2;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=2;
                         }
                     }
                     s=0;
                     p=0;
                 }
                 if(i+8<=31&&j+4<=22)//从当前位置向右下方数数
                 {
                     J=j+2;
                     p=0;
                     for(I=i+4;I<=31;I=I+4,J=J+2)
                     {
                         if(a[I][J]==1)
                         s++;
                         else if(a[I][J]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[I][J]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=8;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=8;
                         }
                     }
                     s=0;
                     p=0;
                 }
                 if(i-8>=3&&j+4<=22)//从当前位置向左下方数数
                 {
                     p=0;
                     J=j+2;
                     for(I=i-4;I>=3;I=I-4,J=J+2)
                     {
                         if(a[I][J]==1)
                         s++;
                         else if(a[I][J]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[I][J]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=6;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=6;
                         }
                     }
                     s=0;
                     p=0;
                 }
                 if(i-8>=3&&j-4>=8)//从当前位置向左上方数数
                 {
                     p=0;
                     J=j-2;
                     for(I=i-4;I>=3;I=I-4,J=J-2)
                     {
                         if(a[I][J]==1)
                         s++;
                         else if(a[I][J]==0)
                         {
                             p=1;
                             break;
                         }
                         else if(a[I][J]==2)
                         break;
                     }
                     if(p==1)
                     {
                         if(C[i][j]<s)
                         {
                             C[i][j]=s;
                             CF[i][j]=4;
                         }
                         if(D[i][j]>s&&s!=0)
                         {
                             D[i][j]=s;
                             DF[i][j]=4;
                         }
                     }
                     p=0;
                     s=0;
                 }
             }
         }
     }
     int I1,J1;//记录最长值的坐标
     int I2,J2;//记录最短值的坐标
     for(i=3;i<=31;i=i+4)//找到最大值最小值并储存
     {
         for(j=8;j<=22;j=j+2)
         {
             if(a[i][j]==2)
             {
                 if(max<C[i][j])
                 {
                     max=C[i][j];
                     I1=i;
                     J1=j;
                 }
                 if(min>D[i][j]&&D[i][j]!=0)
                 {
                     min=D[i][j];
                     I2=i;
                     J2=j;
                 }
             }
         }
     }
     if(ND==1&&max!=0)
     {
         chang(I1,J1,max);
     }
     else if(ND==1||ND==2);
     {
         chang(I1,J1,max);
     }

}
void renji()
{
    printf("○");
    MessageBox( NULL , TEXT("请输入难度，1代表困难，2代表一般，3代表简单") , TEXT("你好") , MB_OK);
    position(2,5);
    scanf("%d",&ND);
    int now=1;
    char ch;//定义接收键盘变量
    int px,py,x,y,s=0,N;
    while(score1&&score2)
    {
        if(now==2)
        {
            xuanze();
            now=1;
        }
        else if(now==1)
        {
                x=3;
                y=8;
                px=3;
                py=8;
                while(ch=getch())
              {
                if(ch==72)
                {
                    px=x;
                    if(y-2>=8)
                        py=y-2;
                }
                else if(ch==80)
                {
                    px=x;
                    if(y+2<=22)
                        py=y+2;
                }
                else if(ch==75)
                {
                    if(x-4>0)
                        px=x-4;
                    py=y;
                }
                else if(ch==77)
                {
                    if(x+4<=31)
                         px=x+4;
                    py=y;
                }
                else if(ch==13)//按下ENTER键后
                {
                    s++;
                    if(s==60)
                     {
                        break;
                        break;
                     }
                    a[px][py]=1;//标记此坐标已有白棋
                    int sco1,sco2;
                    sco1=score1;
                    sco2=score2;
                    guize(now,px,py);
                    if(sco1==score1&&sco2==score2)//改变白棋的分数
                    {
                        a[px][py]=0;
                        x=px;
                        y=py;
                        MessageBox( NULL , TEXT("无效下棋，如果没有位置可以“吃子”，请按TAB键让计算机下棋") , TEXT("错误") , MB_OK);
                        continue;
                    }
                    position(10,24);
                    printf("%d",++score1);
                    now=2;
                }
                else if(ch==27)//按ESC键重玩
                {
                    x=1;
                    y=6;
                    position(x,y);
                    qipan();
                    renji();
                }
                else if(ch==9)
                {
                    position(px,py);
                    printf(" ");
                    position(3,8);
                    if(now==1)
                    now=2;
                    else if(now==2)
                    now=1;
                    break;
                }
                else
                    continue;
                position(x,y);
                if(a[x][y]==0)
                printf(" ");
                else if(a[x][y]==1)
                printf("●");
                else if(a[x][y]==2)
                printf("○");
                x=px;
                y=py;
                position(x,y);
                if(ch==13)
                {
                    printf("●");
                    break;
                }
                else if(ch!=13&&ch!=8&&ch!=126)
                {
                   printf("●");
                }
              }
         }
    }
    if(score1>score2)
    {
        MessageBox( NULL , TEXT("恭喜！白棋获胜！") , TEXT("胜利了！") , MB_OK);
    }
    else if(score2>score1)
    {
        MessageBox( NULL , TEXT("恭喜！黑棋获胜！") , TEXT("胜利了！") , MB_OK);
    }
    else if(score1==score2)
    {
        MessageBox( NULL , TEXT("平局！") , TEXT("你好") , MB_OK);
    }

}
int main()
{
    int k;
    int qipan();//声明棋盘函数
    void renren();//声明人人对战函数
    void position(int x,int y);
    void guize(int now,int x,int y);
    printf("上下左右控制走棋，按Enter键确认。\n");//系统提示
    printf("按ESC键重玩一局\n");
    printf("请选择人机对战或人人对战\n");
    printf("人机对战请按1\n");
    printf("人人对战请按2\n");
    while(scanf("%d",&k)!=EOF)
    {
        if(k==1)
        {
            qipan();
            renji();
        }
        else if(k==2)
        {
            qipan();
            renren();
        }
        else
        {
            MessageBox( NULL , TEXT("请输入1或2") , TEXT("你好") , MB_OK);
            position(0,5);
            printf(" ");
        }
    }
    return 0;
}
