#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int a[4][4],b[4][4],s,p;
char c;

void clrscr(){                  //funkija za clear screen
    system("@cls||clear");      //nasao na netu
}
int provera_svih_nula(){
    int i,j;
    for ( i = 0; i < 4; i++)
    {
        for(j=0;j<4;j--){
            if (a[i][j]==0){return 1;}
        }
    }
    return 0;
}
void cepaj_nule_u_b(){
    int i,j;
    for(i=0;i<4;i++){
        for ( j = 0; i < 4; ++i)
        {
            b[i][j]=0;
        }
    }
}
void generisi_random_b(){
    srand(time(NULL));
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            b[i][j]=rand();
        }
    }
}

int proveravam_da_li_je_polje_prazno(int i,int j){
    if(a[i][j]>0){
        return 1;       //proveravam da li je polje prazno
    }                   //o vracam vrednost
    else {
        return 0;
    }
}
void generisi_gore(){
    int i,max;
    srand(time(NULL));
    for(i=0;i<4;i++){
        if(proveravam_da_li_je_polje_prazno(3,i)==0){
            b[3][i]=rand();
        }
    }
    max=b[0][0];
    for(i=0;i<4;i++){
        if (max<b[3][i])
        {
            max=b[3][i];
        }
    }
    for ( i = 0; i < 4; ++i)
    {
        if(max==b[3][i]){
            a[3][i]=2;
        }
    }
}
void generisi_dole(){
    int i,max;
    srand(time(NULL));
    for(i=0;i<4;i++){
        if(proveravam_da_li_je_polje_prazno(0,i)==0){
            b[0][i]=rand();
        }
    }
    max=b[0][0];
    for(i=0;i<4;i++){
        if (max<b[0][i])
        {
            max=b[0][i];
        }
    }
    for ( i = 0; i < 4; ++i)
    {
        if(max==b[0][i]){
            a[0][i]=2;
        }
    }
}
void generisi_levo(){
    int i,max;
    srand(time(NULL));
    for(i=0;i<4;i++){
        if(proveravam_da_li_je_polje_prazno(i,3)==0){
            b[i][3]=rand();
        }
    }
    max=b[0][0];
    for(i=0;i<4;i++){
        if (max<b[i][3])
        {
            max=b[i][3];
        }
    }
    for ( i = 0; i < 4; ++i)
    {
        if(max==b[i][3]){
            a[i][3]=2;
        }
    }
}
void generisi_desno(){
    int i,max;
    srand(time(NULL));
    for(i=0;i<4;i++){
        if(proveravam_da_li_je_polje_prazno(i,0)==0){
            b[i][0]=rand();
        }
    }
    max=b[0][0];
    for(i=0;i<4;i++){
        if (max<b[i][0])
        {
            max=b[i][0];
        }
    }
    for ( i = 0; i < 4; ++i)
    {
        if(max==b[i][0]){
            a[i][0]=2;
        }
    }

}
void pomeranjelevo (){
    int next,i,j;
    int z;
    for(z=0;z<3;z++){
    for ( i = 0; i<3  ; i++){
        next= i+1;
        for ( j=0;j<4;j++)
        {
            if (proveravam_da_li_je_polje_prazno(j,i)==0){
                if(a[j][next]!=0){
                    p=1;
                }
                a[j][i]=a[j][next];
                a[j][next]=0;
            }
        }
    }
    }
}
void pomeranjedesno (){
    int next,i,j;
    int z;
    for(z=0;z<3;z++){
    for ( i = 3; i>0  ; i--){
        next= i-1;
        for ( j=0;j<4;j++)
        {
            if (proveravam_da_li_je_polje_prazno(j,i)==0){
                if(a[j][next]!=0){
                    p=1;
                }
                a[j][i]=a[j][next];
                a[j][next]=0;
                p=1;
            }
        }
    }
    }
}
void pomeranjegore (){
    int next,i,j;
    int z;
    for(z=0;z<3;z++){
    for ( i =0 ; i<3  ; i++){
        next= i+1;
        for ( j=0;j<4;j++)
        {
            if (proveravam_da_li_je_polje_prazno(i,j)==0){
                if(a[next][j]!=0){
                    p=1;
                }
                a[i][j]=a[next][j];
                a[next][j]=0;
            }
        }
    }
    }
}
void pomeranjedole (){
    int next,i,j;
    int z;
    for(z=0;z<3;z++){
    for ( i =3 ; i>0  ; i--){
        next= i-1;
        for ( j=0;j<4;j++)
        {
            if (proveravam_da_li_je_polje_prazno(i,j)==0){
                if(a[next][j]!=0){
                    p=1;
                }
                a[i][j]=a[next][j];
                a[next][j]=0;

            }
        }
    }
    }
}
void sabiranjelevo (){
    int next,i,j;
    for ( i = 0; i<3  ; i++){
        next= i+1;
        for ( j=0;j<4;j++)
        {
            if (a[j][i]==a[j][next]){
                a[j][i]*=2;
                a[j][next]=0;
                s=1;
            }
        }
    }
}
void sabiranjedesno (){
    int next,i,j;
    for ( i = 3; i>0  ; i--){
        next= i-1;
        for ( j=0;j<4;j++)
        {
            if (a[j][i]==a[j][next]){
                a[j][i]*=2;
                a[j][next]=0;
                s=1;
            }
        }
    }
}
void sabiranjegore (){
    int next,i,j;
    for ( i =0 ; i<3  ; i++){
        next= i+1;
        for ( j=0;j<4;j++)
        {
            if (a[i][j]==a[next][j]){
                a[i][j]*=2;
                a[next][j]=0;
                s=1;
            }
        }
    }
}
void sabiranjedole (){
    int next,i,j;
    for ( i =3 ; i>0  ; i--){
        next= i-1;
        for ( j=0;j<4;j++)
        {
            if (a[i][j]==a[next][j]){
                a[i][j]*=2;
                a[next][j]=0;
                s=1;
            }
        }
    }
}

void gore(){
    pomeranjegore();
    sabiranjegore();
    pomeranjegore();
    cepaj_nule_u_b();
    if( (provera_svih_nula()==0) && (s==0) && (p==0) ) {
        printf("Kraj igre\n");
        return ;
    }
    if((s==0) && (p==0)){
        ceociklus();
    }
    generisi_gore();
    ceociklus();
    return;
}


void dole(){
    pomeranjedole();
    sabiranjedole();
    pomeranjedole();
    cepaj_nule_u_b();
    if( (provera_svih_nula()==0) && (s==0) && (p==0) ) {
        printf("Kraj igre\n");
        return ;
    }
    if((s==0) && (p==0)){
        ceociklus();
    }
    generisi_dole();
    ceociklus();
    return;
}

void levo(){
    pomeranjelevo();
    sabiranjelevo();
    pomeranjelevo();
    cepaj_nule_u_b();
    if( (provera_svih_nula()==0) && (s==0) && (p==0) ) {
        printf("Kraj igre\n");
        return ;
    }
    if((s==0) && (p==0)){
        ceociklus();
    }
    generisi_levo();
    ceociklus();
    return ;
}

void desno(){
    pomeranjedesno();
    sabiranjedesno();
    pomeranjedesno();
    cepaj_nule_u_b();
    if( (provera_svih_nula()==0) && (s==0) && (p==0) ) {
        printf("Kraj igre\n");
        return ;
    }
    if((s==0) && (p==0)){
        ceociklus();
    }
    generisi_desno();
    ceociklus();
    return;

}
void ceociklus(){       //pomocu ove funkcije ispisujemo matricu
    clrscr();           // i trazimo korak (w/a/s/d)
    printf("You're playing 2048 created by SanZ\n\n\n");
    int i,j;
    p=0;
    s=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf(" %d       ",a[i][j]);
        }
        printf("\n\n\n\n");
    }
    c=getchar();
    switch(c){
    case 'a':
        levo();
        break;
    case 'w':
        gore();
        break;
    case 'd':
        desno();
        break;
    case 's':
        dole();
        break;
    default:
        ceociklus();
        break;
    }
    return;
    }


int main()
{
    printf("Welcome to 2048\n");
    int max,min,j,i;
    generisi_random_b();
    min=b[0][0];
    max=b[0][0];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(min>b[i][j]){min=b[i][j];}
            if(max<b[i][j]){max=b[i][j];}
        }
    }
    if((rand()%10)==1){
        a[rand()%4][rand()%4]=4;
    }

    else{
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(min==b[i][j]){a[i][j]=2;}
                if(max==b[i][j]){a[i][j]=2;}
            }
        }
    }

    ceociklus();
    return 0;
}
