#include <iostream>
#include <fstream>

using namespace std;

bool czy_pierwsza(int liczba){

    if (liczba < 2){

        return false;

    }


    for(int i=2; i*i <= liczba; i++){

        if(liczba%i == 0){

            return false;

        }

    }

    return true;
}



int main()
{
    // ifstream in_pary("przyklad.txt");

    ifstream in_pary("pary.txt");
    ofstream wyniki("wyniki4.txt");

    wyniki << "4.1 " << endl;

    int liczba;
    string slowo;

    while( in_pary >> liczba >> slowo){

        // cout << liczba << " " << slowo << endl;

        if( liczba > 4 &
            liczba % 2 == 0){

                int max_roznica = 0;
                int mniejsza = 0;

                for(int i = 3; i <= (liczba/2)+1; i++ )
                {


                    if (czy_pierwsza(i)){

                        int reszta = liczba - i;

                        if (czy_pierwsza(reszta)){


                                if (max_roznica >= i - reszta ){
                                    max_roznica = i - reszta;
                                    mniejsza = i;

                                }
                        }
                    }
                }
                wyniki << "   " << liczba << " " << mniejsza << " " << liczba-mniejsza << endl;

        }


    }

    in_pary.close();


    // Zadanie 4.3.
    // in_pary.open("przyklad.txt");

    in_pary.open("pary.txt");


    wyniki << "4.2. " << endl;


    while( in_pary >> liczba >> slowo){

        // cout << slowo << endl;

        int maks_dlugosc = 0;
        char maks_litera = '\0';

        int biezaca_dlugosc = 0;
        char biezacy_znak = '\0';


        for( int i = 1; i < slowo.length(); i++ ){

                if( slowo[i-1] == slowo[i] ){

                    biezaca_dlugosc++;

                }else{

                    biezaca_dlugosc = 1;

                }

                if( biezaca_dlugosc > maks_dlugosc){
                        maks_dlugosc = biezaca_dlugosc;
                        maks_litera =  slowo[i-1];
                }
        }

        string fragment="";

        for(int i = 0; i < maks_dlugosc; i++){
            fragment += maks_litera;
        }

        // cout << fragment << "   " << maks_liter << endl;

        wyniki << "   " << fragment << " " << maks_dlugosc << endl;
        // cout << "   " << fragment << " " << maks_dlugosc << endl;

        char znak;
        // cin >> znak;

    }


    in_pary.close();


    // Zadanie 4.3.
    in_pary.open("pary.txt");
    // in_pary.open("przyklad.txt");

    wyniki << "4.3. " << endl;

    int min_liczba = 20;
    string min_slowo = "zzzzzzzzzzzzzzzzzzzzzz";

    while( in_pary >> liczba >> slowo){

        if ( liczba == slowo.length() ){

            // cout << "   " << liczba << " " << slowo << endl;

            if( liczba <= min_liczba)
            {

                    if( slowo < min_slowo ){

                            min_slowo = slowo;
                    }

                    min_liczba = liczba;


            }

        }

    }

    wyniki << "   " << min_liczba << " " << min_slowo << endl;


    return 0;
}
