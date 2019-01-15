#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define maxadad 201
using namespace std;
void rzero(short int *a)
{
    int na = a[0];
    for(int i=1;i<na;i++)
    {
        if (a[1] == 0)
                a[0]--;

        for(int j=1; j<na; j++)
        {
            if (a[j]!=0)
            {
                break;
            }
            else
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    if (a[0] < 1)
    {
        a[0] = 1;
        a[1] = 0;
    }

}
void nzero(short int *a,int k)
{
    int na = a[0];
    cout << "^:" << k<<endl;
    for(int i=1;i<=k;i++)
    {
        if (a[1] == 0)
                a[0]--;

        for(int j=1; j<na; j++)
        {
            if (a[j]!=0)
            {
                break;
            }
            else
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    if (a[0] < 1)
    {
        a[0] = 1;
        a[1] = 0;
    }

}
int zeroes(short int *a)
{
    int na=0;
    for(int i=1;i<=a[0];i++)
    {
        if (a[i] != 0)
            break;

        na++;
    }
    return na;

}
void addzero(short int *a)
{
    a[a[0]+1] = 0;
    a[0]++;
}
int get_operation()
{
    char c;
    while (1)
    {
        c = getch();
        if (c>'0' && c<'7')
            break;
        if (c == '+')
        {
            c = '1';
            break;
        }
        if (c == '-')
        {
            c = '2';
            break;
        }
        if (c == 'x')
        {
            c = '3';
            break;
        }
        if (c == '/')
        {
            c = '4';
            break;
        }
        if (c == '^')
        {
            c = '5';
            break;
        }
    }
    cout << c;
    return c;
}
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
    c[0] = na + 1;
    rzero(c);
    return c;
}
short int *jam_zarb_array(short int *a,int na, short int *b, int nb)
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
    c[0] = na+1;// size

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
short int *jam_sub(short int *a,int na, short int *b, int nb) // niazi be in tabe nist !!
{
    short int *c;

    c = jam_array(a,na,b,nb);

    return c;
}

short int *tafrigh_sub(short int *a,int na, short int *b, int nb)
{

    short int *c;
    c = new short int [maxadad];
    //cout << "\nA = ";
    //for (int i=1; i<=na;i++)
    //    cout << a[i];
    //cout << "\nB = ";
    //for (int i=1; i<=nb;i++)
    //    cout << b[i];

    if (nb > na)
    {
        swap (a,b);
        swap (na,nb);
    }
    if (nb == na)
        for (int i=1;i<=na;i++)
        {
            if (b[i] > a[i])
            {
                    swap (a,b);
                    swap (na,nb);
                    break;
            }
            if (a[i] > b[i])
            {
                break;
            }
        }
    a[0] = na;
    int d = na - nb; // d = tafazel tedad argham.

    for ( int i=nb; i>0; i--)
    {
        int p = i + d;  // p = shomarande a.
        int kam = a[p] - b[i];

        if (kam >= 0)
        {
            a[p] = kam;
        }
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
    //rzero(a);

//        cout << "\nMinus Result: ";
        for (int i= 0;i<=a[0];i++)
            {
                c[i] = a[i];
            }
                //    cout << a[i];
    rzero(c);
    return c;
}
short int *zarb_sub(short int *a,int na, short int *b, int nb)
{
    if (nb > na)
    {
        swap (a,b);
        swap (na,nb);
    }

    short int *c;
    c = new short int[maxadad];

    short int *sum;
    sum = new short int[maxadad];

    for (int i=0; i<maxadad; i++)
        sum[i] = 0;

    for (int i=0; i<nb; i++)
    {
       c = zarb_array(a,na,b[nb-i],i);
       sum = jam_zarb_array(c,c[0],sum,c[0]);
    }

    //for ( k = 1; k <= sizef ; k++)
    //    if (sum[k] != 0)
    //        break;
    rzero(sum);
    //cout << endl;
    //if (k > sizef)
    //    cout << "0";
    //for (int i = k;i<=sizef ; i++)
    //    cout << sum[i];

    //if (k > sizef)
    //{
     //   c[1] = 0;
    //    c[0] = 1;
    //}

    return sum;
}
bool arr_comp(short int *a,int na, short int *b, int nb)
{
    if (na < nb)
    {
        return 0;
    }
    else if (na > nb)
    {
        return 1;
    }

    for(int i = 1; i <=na ;i++)
        if (a[i] < b[i])
        {
            return 0;
        }
        else if (a[i] > b[i])
        {
            return 1;
        }

        return 0;
}
bool arr_comp_even(short int *a,int na, short int *b, int nb)
{
    if (na < nb)
    {
        return 0;
    }
    else if (na > nb)
    {
        return 1;
    }

    for(int i = 1; i <=na ;i++)
        if (a[i] < b[i])
        {
            return 0;
        }
        else if (a[i] > b[i])
        {
            return 1;
        }

        return 1;
}

short int *taghsim_sub(short int *a,int na, short int *b, int nb)
{
    int t,k=0;
    a[0] = na;
    b[0] = nb;
    short int *c,*d,*f;
    c = new short int [maxadad];
    d = new short int [maxadad];
    f = new short int [maxadad];
    int n=a[0]-b[0]+1;
    c[0] = 1;
    c[1] = 0;
    //while ()
    while(n>0)
    {
        f[0]=0;
        for(int i=1; i<= nb; i++)
        {
            f[i]=b[i];
            f[0]++;
        }

            n--;
        for (int i=1; i<=n; i++)
            addzero(f);
        t=0;
        while (arr_comp_even(a,a[0],c,c[0]))
        {
            t++;
            c = jam_array(c,c[0],f,f[0]);
        }
        d[++k] = t-1;
        c = tafrigh_sub(c,c[0],f,f[0]);
    }
    d[0] = k;
    rzero(d);

    return d;
}
short int *tavan_sub(short int *a,int na,short int *b,int nb)
{

    short int *c,*d,*s;
    s = new short int [2];
    s[1] = 1;
    s[0] = 1;

    c = new short int [maxadad];
    c[1] = 1;
    c[0] = 1;
    a[0] = na;

    b[0] = nb;
    d = new short int [maxadad];
    d[0] = 1;
    d[1] = 1;

    while (!(arr_comp(c,c[0],b,b[0])))
    {
        c = jam_zarb_array(c,c[0],s,s[0]);
        rzero(c);
        d = zarb_sub(d,d[0],a,na);
    }
    return d;
}
short int *jazr_sub(short int *a, int na)
{
    a[0] = na;
    short int *c,*d,*f;
    c = new short int [maxadad];
    d = new short int [maxadad];
    f = new short int [maxadad];
    int n=a[0]/2+1;
    c[0] = 1;
    c[1] = 0;

    //while ()
    while(n>0)
    {
        f[0] = 1;
        f[1] = 1;
        d[0] = 1;
        d[1] = 1;
            n--;
        for (int i=1; i<n; i++)
            addzero(f);

        while (arr_comp_even(a,a[0],d,d[0]))
        {
            c = jam_array(c,c[0],f,f[0]);
            d = zarb_sub(c,c[0],c,c[0]);
        }
        c = tafrigh_sub(c,c[0],f,f[0]);
    }


    return c;
}
void jam(short int *a, int na, short int *b, int nb)
{
    short int *c;
    c = new short int [maxadad];

    if ((a[0] == -3) && (b[0] == -3))
    {
        a[0] = na;
        b[0] = nb;
        c = jam_sub(a,na,b,nb);
        cout << "-";
    }
    else if ((a[0] == -3) && (b[0] != -3))
    {
        a[0] = na;
        b[0] = nb;
        c = tafrigh_sub(b,nb,a,na);
        if (arr_comp(b,nb,a,na))
            cout << "-";
    }
    else if ((a[0] != -3) && (b[0] == -3))
    {
        a[0] = na;
        b[0] = nb;
        c = tafrigh_sub(a,na,b,nb);
        if (arr_comp(a,na,b,nb))
            cout << "-";
    }
    else
    {
        a[0] = na;
        b[0] = nb;
        c = jam_sub(a,na,b,nb);
    }
    for (int i=1 ; i<=c[0] ; i++)
        cout << c[i];
}
void tafrigh(short int *a, int na, short int *b, int nb)
{
    short int *c;
    c = new short int [maxadad];

    if ((a[0] == -3) && (b[0] == -3))
    {
        if (arr_comp(a,na,b,nb))
            cout << "-";
        a[0] = na;
        b[0] = nb;
        c = tafrigh_sub(a,na,b,nb);
    }
    else if ((a[0] == -3) && (b[0] != -3))
    {
        a[0] = na;
        b[0] = nb;
        c = jam_sub(b,nb,a,na);
        cout << "-";
    }
    else if ((a[0] != -3) && (b[0] == -3))
    {
        a[0] = na;
        b[0] = nb;
        c = jam_sub(a,na,b,nb);
    }
    else
    {
        if (arr_comp(b,nb,a,na))
            cout << "-";
        a[0] = na;
        b[0] = nb;
        c = tafrigh_sub(b,nb,a,na);
    }
    for (int i=1 ; i<=c[0] ; i++)
        cout << c[i];
}
int zarb(short int *a, int na, short int *b, int nb)
{
    short int *c;
    c = new short int [maxadad];
    c = zarb_sub(a,na,b,nb);

    if (((a[0] == -3) || (b[0] == -3)) && !((a[0] == -3) && (b[0] == -3)))
    {
        cout << "-";
    }
    for (int i=1 ; i<=c[0] ; i++)
        cout << c[i];
}
void taghsim(short int *a, int na, short int *b, int nb)
{
    short int *c;
    c = new short int [maxadad];
    if (nb == 1 && b[1] ==1)
    {
        cout << "Error!";
    }
    else
    {
        if (arr_comp_even(a,na,b,nb))
        {
            if (((a[0] == -3) || (b[0] == -3)) && !((a[0] == -3) && (b[0] == -3)))
            {
                cout << "-";
            }
            c = taghsim_sub(a,na,b,nb);
            for (int i=1 ; i<=c[0] ; i++)
                cout << c[i];
        }
        else
        {
            cout << "< 1";
        }
    }
}
void tavan(short int *a, int na, short int *b, int nb)
{
    short int *c;
    c = new short int [maxadad];

    if (b[0] != -3)
    {
        if ((b[0] == 1) && (b[1] = 0))
        {
            cout << "1";
        }
        else
        {
            if (a[0] == -3)
            {
                if (b[nb]%2 != 0)
                {
                    cout << "-";
                }
            }

            c = tavan_sub(a,na,b,nb);
            for (int i=1 ; i<=c[0] ; i++)
            cout << c[i];
        }

    }
    else
    {
        cout << "< 1";
    }
}
void jazr(short int *a, int na)
{
    short int *b;
    b = new short int [maxadad];

    if (a[0] == -3)
    {
        cout << "Error!";
    }
    else
    {
        if (a[1] == 0 && na == 1)
        {
            cout << "0";
        }
        else
        {
            b = jazr_sub(a,na);
            for (int i = 1; i<= b[0] ; i++)
                cout << b[i];
        }
    }
}
int main()
{
   short int a[maxadad],b[maxadad],na,nb;
   int c;

   system("Color 74");
   cout << "#Please enter your first number : \n\n";
   na = set_array(a);
   system("cls");

   cout << "\n\n*Please , Select your desired operation:\n\n1.+    2.-    3.x    4./    5.^    6.Jazr\n\nTYPE: ";
   c = get_operation() - '0';
   system("cls");
   if(c!=6)
   {
       cout << "#Please enter your second number : \n\n";
       nb = set_array(b);
       system("cls");
   }
   cout << "1. ";
   if (a[0] == -3)
    cout << "-";
   for(int i=1; i<=na; i++)
    cout << a[i];
   if(c!=6)
   {
       cout << "\n2. ";
       if (b[0] == -3)
           cout << "-";
       for(int i=1; i<=nb; i++)
       cout << b[i];
   }

   //operations
   cout << endl << endl;
   if (c==1)
   {
       cout << "Operation: Jam +\n";
       jam(a,na,b,nb);
   }
   else if (c==2)
   {
       cout << "Operation: Tafrigh -\n";
       tafrigh(a,na,b,nb);
   }
   else if (c==3)
   {
       cout << "Operation: Zarb x\n";
       zarb(a,na,b,nb);
   }
   else if (c==4)
   {
       cout << "Operation: Taghsim /\n";
       taghsim(a,na,b,nb);
   }
   else if (c==5)
   {
       cout << "Operation: Tavan ^\n";
       tavan(a,na,b,nb);
   }
   else if (c==6)
   {
       cout << "Operation: Jazr ~\n";
       jazr(a,na);
   }
    return 0;
}
