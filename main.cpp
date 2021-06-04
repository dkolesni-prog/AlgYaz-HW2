//
// Created by Daniil Kolesnik on 27/05/2021.
//all rights and lefts reserved

#include <iostream>
#include "vectorKolesnik.h"




int main()
{
    vectorKolesnik <int> f;
    // Vect <int> ::iterator = f.Begin();
    vectorKolesnik <int> f1;
    vectorKolesnik <int> f2;
    f.push_back(0);
    f.push_back(1);
    f.push_back(2);
    f.push_back(3);
    f.push_back(4);

    std::cout << "вызов по [] " << f[2] <<  "\n";
    std::cout << "Указатель на 1 эл-нт " << *f.data()<<"\n";
    std::cout << "Ссылка на 1 эл-нт " << f.front() <<"\n";
    std::cout << "Ссылка на последний эл-нт " << f.back() <<"\n";
    std::cout << "Размер " << f.size() <<"\n";

    f.resize(30);
    std::cout << "новое заполнение " << f.size() << " макс размер " << f.capacity() << "\n";

    f.reserve(200);
    std::cout << "Размер после резервирования " << f.size() << " макс размер "<< f.capacity()<< "\n";

    f.clear();
    std::cout << "Размер после очистки " << f.size() << " макс размер " << f.capacity() << "\n";

    f.push_back(0);
    f.push_back(1);
    f.push_back(2);
    f.pop_back();
    std::cout << "Размер после удаления посл. элемента " << f.size() << " макс размер " << f.capacity() << "\n";

    f1 =* new  vectorKolesnik<int>(f);//конструктор копир
    std::cout << "2 элемент нового скопир вектора "<<f1[2]<<"\n";
    f1[2]=10;
    f.swap(f1);
    std::cout << "2 элемент старого вектора после смены " << f[2]<<"\n";

    f.push_back(20);
    std::cout << "все эл вектора " << f[2] << "\n";
    for (int i = 0; i < f.size(); i++)
        std::cout << f[i]<<std::endl;
    f[1] = 30;
    std::cout << "все эл вектора " << f[2] << "\n";
    for (int i = 0; i < f.size(); i++)
        std::cout << f[i] << std::endl;
    auto iterbe = f.begin();
    auto iteren = f.end();
    auto itercbeg = f.cbegin();
    auto itercend = f.cend();
    auto iterrbeg = f.rbegin();
    auto iterrend = f.rend();
    auto iterrcend = f.crend();
    auto iterrcbegin = f.crbegin();
    std::cout << "пуст ли?"<<f.empty()<<"после чистки ";
    f.clear();
    std::cout << f.empty();

    f.push_back(21);
    f.push_back(22);
    f.push_back(23);
    f.push_back(24);
    f.push_back(25);
    std::cout<<std::endl<<"ссылка на 4 элемент"<< f.at(4)<<std::endl;
    f.erase(f.begin(), f.end()-2);
    for (int i = 0; i < f.size(); i++)
        std::cout << f[i] << std::endl;
    std::cout  << "\n";
    system("Pause");
}

