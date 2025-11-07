#pragma once
#include "BaseClass.h"

//наследование - использование доступных свойств
// и методов класса родителям (parent), классом наследником(child)
class Warrior : public virtual Npc //наследование с модификатором доступа public
{
protected:  //модификатор 0 (приватный - защищенный, доступ к полям, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызывается в момент создания экземпляра
    //класса (вручную вызвать в основном потоке программы не можем)
    bool Save() override;
    Warrior Load();
    Warrior();//конструктор по умолчанию, когда нет аргументов
              //кастомный конструктор
    Warrior(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo() override;  //полиморфизм (перегрузка для метода)
    void Create() override;
    
    //перегрузка операторов
    //перегрузка оператора сравнения (==)

    bool operator == (const Warrior& warrior) const;
        void operator = (Npc npc);
 
        ~Warrior(); //деструктор всегда без аргументов
    
};


//virtual - создает виртуализацию методов, классов
//при этом сам класс повторно не создается
class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магисческая стрела", "огненный шар", "метеоритный дождь" };
public:
    Wizard()
    {
        name = "волшебник";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор волшебника" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override  //полиморфизм (перегрузка для метода)
    {
        Npc::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void CastSpell()
    {
        cout << name << " применяет " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "Вы создали волшебника" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
    }
    bool operator == (const Wizard& wizard) const
    {
        return ((wizard.damage == this->damage) && (wizard.health == this->health)
            && (wizard.intellect == this->intellect));
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&spell[i]), sizeof(spell[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "сохранение не удалось" << endl;
                return false;
            }
        }
    }
    ~Wizard() //деструктор всегда без аргументов
    {
        cout << name << " испустил дух" << endl;
    }

};

//множественное наследование
class Paladin : public Warrior, public Wizard
    //следующий родительственный класс добавляется через запятую
{
public:
    Paladin()
    {
        name = "паладин";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void Create() override
    {
        cout << "Вы создали паладина" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }
    bool operator == (const Paladin& paladin) const
    {
        return ((paladin.damage == this->damage) && (paladin.health == this->health)
            && (paladin.intellect == this->intellect)) && (paladin.strenght == this->strenght);
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&spell[i]), sizeof(spell[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "сохранение не удалось" << endl;
                return false;
            }
        }
    }
};





