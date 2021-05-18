# Užduotis "Pažymių skaičiuoklė"
-----------------------------------------------------------------
PROGRAMOS PALEIDIMO INSTRUKCIJA
-----------------------------------------------------------------
ATNAUJINIMŲ ISTORIJA
-----------------------------------------------------------------
[v0.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.1)
-----------------------------------------------------------------
Šioje programoje galima įrašyti studentų vardus, pavardes bei pažymius (egzamino bei namų darbų).
Ji automatiškai suskaičiuoja vidurkį ar medianą, priklausomai nuo vartotojo noro.
Taip pat, jeigu nėra žinomi studento pažymiai, galima pasirinkti, kad programa juos automatiškai sugeneruotų.
-----------------------------------------------------------------
![image](https://user-images.githubusercontent.com/73912309/108605204-64abee80-73bb-11eb-90ff-9720a407bc53.png)
-----------------------------------------------------------------
[v0.1.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.1)
-----------------------------------------------------------------
Sutvarkytas vektorių failas.
-----------------------------------------------------------------
[v0.2](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.2)
-----------------------------------------------------------------
Pridėta galimybė skaityti iš failų bei rezultatus išvesti rezultatų faile.
-----------------------------------------------------------------
![image](https://user-images.githubusercontent.com/73912309/110829317-a6380700-82a0-11eb-854d-c8891dc0ad22.png)
-----------------------------------------------------------------
![image](https://user-images.githubusercontent.com/73912309/110829401-bf40b800-82a0-11eb-88e4-b5ee4a18c51b.png)
-----------------------------------------------------------------
[v0.3](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.3)
-----------------------------------------------------------------
Programa papildyta dvejais "Try/Catch" papildymais tam, kad galima būtų patikrinti ar failas egzistuoja bei ar visi suvesti pažymiai yra teisingi.
-----------------------------------------------------------------
[v0.3.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.3)
-----------------------------------------------------------------
1. Studentai yra surikiuojami pagal vardus rezultatų faile
2. Patobulintas kodas, ištrintos nereikalingos eilutės
3. Programa suoptimizuota
4. Pataisytas rezultatų failuose lygiavimas
-----------------------------------------------------------------
[v0.4](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.4)
-----------------------------------------------------------------
1. Programa gali sugeneruoti papildomus .txt failus priklausomai nuo vartotojo pasirinkimo
2. Studentai yra surūšiuojami į dvi grupes: tie, kurie išlaikė s bei tie, kurie neišlaikė
3. Programa išveda failų sukūrimo bei studentų rūšiavimo laikus
![image](https://user-images.githubusercontent.com/73912309/112353997-f2d60600-8cd4-11eb-8010-ee423ec766d5.png)
-----------------------------------------------------------------
|   Studentų kiekis |   Sugeneravimo trūkmė    |   Nuskaitymo trukmė   |   Studentų surūšiavimo trūkmė   |  Visas sugaištas laikas   |
|--------------|:-------------:      | :-------------------: | :-----------------------------: | :-----------------------: |
|      1000         |       0.013385s          |     0.0010931s        |         0.0115191s              |         0.0259972         |
|      10000        |     0.127771s            |     0.0106337s        |         0.0880599s              |         0.2264646         |
|      100000       |        1.28625s          |     0.0976294s        |         0.882631s               |         2.2665104         |
|      1000000      |       12.7196s           |     0.987103s         |         8.64162s                |         22.348323         |
|      10000000     |         125.735s         |     9.76024s          |         86.515s                 |         222.01024         |
-----------------------------------------------------------------
[v0.4.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.4)
-----------------------------------------------------------------
Patobulinimai bei klaidų taisymas. Taip pat .txt failams saugoti yra sukuriami folderiai.
-----------------------------------------------------------------
[v0.5](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.5)
-----------------------------------------------------------------
Įdėta galimybė pasirinkti norimą konteinerio tipą:
1. Vector
2. Deque
3. List

Programos veikimo laikai priklausomai nuo konteinerio pasirinkimo bei studentų kiekio (sekundėmis):

*Failo nuskaitymas*
|   Konteineris       |         10000                  |         100000              |        1000000          |        10000000          |
|---------------------|:------------------------------:|:---------------------------:|:-----------------------:|:-----------------------:|
|      Vector         |         0.0097385              |         0.137411            |       0.685214          |       9.42775           |
|      Deque          |         0.0097405              |         0.140276            |       0.697253          |       9.53751           |
|      List           |         0.009782               |         0.1389939           |       0.693967          |       9.47624           |

*Rezultatu failo generavimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |        10000000          |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0679942              |         1.00796            |        5.9101            |       71.56             |
|      Deque          |         0.0861038              |         1.04751            |        6.16688           |       74.9914           |
|      List           |         0.0692834              |         0.999789           |        5.877352          |       70.8147           |

*Rūšiavimas ir išvedimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0105147              |         0.104326           |        1.02452           |       10.1956           |
|      Deque          |         0.0109866              |         0.114482           |        1.09572           |       10.6518           |
|      List           |         0.0106121              |         0.107204           |        1.04673           |       10.55             |

*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.089016               |         1.25055            |        7.62065           |       91.1843           |
|      Deque          |         0.10761                |         1.30315            |        7.96067           |       95.1816           |
|      List           |         0.090639               |         1.24674            |        7.6152            |       90.8422           |
-----------------------------------------------------------------
Sistemos parametrai naudojami testavimui:
* CPU: AMD Ryzen 5 3600 6-Core
* RAM: 16 GB DDR4 3200 MHz
* SSD: Samsung 970 Evo Plus M.2 NVMe (r: 3500 MB/s, w: 3300 MB/s) 
-----------------------------------------------------------------
[v0.5.1](https://github.com/edgarasratas/oop-uzduotis-1/tree/v0.5)
-----------------------------------------------------------------
Pataisytos kelios klaidos susijusios su optimizavimu.
-----------------------------------------------------------------
[v1.0](https://github.com/edgarasratas/oop-uzduotis-1/tree/v1.0)
-----------------------------------------------------------------
Pridėta galimybė pasirinkti dvi strategijas studentų rūšiavimui:
1. **Strategija 1.** Konteineris *student* yra suskaidomas į du atskirus konteinerius skirtus laikyti gerus bei blogus studentus
2. **Strategija 2.** Yra sukuriamas vienas naujas konteineris, kuriame laikoma visi blogi studentai, o tie patys blogi studentai yra ištrinami iš bendro studentų konteinerio, todėl tas bendras konteineris laiko tik gerus studentus.

Žemiau yra palyginami laikai tarp šių dviejų strategijų.

**Strategija 1**


*Rūšiavimas ir išvedimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0128002              |         0.123162           |        1.13172           |       11.5776           |
|      Deque          |         0.0133573              |         0.129359           |        1.24612           |       12.7791           |
|      List           |         0.011144               |         0.104622           |        1.05499           |       10.6363           |
-----------------------------------------------------------------

**Strategija 2**

*Rūšiavimas ir išvedimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0124096              |         0.121238           |        1.13111           |       11.7551           |
|      Deque          |         0.0129485              |         0.124776           |        1.20616           |       12.3648           |
|      List           |         0.0113094              |         0.107852           |        1.04427           |       10.5682           |
-----------------------------------------------------------------
[v1.1](https://github.com/edgarasratas/oop-uzduotis-1-2/tree/v1.1)
-----------------------------------------------------------------
Pakeista programos realizacija:
Programoje 'Student' struktūra pakeista į 'Student' klasę.

Žemiau yra palyginamos 1.0 ir 1.1 versijos
-----------------------------------------------------------------
                                                                  v1.0 (struktūros naudojimas)
*Failo nuskaitymas*
|   Konteineris       |         10000                  |         100000              |        1000000          |        10000000          |
|---------------------|:------------------------------:|:---------------------------:|:-----------------------:|:-----------------------:|
|      Vector         |         0.0097385              |         0.137411            |       0.685214          |       9.42775           |
|      Deque          |         0.0097405              |         0.140276            |       0.697253          |       9.53751           |
|      List           |         0.009782               |         0.1389939           |       0.693967          |       9.47624           |

*Rezultatu failo generavimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |        10000000          |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0679942              |         1.00796            |        5.9101            |       71.56             |
|      Deque          |         0.0861038              |         1.04751            |        6.16688           |       74.9914           |
|      List           |         0.0692834              |         0.999789           |        5.877352          |       70.8147           |

*Rūšiavimas ir išvedimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0105147              |         0.104326           |        1.02452           |       10.1956           |
|      Deque          |         0.0109866              |         0.114482           |        1.09572           |       10.6518           |
|      List           |         0.0106121              |         0.107204           |        1.04673           |       10.55             |

*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.089016               |         1.25055            |        7.62065           |       91.1843           |
|      Deque          |         0.10761                |         1.30315            |        7.96067           |       95.1816           |
|      List           |         0.090639               |         1.24674            |        7.6152            |       90.8422           |

                                                                 v1.1 (klasės naudojimas)

*Failo nuskaitymas*
|   Konteineris       |         10000                  |         100000              |        1000000          |        10000000          |
|---------------------|:------------------------------:|:---------------------------:|:-----------------------:|:-----------------------:|
|      Vector         |         0.0671338              |         1.11884             |        4.97842          |        66.1142           |
|      Deque          |         0.0691728              |         1.1224              |        4.82193          |        64.9826           |
|      List           |         0.0660186              |         1.10605             |        4.89119          |        65.2358           |

*Rezultatu failo generavimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |        10000000          |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0236084              |         0.254487           |        2.35852           |        24.6748           |
|      Deque          |         0.0241477              |         0.269628           |        2.56308           |        27.8674           |
|      List           |         0.0215433              |         0.236038           |        2.05107           |        21.5577           |

*Rūšiavimas ir išvedimas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.0123616              |         0.116684           |        1.15988           |       11.6959           |
|      Deque          |         0.0125484              |         0.117744           |        1.15294           |       11.5209           |
|      List           |         0.0104655              |         0.107797           |        1.01617           |       10.0222           |

*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.103755               |         1.4909             |        8.46779           |       102.486           |
|      Deque          |         0.106488               |         1.44758            |        8.53876           |       104.372           |
|      List           |         0.0986256              |         1.45076            |        7.9594            |       96.8165           |
-----------------------------------------------------------------
Taip pat programos sparta patikrinta panaudojant skirtingas optimizavimo vėliavas (O1, O2 ir Ox).
Žemiau yra pateikti laikai:

                                                                  O1
                                                                  
*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.104819               |         1.56082            |        8.71028           |       106.583           |
|      Deque          |         0.109873               |         1.57809            |        9.00834           |       109.224           |
|      List           |         0.102537               |         2.02472            |        8.2901            |       102.237           | 

                                                                  O2
                                                                  
*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.106814               |         1.53962            |        8.32844           |       102.354           |
|      Deque          |         0.104889               |         1.53348            |        8.51819           |       104.493           |
|      List           |         0.0975132              |         1.45929            |        7.96549           |       96.8712           |

                                                                  Ox
                                                                  
*Visas laikas*
|   Konteineris       |         10000                  |         100000             |        1000000           |       10000000           |
|---------------------|:------------------------------:|:--------------------------:|:------------------------:|:-----------------------:|
|      Vector         |         0.102592               |         1.54038            |        8.34943           |       102.358           |
|      Deque          |         0.103584               |         1.52892            |        8.68615           |       104.61            |
|      List           |         0.0962083              |         1.49566            |        7.86732           |       141.352           |
-----------------------------------------------------------------
[v1.2](https://github.com/edgarasratas/oop-uzduotis-1-2/tree/v1.2)
-----------------------------------------------------------------
Programoje realizuota "Rule of Three" 'Student' klasei:
* Destructor
* Copy constructor
* Copy assignment operator
-----------------------------------------------------------------
[v1.5](https://github.com/edgarasratas/oop-uzduotis-1-2/tree/v1.5)
-----------------------------------------------------------------
Programoje sudaryta papildoma abstrakti *Human* bazinė klasė, iš kurios *Student* klasė paveldi.
-----------------------------------------------------------------
[v2.0](https://github.com/edgarasratas/oop-uzduotis-1-2/tree/v2.0)
-----------------------------------------------------------------
* Programoje panaudojami keli Unit testai ištirti klases bei jų narius. Tam atlikti buvo naudojamas C++ framework'as *GoogleTest*
* Sukurta dokumentacija pasinaudojant *Doxygen* projekto pagrindu
* Sukurtas *Setup.msi* diegimo failas programos instaliavimui
