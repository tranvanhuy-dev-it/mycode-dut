#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
/*--KHAI BAO CAC HAM NGUYEN MAU--*/
/*--------------------------------*/
int NOT(int x);
int AND(int x,int y);
int OR(int x,int y);
int NAND(int x,int y);
int NOR(int x,int y);
int XOR(int x,int y);
void VIET();
/*--------------------------------*/
int main()
{
char ch;
tt:
printf("\n");
printf("\n\tBang chan tri cua dinh luat DE Morgan");
printf("\n");
VIET();
printf("\n");
printf("\nAn Enter tiep tuc.An phim ESC de thoat");
do
 {
 ch=getch();
 }while(ch!=13 && ch!=27);
if(ch==13) goto tt;
return(0);
}
/*--------------------------------*/
int AND(int x,int y)
{
return(x&&y);
}
/*--------------------------------*/
int OR(int x,int y)
{
return(x||y);
}
/*--------------------------------*/
int NOR(int x,int y)
{
return(!(x||y));
}
/*--------------------------------*/
int NAND(int x,int y)
{
return(!(x&&y));
}
/*--------------------------------*/
int NOT(int x)
{
return(!x);
}
int XOR(int x,int y)
{
return (x^y);
}
/*--------------------------------*/
void VIET()
{
int A,B,C,D,E,F,G,H;
printf("\n\tA\tB\tC\tD\tE\tF\tG\tH");
for(A=FALSE;A<=TRUE;A++)
for(B=FALSE;B<=TRUE;B++)
 {
 C=AND(A,B);
 D=OR(A,B);
 E=NOR(A,B);
 F=NAND(A,B);
 G=NOT(A);
 H=XOR(A,B);
 printf("\n\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d",A,B,C,D,E,F,G,H);
 }
}