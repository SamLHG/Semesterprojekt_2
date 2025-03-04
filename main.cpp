#include <iostream>
#include "Person.h"
#include "Bil.h"
#include "Dato.h"
#include <string>
#include <chrono>
// aktiverer klasserne vi har lavet

using namespace std;

int main()
{

    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "Det er nuværende " << std::ctime(&t_c); //udskriver systemtiden
    std::tm* now_tm = std::localtime(&t_c);
    cout <<"Det er d. " << now_tm->tm_mday <<" i måneden " << (now_tm->tm_mon + 1) <<" klokken " << __TIME__ << " i år " << (now_tm->tm_year + 1900) << endl; //udskriver datoen og tiden
    Dato d1(20241225);
    Dato d2(20251215);
    Dato dd(20250314); //skaber et objekt med indholdet 20251403
    cout << "I dag er det d. " << dd.getDato() << endl; //udskriver datoen, endl er linjeskift
    cout << "I maaneden " << dd.getMaaned() << " og " << dd.getKvartal() << ". kvartal" << endl;
    cout << "I aaret " << dd.getAar() << endl;
    dd.setNyAar(2026); //sætter året til 2026
    dd.setNyDag(25); //sætter  dagen til 25
    dd.setNyMaaned(12); //sætter datoen til 12  
    cout << "Den nye dato er d. " << dd.getDato() << endl; //udskriver datoen, endl er linjeskift
    cout << "Dagen er d. " << dd.getDag()<<" I maanede " << dd.getMaaned() << " i " << dd.getKvartal() << ". kvartal"  << " i aaret " << dd.getAar() << endl;
    cout << d1.forskelDag(d2) << endl;


    bool ok;
    while (ok=true) //er ok sandt kører while loopet
    {
    
        cout <<"Hvad er din fødselsdag? (YYYYMMDD) " << endl;
        int nyDato;
        cin >> nyDato;
        dd.setNyDato(nyDato);
        if (nyDato > 99999999) 
        {
            cout << "Datoen er for lang søde. Datoen skal være på YYYYMMDD form" << endl;
            return ok=true;
        }
        else if (nyDato < 10000000)
        {
            cout << "Datoen er for kort. Skriv den på form YYYYMMDD" << endl;
            return ok=true;
        }
    
        if(dd.validDato())
        {
            cout << "Din fødselsdag er " << dd.getAar() <<"-"<<dd.getMaaned()<<"-"<<dd.getDag()<< endl;
            cout << "Det er d. " << dd.getDag() <<" "<<  dd.hvilkenMaaned() << " i " << dd.getKvartal() << ". kvartal"  << " i aaret " << dd.getAar() << endl;
            cout << "Din alder er " << dd.dinAlder() << " år" << endl;
            cout << "Det betyder dit stjernetegn er " << dd.stjerneTegn() << endl;
            cout << "Det der den " << dd.dagIaar() << " dag i året " << dd.getAar() <<  " og det betyder der var "<< dd.restDagIaar()<<" dage tilbage i dit fødseldagsår" << endl;
       
        }
        else
        {
            cout <<"datoen er ikke korrekt:(" << endl;
            cout<<"Vil du vide hvad der er galt med datoen?(j/n)" << endl;
            char svar1;
            cin >> svar1;   
            switch(svar1)
            {
                case 'j':
                if(dd.aarKorrekt()==false)
                {
                     cout << "Aaret er ikke korrekt" << endl;
    
                     if(dd.getAar()>2025) //hvis aaret er større end 2025
                    {
                        cout << "Aaret er i fremtiden??? Er du dum eller hvad?" << endl;
                     }
                else 
                     {
                         cout<<"Du er fandme ikke 300+ år, er du?" << endl;
                    }

                }
                else 
                 {
                    cout << "Aaret er korrekt" << endl;
                }

                if(dd.maanedKorrekt()==false)
                 {
                 cout << "Måneden er ikke korrekt" << endl;
                    if(dd.getMaaned() > 12)
                     {
                        cout << "Der er ikke mere end 12 måneder i året??" << endl;
        }
        else
        {
            cout << "Måneden er for lille" << endl;
        }
    }
    else
    {
        cout << "Måneden er korrekt" << endl;
    }

    if(dd.dagKorrekt()==false)
    {
        cout << "Dagen er ikke korrekt" << endl;
        if(dd.getMaaned() == 2 && dd.getDag() > 28 && !dd.skudAar())
        {
            cout << "Februar i år" << dd.getAar()<<" har kun 28 dage, da det ikke var et skudår" << endl;
        }
        else if(dd.getMaaned() == 2 && dd.getDag() > 29 && dd.skudAar())
        {
            cout << "Februar har kun 29 dage i" <<dd.getAar()<<", da det var et skudår" << endl;
        }
        else if(dd.getMaaned() == 4 || dd.getMaaned() == 6 || dd.getMaaned() == 9 || dd.getMaaned() == 11 && dd.getDag() > 30)
        {
            cout <<dd.hvilkenMaaned()<< " har kun 30 dage" << endl;
        }
        else
        {
            cout << "Ingen måneder har mere end 31 dage dumbass. Håber fandme ikke du bliver inginør" << endl;
        }
    }
    else
    {
        cout << "Dagen er korrekt" << endl;
    }
        cout<<"Vil du prøve igen?(j/n)" << endl;
        char svar2;
        cin >> svar2;
        switch
         (svar2)
        {
        case 'j':

            cout<<"Godt, så prøver vi igen" << endl;

            break;
        case 'n':
            cout<<"Okay så... taber. Farvel" << endl;
            return ok=false;
            break;
        default: cout<<"ugyldigt svar" << endl;
            return ok=false;
        } 
     break;
     case 'n':
     cout<<"vil du prøve igen?(j/n)" << endl;
        char svar3;
        cin >> svar3;
        switch
         (svar3)
        {
        case 'j':
            cout<<"Godt, så prøver vi igen" << endl;
            return ok=true;

            break;
        case 'n':
            cout<<"Okay så... taber. Farvel" << endl;
            return ok=false;
            break;
        default: cout<<"ugyldigt svar" << endl;
            return ok=false;
        }
        

    break;
        
    default: cout<<"ugyldigt svar" << endl;
        
            }
        }
    }


    
    Dato pf(19810115); //objekt der indeholder pittbill fødselsdag
    Person pitbull("Pitbull ", "ArmandoChristianParez@gmail.com", pf); //paremeterliste, der kalder til konstrukteren i datoklassen.
    cout << pitbull.getFornavn() << "er fodt i år " << pitbull.getFDato().getAar() << endl; //skal altid have parentes efter metoden, selvom der ikke er nogen parametre
     
    Bil b("MRW0RLDW1DE", 2020);
    pitbull.addBil(b); //tilføjer bilen til personen
    cout << "Bilen er fra " << pitbull.getBil().getAargang() << endl;//næstemetode, flere metoder efter hinanden
    if(pitbull.getFDato().getMaaned()==10&&pitbull.getFDato().getAar()==1981)//hvis peter er født i 10. måned, boolean expression, && betyder og
     {
        cout << pitbull.getFornavn() <<" er født i oktober 1981" << endl;
    }
    else
    {
    cout <<pitbull.getFornavn() <<" er ikke født i oktober 1981" << endl;
    }
    return 0;


    for (int i=0; i <10; i++) // forkonstruktion
    {
        cout <<"i er lig med " << i << endl;
    }
    
    int i = 0; // i er kendt i hele
    while (i < 10)
    {
        cout <<"i er lig med " << i << endl;
        i++;
    }

}






