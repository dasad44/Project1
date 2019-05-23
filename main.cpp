#include <iostream>

using namespace std;

int main()
{
    int krawedzie, wierzcholki, maxi;
    cout<<"Podaj ilosc wierzchalokow i krawedzi:"<<endl;
    cin>>wierzcholki>>krawedzie;
    int tab[krawedzie][wierzcholki];
    cout<<"Podaj pierwszy, nastepnie z ktorym jest polaczony oraz jaka waga:" <<endl;
    for(int i = 0 ; i < krawedzie; i++)
    {
        for(int j = 0; j < 1; j++)
        {
            cin>>tab[i][0];
            cin>>tab[i][1];
            cin>>tab[i][2];
        }
    }

    maxi = tab[0][2];
    for(int i = 1; i < krawedzie; i++)
    {
        if(tab[i][2] > maxi)
            maxi = tab[i][2];
    }
    //cout<<"max = "<<maxi<<endl;

    //cout<<"krawedzie"<<(krawedzie+1)/2<<endl;
    //cout<<wierzcholki<<endl;
    int n = wierzcholki/2, weightCounter = 1, suma_wag = 0, counter0 = 2, waga_max = 0;
    if(wierzcholki % 2 == 0)
    {
        if(krawedzie %  2 == 0)
        {
            for(int i = 0; i < krawedzie/2 ; i ++)
            {
                waga_max = waga_max + tab[i][2];
            }
        }
        else
        {
            for(int i = 0; i < (krawedzie+1)/2 ; i ++)
            {
                waga_max = waga_max + tab[i][2];
            }
        }
        // cout<<waga_max<<endl;
        while(weightCounter <= maxi)
        {
            if(tab[0][2] == weightCounter)
            {
                suma_wag = suma_wag + tab[0][2];
                tab[0][2] = 0;
            }
            weightCounter++;
        }

        weightCounter = 1;
        for(int k = 0; k < maxi; k++)
        {
            for(int i = 1; i < wierzcholki; i++)
            {
                if(suma_wag < waga_max)
                {
                    if(tab[i][0] != 1 && tab[i][2] == weightCounter)
                    {
                        suma_wag = suma_wag + tab[i][2];
                        tab[i][2] = 0;
                        cout<<"waga: "<<suma_wag<<endl;
                    }
                }
            }
            weightCounter++;
        }
        for(int i = 0 ; i < krawedzie; i++)
        {
            for(int j = 0; j < 1; j++)
            {
                cout<<tab[i][0];
                cout<<tab[i][1];
                cout<<tab[i][2];
            }
            cout<<endl;
        }

    }
    else
    {
        cout<<"Graf nie jest dwudzielny"<<endl;
    }



    return 0;
}
