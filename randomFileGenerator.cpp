#include "Student.h"
#include "createDir.h"
#include "randomFileGenerator.h"

const int gradeNr = 15;

void randomFileGenerator(string dir, string fileWrite, int studentSize, vector<Student>& student)
{
    auto start = std::chrono::high_resolution_clock::now();

    cout << "Generuojama...\n";

    createDir("Generated text files");

    ofstream fout(dir + fileWrite);

    fout << std::setw(15) << std::left << "Vardas"
        << std::setw(15) << std::left << "Pavarde";

    for (int i = 0; i < gradeNr + 1; i++)
    {
        string ND = "ND" + std::to_string(i + 1);
        if (i < gradeNr)
        {
            fout << std::setw(10) << std::left << ND << std::setw(10) << std::left;
        }
        else
        {
            fout << std::setw(10) << std::left << "Egz." << '\n';
        }
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < studentSize; i++)
    {
        string name = "Vardas" + std::to_string(i + 1);
        string surname = "Pavarde" + std::to_string(i + 1);

        fout << std::setw(15) << std::left << name
            << std::setw(15) << std::left << surname;

        for (int j = 0; j < gradeNr; j++)
        {
            fout << std::setw(10) << std::left << rand() % 10 + 1;
        }

        if (i == studentSize - 1)
        {
            fout << std::setw(10) << std::left << rand() % 10 + 1;
        }
        else
        {
            fout << std::setw(10) << std::left << rand() % 10 + 1 << '\n';
        }
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Faila sugeneravo per " << diff.count() << "s\n"
        << "Sugeneruotas failas '" << fileWrite << "' 'Generated text files' folderyje\n";
}