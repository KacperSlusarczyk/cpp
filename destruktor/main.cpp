#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class Tablica
{
public:
    int rozmiar;
    int *t;

    Tablica(int rozmiar)
        : rozmiar(rozmiar)
    {
        t = new int[rozmiar];
    }

    void losuj()
    {
        srand(time(NULL));

        for(int i=0; i<rozmiar; i++)
            t[i] = rand() % 100;
    }

    int maxi()
    {
        int maxi = t[0];
        for(int i=0; i<rozmiar; i++)
            if(t[i] > maxi)
                maxi = t[i];

        return maxi;
    }

    int mini()
    {
        int mini = t[0];
        for(int i=0; i<rozmiar; i++)
            if(t[i] < mini)
                mini = t[i];

        return mini;
    }

    int suma()
    {
        int suma = 0;
        for(int i=0; i<rozmiar; i++)
            suma += t[i];

        return suma;
    }

    int srednia()
    {
        int sumaElem = suma();
        float srednia = float(sumaElem) / rozmiar;
        return srednia;
    }

    void wyswietl()
    {
        for(int i=0; i<rozmiar; i++)
            cout << t[i] << " ";

        cout << endl;
    }

    // DESTRUKTOR BEZ PARAMETROW
    ~Tablica()
    {
        delete[] t;
    }
};

int main()
{
    Tablica Tab(20);

    Tab.losuj();
    Tab.wyswietl();
    cout << "Max: " << Tab.maxi() << endl;
    cout << "Min: " << Tab.mini() << endl;
    cout << "Suma: " << Tab.suma() << endl;
    cout << "Srednia: " << Tab.srednia() << endl;

    return 0;
}
