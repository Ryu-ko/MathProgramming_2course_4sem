// -- main (решение задачи  о размещении контейнеров)  
#include <iostream>
#include <iomanip> 
#include "Auxil.h"   
#include "Combi1.h"
#include "Combi2.h"
#include "Combi3.h"
#include "Combi4.h"
#include <ctime>
#define N (sizeof(AA)/2)
#define M 3
#define NN (sizeof(v)/sizeof(int))
#define MM 8

//Разработать генератор подмножеств заданного множества. 
void setGenerator()
{
    system("cls");
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << " - Генератор множества всех подмножеств -";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация всех подмножеств  ";
    combi1::subset s1(sizeof(AA) / 2);     // создание генератора   
    int  n = s1.getfirst();                // первое (пустое) подмножество    
    while (n >= 0)                         // пока есть подмножества 
    {
        std::cout << std::endl << "{ ";
        for (int i = 0; i < n; i++)
            std::cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s1.getnext();                  // cледующее подмножество 
    };
    std::cout << std::endl << "всего: " << s1.count() << std::endl;
}
//Разработать генератор сочетаний 
void combinations()
{
    system("cls");
    char  AA[][2] = { "A", "B", "C", "D", "E" };
    std::cout << " --- Генератор сочетаний ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация сочетаний ";
    combi2::xcombination xc(sizeof(AA) / 2, 3);  
    std::cout << "из " << xc.n << " по " << xc.m;
    int  n = xc.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << xc.nc << ": { ";
        for (int i = 0; i < n; i++)
            std::cout << AA[xc.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = xc.getnext();
    };
    std::cout << std::endl << "всего: " << xc.count() << std::endl;
}
//Разработать генератор перестановок
void permutations()
{
    system("cls");
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << " --- Генератор перестановок ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < sizeof(AA) / 2; i++)
        std::cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация перестановок ";
    combi3::permutation p(sizeof(AA) / 2);
    __int64  n = p.getfirst();
    while (n >= 0)
    {
        std::cout << std::endl << std::setw(4) << p.np << ": { ";
        for (int i = 0; i < p.n; i++)
            std::cout << AA[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
        std::cout << "}";
        n = p.getnext();
    };
    std::cout << std::endl << "всего: " << p.count() << std::endl;
}
//Разработать генератор размещений  
void placements()
{
    system("cls");
    char  AA[][2] = { "A", "B", "C", "D" };
    std::cout << " --- Генератор размещений ---";
    std::cout << std::endl << "Исходное множество: ";
    std::cout << "{ ";
    for (int i = 0; i < N; i++)
        std::cout << AA[i] << ((i < N - 1) ? ", " : " ");
    std::cout << "}";
    std::cout << std::endl << "Генерация размещений  из  " << N << " по " << M;
    combi4::accomodation s(N, M);
    int  n = s.getfirst();
    while (n >= 0) {
        std::cout << std::endl << std::setw(2) << s.na << ": { ";
        for (int i = 0; i < 3; i++)
            std::cout << AA[s.ntx(i)] << ((i < n - 1) ? ", " : " ");
        std::cout << "}";
        n = s.getnext();
    };
    std::cout << std::endl << "всего: " << s.count() << std::endl;
}


int main()
{
    setlocale(LC_ALL, "rus");

    int switcher = 1;
    while (switcher)
    {
        std::cout << "1. Генератор подмножеств: " << std::endl;
        std::cout << "2. Генератор сочетаний: " << std::endl;
        std::cout << "3. Генератор перестановок: " << std::endl;
        std::cout << "4. Генератор размещений: " << std::endl;

        std::cout << "Введите число: "; std::cin >> switcher; std::cout << std::endl;
        switch (switcher)
        {
        case 1: setGenerator(); break;
        case 2: combinations(); break;
        case 3: permutations(); break;
        case 4: placements(); break;
        default:
            break;
        }
    }

    return 0;
}
