#include <iostream>
#include <conio.h>
#define maxadad 201
using namespace std;

int set_array(short int *a)
{
   char c;
   int n=0;
        c = '0';
        if(c>='0'&&c<='9' && n<maxadad  && !(c=='0' && (n==2 || (a[0] == -3 && n==3))) || (n == 0 && c == '-' && a[0] != -3))
        {
            if (n==0 && c != '-')
            {
                a[0] = -2;
                n++;
            }
            if (n==2 && a[1] == 0)
            {
                n--;
                cout << "\b \b";
                a[n] = c - '0';
            }
            else
            {
                a[n] = c - '0';
            }

            if (a[n] == -3)
            {
                cout<<"-";
                n++;
            }

            else

            {
                cout<<a[n];
                n++;
            }

        }
   while(1)
   {

        c = getch();
        if(c==8)
        {
            cout << "\b \b";
            if (n>1 || (n==1 && a[0] == -3))
            n--;
            if (n==1 && a[0] == -2)
            {
                n--;
            }
            if (n==0)
            a[0] = -2;
        }
        if(c==13 && !(n==1 && a[0] == -3) && n!=0)
            break;
        if(c>='0'&&c<='9' && n<maxadad  && !(c=='0' && ((n==2 && a[1] == 0) || (a[0] == -3 && (n==3 && a[1] == 0)))) || ((n == 0 || (n==2 && a[1] == 0)) && c == '-' && a[0] != -3))
        {
            if (n==0 && c != '-')
            {
                a[0] = -2;
                n++;
            }
            if (n==2 && a[1] == 0)
            {
                if (c == '-')
                {
                    n -= 2;
                    cout << "\b \b";
                    a[n] = c - '0';
                }
                else
                {
                    n--;
                    cout << "\b \b";
                    a[n] = c - '0';
                }
            }
            else
            {
                a[n] = c - '0';
            }

            if (a[n] == -3)
            {
                cout<<"-";
                n++;
            }

            else

            {
                cout<<a[n];
                n++;
            }

        }
    }
    return n-1;
}
short int *jam_array(short int *a,int na, short int *b, int nb)
{
    short int *c;
    c = new short int[maxadad];
    bool flag;

    if (nb > na)
    {
        swap (a,b);
        swap (na,nb);
    }
    int d = na-nb;

    for (int i=1; i<=na+1;i++)
        c[i] = 0;

    for (int i = na ; i>0 ; i--)
    {
        int sum;
        flag = true;
        if (i > d)
        {
            sum = a[i] + b[i-d] + c[i+1];
        }
        else
        {
            sum = a[i] + c[i+1];
        }
        c[i+1] = sum % 10;
        c[i] = sum / 10;
        if (sum/10)
        flag = false;
    }
    if (flag)
    {
        c[0] = 1;
    }
    else
    {
        c[0] = 0;
    }
    return c;
}
short int *zarb_array(short int *a,int na, int b,int j)
{
    short int *c;
    c = new short int[maxadad];

    for (int i=1; i<=maxadad;i++)
        c[i] = -1;

    for (int i = na ; i>=1; i--)
    {
        int zarb;
        c[i] = (c[i]==-1)?0:c[i];
        c[i+1] = (c[i+1]==-1)?0:c[i+1];
        zarb = a[i] * b + c[i+1];
        c[i+1] = zarb % 10;
        c[i] = zarb / 10;
    }
    c[0] = na+1;
    for (int i =0 ; i<j ; i++)
    {
        c[na+i+2] = 0;
        c[0]++;
    }
    return c;
}

void jam_sub(short int *a,int na, short int *b, int nb)
{
    short int *c;
    bool flag;

    c = jam_array(a,na,b,nb);

    cout << "\nResult =";
    if (c[0])
    {
        if (a[0] == -3)
            cout << "-";
        for (int i= 2;i<=na+1;i++)
            cout << c[i];
    }
    else
    {
        if (a[0] == -3)
            cout << "-";
        for (int i= 1;i<=na+1;i++)
            cout << c[i];
    }
}

void tafrigh_sub(short int *a,int na, short int *b, int nb)
{
    bool manfi=false;

    if (a[0] == -3)
        manfi = true;

    if (nb > na)
    {
        swap (a,b);
        swap (na,nb);
        manfi = !manfi;
    }
    if (nb == na)
        for (int i=1;i<=na;i++)
            if (b[i] > a[i])
            {
                    swap (a,b);
                    swap (na,nb);
                    manfi = !manfi;
                    break;
            }
    int d = na - nb; // d = tafazel tedad argham.

    for ( int i=nb; i>0; i--)
    {
        int p = i + d;  // p = shomarande a.
        int kam = a[p] - b[i];
        if (kam >= 0)
            a[p] = kam;
        else
        {
            a[p] = kam + 10;
            for (int j=p-1; j>0; j--)
            {
                if (a[j] == 0)
                {
                    a[j] = 9;
                }
                else
                {
                    a[j]--;
                    break;
                }
            }
        }

    }
    cout << "\nResult = ";
    int m;
    if (manfi)
    {
        cout << "-";
        m=0;
        while (++m)
            if (a[m] != 0 || m == na)
                break;
        for (int i= m;i<=na;i++)
        cout << a[i];
    }
    else
    {
        m=0;
        while (++m)
            if (a[m] != 0 || m == na)
                break;
        for (int i= m;i<=na;i++)
        cout << a[i];
    }
}
void zarb_sub(short int *a,int na, short int *b, int nb)
{
    int m;
    if (nb > na)
    {
        swap (a,b);
        swap (na,nb);
    }

    short int *c [200];
    for (int i=0;i<2;i++)
        c[i] = new short int[maxadad];

    for (int i=0; i<nb; i++)
    {
       c[i] = zarb_array(a,na,b[nb-i],i);
    }
    for ( m=0; m<nb; m++)
    {
        c[m+1] = jam_array(c[m],c[m][0],c[m+1],c[m+1][0]);
    }
    for (int j = 1;j<=maxadad;j++)
    {
        cout<< "OK0;";
        if (c[m+1][j] != -1)
        {
            cout << c[m+1][j];
        }
    }
}
int main()
{
   short int a[maxadad],b[maxadad],na,nb;
   int n[2];
   n[0] = set_array(a);
   cout << endl;
   n[1] = set_array(b);
   zarb_sub(a,n[0],b,n[1]);
    return 0;
}
