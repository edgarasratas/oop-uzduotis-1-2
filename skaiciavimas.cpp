#include "Student.h"
#include "skaiciavimas.h"

void skaiciavimas() {
    float sum{ 0 };
    int n;
    string input;
    int randomNumber, randomExamGrade;
    int temp;
    int examGrade;
    int gradeNr;
    string name;
    string surname;
    vector<Student> student;
    int index = 0;

    do {
        index++;
        if (index != 1)
            cout << "Klaidingas ivedimas. Studentu skaicius turi buti bent 1. Bandykite dar karta\n";

        cout << "Iveskite reikiama studentu skaiciu: \n";
        cin >> n;
    } while (n < 1);

    cout << '\n';

    for (int i = 0; i < n; i++) {
        student.push_back(Student());

        cout << i + 1 << " studentas\n";
        cout << "Iveskite studento varda: ";
        cin >> name;

        student[i].setName(name);

        cout << "Iveskite studento pavarde: ";
        cin >> surname;

        student[i].setSurname(surname);

        cout << "Iveskite studento nd pazymiu kieki: ";
        cin >> gradeNr;

        student[i].setNumOfGrades(gradeNr);

        cout << "Ar zinomi studento pazymiai? (y/n)\n";
        cin >> input;

        do {
            if (input == "Y" || input == "y") {

                cout << "Iveskite egzamino pazymi: ";
                cin >> examGrade;

                student[i].setExamGrade(examGrade);

                for (int j = 0; j < student[i].getNumOfGrades(); j++) {

                    cout << "Iveskite " << j + 1 << " nd pazymi: ";
                    cin >> temp;

                    student[i].addGrade(temp);

                    sum += student[i].getGrade(j);
                }

                cout << '\n';

                cout << '\n';
                break;
            }
            else if (input == "N" || input == "n") {
                srand((unsigned int)time(NULL));

                randomExamGrade = rand() % 10 + 1;

                student[i].setExamGrade(randomExamGrade);


                for (int j = 0; j < student[i].getNumOfGrades(); j++) {
                    randomNumber = rand() % 10 + 1;

                    student[i].addGrade(randomNumber);

                    sum += student[i].getGrade(j);
                }

                cout << "Egzamino pazymys: " << student[i].getExamGrade() << "\nNd pazymiai: ";

                for (int j = 0; j < student[i].getNumOfGrades(); j++) {
                    cout << student[i].getGrade(j) << " ";
                }

                cout << '\n';
                break;
            }
            else {
                cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
                cout << "Ar zinomi studento pazymiai? (y/n)\n";
                cin >> input;
            }
        } while (input != "Y" || input != "y" || input != "N" || input != "n");

        student[i].setExamFinal((float)0.6 * student[i].getExamGrade());

        for (int j = 1; j < student[i].getNumOfGrades(); j++) {
            student[i].setFinal((float)0.4 * (sum / (student[i].getNumOfGrades())) + student[i].getExamFinal());
        }

        sum = 0;

        //sort(student[i].getGrade().begin(), student[i].getGrade().end());

        for (int j = 0; j < student[i].getNumOfGrades(); j++) {
        }
        cout << '\n';
    }
    cout << "Ar norite, kad atspausdintu galutinio pazymio vidurki (y) ar mediana? (n)\n";
    cin >> input;
    cout << '\n';

    do {
        if (input == "Y" || input == "y") {
            printf("Vardas\t\tPavarde\t\tGalutinis (vid.)\n");
            printf("-----------------------------------------------------\n");

            for (int i = 0; i < n; i++) {
                cout << std::setw(15) << std::left << student[i].getName()
                    << std::setw(15) << std::left << student[i].getSurname()
                    << std::setw(15) << std::left << student[i].getFinal() << '\n';
            }
            break;
        }
        else if (input == "N" || input == "n") {
            printf("Vardas\t\tPavarde\t\tGalutinis (med.)\n");
            printf("-----------------------------------------------------\n");

            for (int i = 0; i < n; i++) {
                student[i].sortGrades();

                if (student[i].getNumOfGrades() % 2 == 0) {
                    student[i].setMedian((student[i].getGrade(student[i].getNumOfGrades() / 2) + student[i].getGrade((student[i].getNumOfGrades() / 2) - 1)) / (float)2.0);
                }
                else {
                    student[i].setMedian((float)student[i].getGrade(student[i].getNumOfGrades() / 2));
                }
                student[i].setMedFinal(((float)0.4 * student[i].getMedian()) + ((float)0.6 * student[i].getExamGrade()));
                cout << std::setw(15) << std::left << student[i].getName()
                    << std::setw(15) << std::left << student[i].getSurname()
                    << std::setw(15) << std::left << student[i].getMedFinal();
            }
            break;
        }
        else {
            cout << "Prasome iveskite y arba n. Bandykite is naujo\n";
            cout << "Ar norite, kad atspausdintu galutinio pazymio vidurki (y) ar mediana? (n)\n";
            cin >> input;
        }
    } while (input != "Y" || input != "y" || input != "N" || input != "n");
}