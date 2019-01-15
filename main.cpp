#include <iostream>
#include <conio.h>
#include <math.h>
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
    c[0] = na;// size

    return c;
}
short int *zarb_array(short int *a,int na, int b,int j)
{
    short int *c;
    c = new short int[maxadad];

    for (int i=1; i<=maxadad;i++)
        c[i] = -1;
    c[0] = na+1;
    for (int i =0 ; i<j ; i++)
    {
        c[na+i+2] = 0;
        c[0]++;
    }
    for (int i = na ; i>=1; i--)
    {
        int zarb;
        c[i] = (c[i]==-1)?0:c[i];
        c[i+1] = (c[i+1]==-1)?0:c[i+1];
        zarb = a[i] * b + c[i+1];
        c[i+1] = zarb % 10;
        c[i] = zarb / 10;
    }

    rzero(c);
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

short int *tafrigh_sub(short int *a,int na, short int *b, int nb)
{
    bool manfi=false;

    short int *c;
    c = new short int [maxadad];

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
        {
            if (b[i] > a[i])
            {
                    swap (a,b);
                    swap (na,nb);
                    manfi = !manfi;
                    break;
            }
            if (a[i] > b[i])
            {
                break;
            }
        }
    int d = na - nb; // d = tafazel tedad argham.

    for ( int i=nb; i>0; i--)
    {
        int p = i + d;  // p = shomarande a.
        int kam = a[p] - b[i];
        if (b[i] == 0)
            continue;

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
        c[0] = na;
     //   cout << "\nMinus Result: ";
        for (int i= 1;i<=na;i++)
            {
                c[i] = a[i];
    //            cout <<endl<< c[i];
            }
    //    cout << a[i];
    return c;
}
short int *zarb_sub(short int *a,int na, short int *b, int nb)
{
    int m;
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
    int sizef = sum[0]+1;
    int k;

    for ( k = 1; k <= sizef ; k++)
        if (sum[k] != 0)
            break;

    //cout << endl;
    //if (k > sizef)
    //    cout << "0";
    //for (int i = k;i<=sizef ; i++)
    //    cout << sum[i];

    c[0] = -1;
    if (k > sizef)
    {
        c[1] = 0;
        c[0] = 1;
    }
    for (int i = k;i<=sizef ; i++)
    {
        if (c[0] == -1 && c[i] != 0)
        {
            c[0] = 0;
        }

        if (c[0] != -1)
        {
          c[i] = sum[i];
          c[0]++;
        }
    }
    return c;
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

string taghsim_sub(short int *a,int na, short int *b, int nb)
{
    cout << endl;
    int n1,n2,k;
    string out = "";
    short int *c;
    c = new short int [maxadad];
    short int *d;
    d = new short int [maxadad];
    short int *q;
    q = new short int [maxadad];
    int power,n=0,I = 1;

if (arr_comp(a,na,b,nb))
{
        a[0] = na;
    while (arr_comp_even(a,a[0],b,nb))
    {

        if (arr_comp_even(a,nb,b,nb))
        {
            for ( k =1; k<=nb; k++)
            {
                c[k] = a[k];
            }
        }
        else
        {
            for ( k =1; k<=nb+1; k++)
            {
                c[k] = a[k];
                if (I != 1)
                {
                   // q[I++] = 0;
                }
            }
        }
        c[0] = k-1;

        for ( int i=2 ; i<=10 ; i++)
        {
            d = zarb_array(b,nb,i,0);

            if (arr_comp(d,d[0],c,k-1))
            {
                d = zarb_array(b,nb,i-1,0);
                power = a[0] - d[0];
                for(int g=1; g<=power; g++)
                {
                    addzero(d);
                }
                if (arr_comp(d,d[0],a,a[0]))
                    d[0]--;



                q[I++] = i-1;

                a = tafrigh_sub(a,a[0],d,d[0]);
                n = zeroes(a);

                for (int i=1; i< n-nb ; i++)
                {

                    q[I++] = 0;
                }
                rzero(a);
                break;
            }
        }
    }
        cout << "\n\n";
        for (int j=1; j<I; j++)
            cout << q[j];


        return out;
    }
    else
    {
        return "<1";
    }

}
int main()
{
   short int a[maxadad],b[maxadad],na,nb;
   int n[2];
   n[0] = set_array(a);
   cout << endl;
   n[1] = set_array(b);
   //tafrigh_sub(a,n[0],b,n[1])
   cout << taghsim_sub(a,n[0],b,n[1]);
    return 0;
}
