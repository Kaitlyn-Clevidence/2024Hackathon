#include <iostream>
using namespace std;
void dispCardBorder(int x, int y){   
        /*" ___ "
        "/   \"
        "|   |"
        "\___/""*/
        printf("\e[m\e[%d;%dH/\e[53m   \e[55m\e[%d;%dH\\\e[%d;%dH|\e[%d;%dH|\e[%d;%dH\\___/",x+1,y,x+1,y+4,x+2,y,x+2,y+4,x+3,y);
}

void dispCard(int n,int x, int y){
        dispCardBorder(x,y);
        string c;
        switch(n%4){
        case 0:
                c="\e[48;2;200;0;0m";
                break;
        case 1:
                c="\e[48;2;0;0;200m";
                break;
        case 2:
                c="\e[48;2;0;200;0m";
                break;
        case 3:
                c="\e[48;2;200;200;0m";
                break;
        
        }
        for(int i=1;i<2;i++){for(int j=1;j<4;j++){printf("\e[%d;%dH",x+i,y+j);cout<<c<<"\e[53m \e[55m";}}
        for(int i=2;i<3;i++){for(int j=1;j<4;j++){printf("\e[%d;%dH",x+i,y+j);cout<<c<<" ";}}
        for(int j=1;j<4;j++){printf("\e[4m\e[%d;%dH",x+3,y+j);cout<<c<<" \e[24m";}
        printf("\e[%d;%dH",x+2,y+2);
        switch(n/4-1){
        case -1:
                cout<<"0";
                break;
        case 0:
                cout<<"1";
                break;
        case 1:
                cout<<"2";
                break;
        case 2:
                cout<<"3";
                break;
        case 3:
                cout<<"4";
                break;
        case 4:
                cout<<"5";
                break;
        case 5:
                cout<<"6";
                break;
        case 6:
                cout<<"7";
                break;
        case 7:
                cout<<"8";
                break;
        case 8:
                cout<<"9";
                break;
        case 9:
                cout<<"R";
                break;
        case 12:
                cout<<"S";
                break;
        case 10:
                printf("\e[%d;%dH",x+1,y+1);cout<<c+"+";
                printf("\e[%d;%dH",x+2,y+2);cout<<c+"2";
                printf("\e[%d;%dH",x+3,y+3);cout<<c+"+";
                break;
        case 11:
                printf("\e[%d;%dH",x+1,y+1);cout<<"\e[48;2;200;0;0m\e[53m"<<"+\e[55m";
                printf("\e[%d;%dH",x+3,y+1);cout<<"\e[48;2;0;0;200m"<<"+";
                printf("\e[%d;%dH",x+1,y+3);cout<<"\e[48;2;0;200;0m\e[53m"<<"+\e[55m";
                printf("\e[%d;%dH",x+2,y+2);cout<<c+"4";
                printf("\e[%d;%dH",x+3,y+3);cout<<"\e[48;2;200;200;0m"<<"+\e[55m";

                printf("\e[%d;%dH",x+1,y+2);cout<<"\e[48;2;0;200;0m\e[53m"<<"-\e[55m";
                printf("\e[%d;%dH",x+3,y+2);cout<<"\e[48;2;0;0;200m"<<"-";
                printf("\e[%d;%dH",x+2,y+1);cout<<"\e[48;2;200;0;0m"<<"|";
                printf("\e[%d;%dH",x+2,y+3);cout<<"\e[48;2;200;200;0m"<<"|";
                break;
        case 13:
                
                printf("\e[%d;%dH",x+1,y+1);cout<<"\e[48;2;200;0;0m\e[53m"<<" \e[55m";
                printf("\e[%d;%dH",x+3,y+1);cout<<"\e[48;2;0;0;200m"<<" ";
                printf("\e[%d;%dH",x+1,y+3);cout<<"\e[48;2;0;200;0m\e[53m"<<" \e[55m";
                printf("\e[%d;%dH",x+2,y+2);cout<<c+" ";
                printf("\e[%d;%dH",x+3,y+3);cout<<"\e[48;2;200;200;0m"<<" ";

                printf("\e[%d;%dH",x+1,y+2);cout<<"\e[48;2;0;200;0m\e[53m"<<" \e[55m";
                printf("\e[%d;%dH",x+3,y+2);cout<<"\e[48;2;0;0;200m"<<" ";
                printf("\e[%d;%dH",x+2,y+1);cout<<"\e[48;2;200;0;0m"<<" ";
                printf("\e[%d;%dH",x+2,y+3);cout<<"\e[48;2;200;200;0m"<<" ";
                
                break;
        }
}
void dispCard(char a,char b,int x, int y){
        int c;
        int d;
        switch(a){
                case 'r':c=0;break;
                case 'b':c=1;break;
                case 'g':c=2;break;
                case 'y':c=3;break;
        }
        switch(b){
                case '0':d=0;break;
                case '1':d=1;break;
                case '2':d=2;break;
                case '3':d=3;break;
                case '4':d=4;break;
                case '5':d=5;break;
                case '6':d=6;break;
                case '7':d=7;break;
                case '8':d=8;break;
                case '9':d=9;break;
                case 'R':d=10;break;
                case '+':d=11;break;
                case 'W':d=12;break;
                case 'S':d=13;break;
                case 'Y':d=14;break;
        }
        dispCard(a+b*4,x,y);
        
}
string e;
string* getIntString(int a){
        char c,d;
        switch(a%4){
                case 0:c='r';break;
                case 1:c='b';break;
                case 2:c='g';break;
                case 3:c='y';break;
        }
        switch(a/4-1){
                case 0:d='0';break;
                case 1:d='1';break;
                case 2:d='2';break;
                case 3:d='3';break;
                case 4:d='4';break;
                case 5:d='5';break;
                case 6:d='6';break;
                case 7:d='7';break;
                case 8:d='8';break;
                case 9:d='9';break;
                case 10:d='R';break;
                case 11:d='+';break;
                case 12:d='W';break;
                case 13:d='S';break;
                case 14:d='Y';break;
                default:
                     d=' ';break;
        }e[0]=c;e[1]=d;
        string* var;
        *var=c+d;
        return var;
}
#include <time.h>

bool randBool(int a, int b){
        int randIntCounter=0;
        for(int i=0;i<50;i++){
	        clock_t start_time = clock();
	        randIntCounter+=clock();
        }
        randIntCounter*=763;
        randIntCounter%=b;

        return randIntCounter<a?true:false;
}
void swap(string& a, string& b){
        string c=a;
        a=b;
        b=c;
}
void swap(int& a, int& b){
        int c=a;
        a=b;
        b=c;
}
string v[200];
int vi[200];
string* RANDOIMIZE(string value[],const int a){
        for (int i=0;i<a;i++){
                cout<<i<<" ";
        v[i]=value[i];
        }
        for(int i=0;i<a;i++){
                for(int j=0;j<a;j++){
                        if(randBool(1,2)&&j!=i){
                                swap(v[i],v[j]);
                        }
                }
        }
        for (int i=0;i<a;i++){
        value[i]=vi[i];
        }
        return v;

}
int* RANDOIMIZE(int value[],const int a){
        for (int i=0;i<a;i++){
        vi[i]=value[i];
        }
        for(int i=0;i<a;i++){
                for(int j=0;j<a;j++){
                        if(randBool(1,2)&&j!=i){
                                swap(vi[i],vi[j]);
                        }
                }
        }
        for (int i=0;i<a;i++){
        value[i]=vi[i];
        }
        return vi;

}
void dispCard(string s,int x, int y){
        dispCard(stoi(s),x,y);
}


void cardStack(int x,int y, int n){
        if(n==0){
                        /*" ___ "
        "/   \"
        "|   |"
        "\___/""*/
                //printf("\e[%d;%dH\e[m\e[5m _____ \e[25m",x,y);
                printf("\e[%d;%dH\e[m\e[5m/\e[53m     \e[55m\\\e[25m",x+1,y);
                printf("\e[%d;%dH\e[m\e[5m|     |\e[25m",x+2,y);
                printf("\e[%d;%dH\e[m\e[5m|     |\e[25m",x+3,y);
                printf("\e[%d;%dH\e[m\e[5m|     |\e[25m",x+4,y);
                printf("\e[%d;%dH\e[m\e[5m\\_____/\e[25m",x+5,y);
        }
}



/*
int main(int argc, char** argv){
    int strings[108];
    int n=0;
    for(int i=0;i<1;i++){
        for(int j=0;j<4;j++){
            strings[n]=(i*4+j);n++;
        }
    }
    for(int i=1;i<11;i++){
        for(int j=0;j<4;j++){
            strings[n]=(i*4+j);strings[n+1]=(i*4+j);n+=2;
        }
    }
    for(int i=11;i<16;i++){
        for(int j=0;j<4;j++){
            strings[n]=(i*4+j);n++;
        }
    }
    RANDOIMIZE(strings,104);
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            dispCard((strings[i*4+j]),5*j+2,5*i+2);
        }
    }
    cardStack(5,5,0);
    cout<<"\e[25;25H";
}

*/

/*
Colors:
0:Red
1:Blue
2:Green
3:Yellow

W: Wild +4
Y: Wild
+: +2
R: Reverse
S: Skip
0-3:'0'
4-7:'1'
8-11:'2'
12-15:'3'
16-19:'4'
20-23:'5'
24-27:'6'
28-31:'7'
32-35:'8'
36-39:'9'
40-43:'R'
44-47:'+'
48-51:'W'
52-55:'S'
56-59:'Y'
60..: DNE: Selected wild
*/