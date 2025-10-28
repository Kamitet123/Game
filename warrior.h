#pragma once
#ifndef WARRIOR
#define WARRIOR
#include "Npc.h"

#include <iostream>
class Warrior : virtual public Npc //наследование с модификатором public (неизменное)
{
protected:  //модификатор доступа (приватный - защищенный, доступ к полям, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызывается в момент создания экземпляра
    //класса (вручную вызвать в основном потоке программы не можем)

    Warrior() //конструктор по умолчанию, когда нет аргументов
    {
        cout << "конструктор война по умолчанию" << endl;
        name = "воин";
        health = 35;
        damage = 10;
    }
    //кастомный конструктор
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор война" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " взял в руки " << weapons[lvl - 1];
    }
    void GetInfo() override //полиморфизм (перегрузка для метода)
    {
        Npc::GetInfo();
        cout << "Сила - " << strenght << endl;
        cout << "Доступное оружие - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    void Create() override
    {
        cout << "Вы создали война" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    //деструктор - метод, который вызывается автоматически при высвобождении памяти
    //при окончании работы с экземпляром класса (нельзя вызвать вручную)
    ~Warrior() //деструктор всегда без аргументов
    {
        cout << name << " пал смертью храбрых" << endl;
    }
};

#endif
