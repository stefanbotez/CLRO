#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
char cif1[][20]={"zero"," unu "," doi "," trei "," patru "," cinci "," sase "," sapte "," opt "," noua "," zece ",
"unsprezece","doisprezece","treisprezece","paisprezece","cincisprezece","saisprezece","saptesprezece","optsprezece","nouasprezece","douazeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","treizeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","patruzeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","cincizeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","saizeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","saptezeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","optzeci ",
"xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","xxxx","nouazeci "};
char s[505],op='+',w[100],aux1[505],aux2[505],*p,aux[505];
int i,ok,op1=-1,op2=-1;
void tol(char *x)
{
    for(int i=0;x[i];i++)
            x[i]=tolower(x[i]);
}
int urm(char *x)
{
    if(x[1]=='d'&&x[2]=='o'&&x[3]=='u'&&x[4]=='a')
        if((x[5]=='s'&&x[6]=='u'&&x[7]=='t'&&x[8]=='e')||(x[5]=='m'&&x[6]=='i'&&x[7]=='i')||(x[5]=='m'&&x[6]=='i'&&x[7]=='l'))
            return 1;
    for(int j=1;j<=9;j++)
        if(strstr(x,cif1[j]))
        {
            int l=strlen(cif1[j]);
            char *xx=strstr(x,cif1[j]);
            if(strlen(x)==strlen(xx))
                if((x[l]=='s'&&x[l+1]=='u'&&x[l+2]=='t'&&x[l+3]=='e')||(x[l]=='m'&&x[l+1]=='i'&&x[l+2]=='i')||(x[l]=='m'&&x[l+1]=='i'&&x[l+2]=='l'))
                    return 1;
        }
    return 0;
}
int isDigit(char *x)
{
    if(x[1]=='d'&&x[2]=='o'&&x[3]=='u'&&x[4]=='a')
        return 1;
    for(int j=1;j<=9;j++)
        if(strstr(x,cif1[j]))
        {
            char *xx=strstr(x,cif1[j]);
            if(strlen(x)-strlen(xx)==0)
                return 1;
        }
    return 0;
}
void refacere()
{
    if(w[0]==' ')
        strcpy(w,w+1);
    for(int i=1;i<strlen(w);i++)
        if(w[i]==' '&&w[i-1]==' ')
        strcpy(w+i,w+i+1);
    for(int i=3;i<strlen(w);i++)
    {
//        if(w[i-3]==' '&&w[i-2]=='s'&&w[i-1]=='i'&&w[i]==' ')
//        {strcpy(w+i,w+i+1);strcpy(w+i-3,w+i-2);}
        if(w[i-3]=='z'&&w[i-2]=='e'&&w[i-1]=='c'&&w[i]=='i')
            strcpy(w+i-4,w+i-3);
    }
    if(strlen(w)>=5)
    for(int i=0;i<strlen(w)-5;i++)
        if(w[i]=='s'&&w[i+1]=='a'&&w[i+2]=='s'&&w[i+3]=='e'&&w[i+4]=='z')
        {
            w[i+2]='i';
            strcpy(w+i+3,w+i+4);
        }
    if(w[strlen(w)-1]==' ')
        strcpy(w+strlen(w)-1,w+strlen(w));
}
int nrc(int n)
{
    int a=0;
    while(n)
    {
        a++;n/=10;
    }
    return a;
}
struct word{
int numar;
int poz;}v[100];
bool compPoz(const word &a, const word &b)
{
    return a.poz < b.poz;
}
int numar(char x[])
{
    int n=0,i=0,ok=0;
    while(i<strlen(x))
    {
        if(x[i]>='0'&&x[i]<='9')
        {
            n=n*10+x[i]-'0';ok=1;
        }
        i++;
    }
    if(ok)
        return n;
    else
    {
        char del2[505];
        int nr=0;
        for(i=0;i<=90;i++)
        {
            strcpy(del2,x);
            while(strstr(del2,cif1[i]))
            {
                p=strstr(del2,cif1[i]);
                v[++nr].numar=i;
                v[nr].poz=strlen(x)-strlen(p);
                strcpy(del2,p+1);
            }
        }
        strcpy(del2,x);
        while(strstr(del2,"sute"))
        {
            p=strstr(del2,"sute");
            v[++nr].numar=100;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2,"suta"))
        {del2,
            p=strstr(del2,"suta");
            v[++nr].numar=100;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2,"mie"))
        {
            p=strstr(del2,"mie");
            v[++nr].numar=1000;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2,"mii"))
        {
            p=strstr(del2,"mii");
            v[++nr].numar=1000;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2,"milioane"))
        {
            p=strstr(del2,"milioane");
            v[++nr].numar=1000000;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2,"milion"))
        {
            p=strstr(del2,"milion");
            v[++nr].numar=1000000;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2," o "))
        {
            p=strstr(del2," o ");
            v[++nr].numar=1;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2," un "))
        {
            p=strstr(del2," un ");
            v[++nr].numar=1;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
        strcpy(del2,x);
        while(strstr(del2," doua "))
        {
            p=strstr(del2," doua ");
            v[++nr].numar=2;
            v[nr].poz=strlen(x)-strlen(p);
            strcpy(del2,p+1);
        }
//        strcpy(del2,x);
//        while(strstr(del2,"douazeci si doua"))
//        {
//            p=strstr(del2,"douazeci si doua");
//            v[++nr].numar=22;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"treizeci si doua"))
//        {
//            p=strstr(del2,"treizeci si doua");
//            v[++nr].numar=32;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"patruzeci si doua"))
//        {
//            p=strstr(del2,"patruzeci si doua");
//            v[++nr].numar=42;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"cincizeci si doua"))
//        {
//            p=strstr(del2,"cincizeci si doua");
//            v[++nr].numar=52;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"saizeci si doua"))
//        {
//            p=strstr(del2,"saizeci si doua");
//            v[++nr].numar=62;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"saptezeci si doua"))
//        {
//            p=strstr(del2,"saptezeci si doua");
//            v[++nr].numar=72;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"optzeci si doua"))
//        {
//            p=strstr(del2,"optzeci si doua");
//            v[++nr].numar=82;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
//        strcpy(del2,x);
//        while(strstr(del2,"nouazeci si doua"))
//        {
//            p=strstr(del2,"nouazeci si doua");
//            v[++nr].numar=92;
//            v[nr].poz=strlen(x)-strlen(p);
//            strcpy(del2,p+1);
//        }
        sort(v, v+nr+1, compPoz);
        n=0;int na=v[1].numar;
        for(int i=2;i<=nr;i++)
        {
            if(nrc(v[i].numar)>nrc(v[i-1].numar))
                na*=v[i].numar;
            else
            if(nrc(v[i-1].numar)-nrc(v[i].numar)<=2)
                na+=v[i].numar;
            else {n+=na;na=v[i].numar;}
        }
        n+=na;
        return n;
    }
}
void perator()
{
    if(strstr(s,"sum")||strstr(s,"adun")||strstr(s,"plus"))
        op='+';
    if(strstr(s,"inmult")||strstr(s,"produs")||strstr(s,"ori"))
        op='*';
    if(strstr(s,"diferen")||strstr(s,"minus"))
        op='-';
    if(strstr(s,"impart")||strstr(s,"divi"))
        op='/';
}
void delimitare()
{
    char *del;
    int ok=0;
    if(strstr(s," ori "))
    {
        del=strstr(s," ori ");
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," plus "))
    {
        del=strstr(s," plus ");
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }

    if(strstr(s," la "))
    {
        del=strstr(s," la ");
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," marit cu "))
    {
        del=strstr(s," marit cu ");
        op='+';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," marit de "))
    {
        del=strstr(s," marit de ");
        op='*';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," creste cu "))
    {
        del=strstr(s," creste cu ");
        op='+';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," creste de "))
    {
        del=strstr(s," creste de ");
        op='*';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," inmultit "))
    {
        del=strstr(s," inmultit ");
        op='*';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," minus "))
    {
        del=strstr(s," minus ");
        op='*';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," micsorat cu "))
    {
        del=strstr(s," micsorat cu ");
        op='-';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," micsorat de "))
    {
        del=strstr(s," micsorat de ");
        op='/';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," scade cu "))
    {
        del=strstr(s," scade cu ");
        op='-';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," scade de "))
    {
        del=strstr(s," scade de ");
        op='/';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," cu ")&&!strstr(s," creste cu ")&&!strstr(s," scade cu ")&&!strstr(s," inmultit cu ")&&!strstr(s," marit cu ")&&!strstr(s," micsorat cu "))
    {
        del=strstr(s," cu ");
        op='+';
        strcpy(aux2,del);
        strncpy(aux1,s,strlen(s)-strlen(del)+1);
        aux1[strlen(s)-strlen(del)+2]=NULL;
        ok=1;
    }
    if(strstr(s," si ")&&ok==0)
    {
        int ok2=0;
        for(int i=0;i<strlen(s)-7;i++)
            if((s[i]!='z'||s[i+1]!='e'||s[i+2]!='c'||s[i+3]!='i')&&s[i+4]==' '&&s[i+5]=='s'&&s[i+6]=='i')
            {
                del=s+i+5;
                strcpy(aux2,del);
                strncpy(aux1,s,strlen(s)-strlen(del)+1);
                aux1[strlen(s)-strlen(del)+2]=NULL;
                ok2=1;
            }
        if(ok2==0)
            for(int i=0;i<strlen(s)-1;i++)
                if(s[i]=='s'&&s[i+1]=='i')
                    if(isDigit(s+i+2)==0)
                    {
                        del=s+i;
                        strcpy(aux2,del);
                        strncpy(aux1,s,strlen(s)-strlen(del)+1);
                        aux1[strlen(s)-strlen(del)+2]=NULL;
                        ok2=1;
                    }
        if(ok2==0)
        for(int i=0;i<strlen(s)-1;i++)
                if(s[i]=='s'&&s[i+1]=='i')
                    if(isDigit(s+i+2)==1&&urm(s+i+2))
                    {
                        del=s+i;
                        strcpy(aux2,del);
                        strncpy(aux1,s,strlen(s)-strlen(del)+1);
                        aux1[strlen(s)-strlen(del)+2]=NULL;
                        ok2=1;
                    }
        if(ok2==0)
            for(int i=0;i<strlen(s)-4;i++)
                if(s[i]=='z'&&s[i+1]=='e'&&s[i+2]=='c'&&s[i+3]=='i'&&s[i+4]==' '&&s[i+5]=='s'&&s[i+6]=='i')
                {
                    del=s+i+5;
                    strcpy(aux2,del);
                    strncpy(aux1,s,strlen(s)-strlen(del)+1);
                    aux1[strlen(s)-strlen(del)+2]=NULL;
                    ok2=1;
                }

    }
}
void n2w(int n)
{

    int v[]={0,0,0,0,0,0,0,0,0};
    char cif1[][20]={"zero","unu","doi","trei","patru","cinci","sase","sapte","opt","noua","zece","unsprezece","doisprezece","treisprezece","paisprezece","cincisprezece","saisprezece","saptesprezece","optsprezece","nouasprezece"};
    char cif2[][20]={"zero","o","doua","trei","patru","cinci","sase","sapte","opt","noua"};
    int aux=n;
    int i=0;
    int ok=0;
    while(aux)
    {
        v[i++]=aux%10;
        aux/=10;
    }
    i--;
    if(v[8]&&v[8]!=1)
    {
        strcat(w,cif2[v[8]]);
        strcat(w," sute ");
        if(v[7]==0&&v[6]==0)
            strcat(w," de milioane ");
    }
    if(v[8]==1)
    {
        strcat(w,cif2[v[8]]);
        strcat(w," suta ");
        if(v[7]==0&&v[6]==0)
            strcat(w," de milioane ");
    }
    if(v[7]==1)
    {
        strcat(w,cif1[10+v[6]]);
        strcat(w," milioane ");
        ok=2;
    }
    if(v[7]!=0&&v[7]!=1)
    {
        strcat(w,cif2[v[7]]);
        strcat(w," zeci ");
        ok=1;
        if(v[6]==0)
            strcat(w," de milioane ");
    }
    if(v[6]&&ok==1)
    {
        strcat(w," si ");
        strcat(w,cif1[v[6]]);
        strcat(w," de milioane ");
    }
    if(v[6]&&ok==0&&v[6]!=1)
    {
        strcat(w,cif2[v[6]]);
        strcat(w," milioane ");
    }
    if(v[6]==1&&ok==0)
    {
        strcat(w," un milion ");
    }
    ok=0;
    if(v[5]&&v[5]!=1)
    {
        strcat(w,cif2[v[5]]);
        strcat(w," sute ");
        if(v[4]==0&&v[3]==0)
            strcat(w," de mii ");
    }
    if(v[5]==1)
    {
        strcat(w,cif2[v[5]]);
        strcat(w," suta ");
        if(v[4]==0&&v[3]==0)
            strcat(w," de mii ");
    }
    if(v[4]==1)
    {
        strcat(w,cif1[10+v[3]]);
        strcat(w," mii ");
        ok=2;
    }
    if(v[4]!=0&&v[4]!=1)
    {
        strcat(w,cif2[v[4]]);
        strcat(w," zeci ");
        ok=1;
        if(v[3]==0)
            strcat(w," de mii ");
    }
    if(v[3]&&ok==1)
    {
        strcat(w," si ");
        strcat(w,cif1[v[3]]);
        strcat(w," de mii ");
    }
    if(v[3]&&ok==0&&v[3]!=1)
    {
        strcat(w,cif2[v[3]]);
        strcat(w," mii ");
    }
    if(v[3]==1&&ok==0)
    {
        strcat(w,cif2[v[3]]);
        strcat(w," mie ");
    }
    ok=0;
    if(v[2]&&v[2]!=1)
    {
        strcat(w,cif2[v[2]]);
        strcat(w," sute ");
    }
    if(v[2]==1)
    {
        strcat(w,cif2[v[2]]);
        strcat(w," suta ");
    }
    if(v[1]==1)
    {
        strcat(w,cif1[10+v[0]]);
        ok=2;
    }
    if(v[1]!=0&&v[1]!=1)
    {
        strcat(w,cif2[v[1]]);
        strcat(w," zeci ");
        ok=1;
    }
    if(v[0]&&ok==1)
    {
        strcat(w," si ");
        strcat(w,cif1[v[0]]);
    }
    if(v[0]&&ok==0)
    {
        strcat(w,cif1[v[0]]);
    }
    if(n==0)strcpy(w," zero ");
}
int main()
{
    cout<<"Calculator in limba romana"<<endl;
    cout<<"Acesta poate face calcule simple de tipul operand1 operator"<<endl;
    cout<<"operand2,  in care operatorii sunt cei aritmetici (+,-,*,/),"<<endl;
    cout<<"plecand de la o propozitie interogativa in limba romana,"<<endl;
    cout<<"de genul \"Cat este suma dintre 3 si patru?\" sau"<<endl;
    cout<<"\"Care este rezultatul inmultirii lui zece cu paisprezece?\"."<<endl;
    cout<<"ATENTIE! Numerele de tipul 23 se scriu corect douazeci si trei"<<endl;
    cout<<"Puneti calculatorului intrebari, iar cand doriti sa opriti programul tastati \"stop\":"<<endl;
        cin.getline(s,505);
    while(!strstr(s,"stop"))
    {
        if(strlen(s)==0)
            {cout<<"0 + 0 = 0(zero)"<<endl;cin.getline(s,505);}
        else{
        tol(s);
        if(s[strlen(s)-1]!='?'&&s[strlen(s)-1]!='.')
            strcat(s," ");
        else s[strlen(s)-1]=' ';
        strcpy(aux,s);
        strcpy(s," ");
        strcat(s,aux);
        strcpy(aux,"x");
        delimitare();
        perator();
        op1=numar(aux1);
        op2=numar(aux2);
        cout<<op1<<" "<<op<<" "<<op2<<" = ";
        int rez;
        if(op=='+')
        {
            int o=0;
            rez=op1+op2;
            cout<<rez<<" ";
            if(rez<0){rez=-rez;o=1;}
            n2w(rez);
            refacere();
            if(o == 1)
                cout<<"(minus "<<w<<")"<<endl;
            else
            cout<<"("<<w<<")"<<endl;
        }
        if(op=='-')
        {
            int o=0;
            rez=op1-op2;
            cout<<rez<<" ";
            if(rez<0){rez=-rez;o=1;}
            n2w(rez);
            refacere();
            if(o == 1)
                cout<<"(minus "<<w<<")"<<endl;
            else
            cout<<"("<<w<<")"<<endl;
        }
        if(op=='*')
        {
            int o=0;
            rez=op1*op2;
            cout<<rez<<" ";
            if(rez<0){rez=-rez;o=1;}
            n2w(rez);
            refacere();
            if(o == 1)
                cout<<"(minus "<<w<<")"<<endl;
            else
            cout<<"("<<w<<")"<<endl;
        }
        if(op=='/')
        {
            if(op2==0)
                cout<<"INFINIT"<<endl;
            else
            {
                int o=0;
                rez=op1/op2;
                cout<<rez<<" ";
                if(rez<0){rez=-rez;o=1;}
                n2w(rez);
                refacere();
                if(o == 1)
                    cout<<"(minus "<<w<<")"<<endl;
                else
                cout<<"("<<w<<")"<<endl;
            }
        }
        strcpy(w,"");
        strcpy(aux1,"");
        strcpy(aux2,"");
        op1=0;
        op2=0;
        op='+';
        cin.getline(s,505);
    }}
    return 0;
}
