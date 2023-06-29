// Combi.h  
#pragma once
#include "Combi3.h"
#include "Combi4.h"
#include "Combi2.h"
using namespace combi2;
using namespace combi3;
namespace combi
{
    struct  accomodation  // ��������� ���������� 
    {
        short  n,      // ���������� ��������� ��������� ���������  
            m,      // ���������� ��������� � ���������� 
            * sset;      // ������ ������� �������� ����������  
        xcombination* cgen;   // ��������� �� ��������� ���������
        permutation* pgen;   // ��������� �� ��������� ������������
        accomodation(short n = 1, short m = 1);  // �����������  
        void reset();     // �������� ���������, ������ ������� 
        short getfirst();     // ������������ ������ ������ ��������   
        short getnext();      // ������������ ��������� ������ ��������  
        short ntx(short i);   // �������� i-� ������� ������� ��������  
        unsigned __int64 na;  // ����� ���������� 0, ..., count()-1 
        unsigned __int64 count() const;  // ����� ���������� ���������� 
    };
}
