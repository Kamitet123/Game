#include "StartClasses.h"
bool Warrior::Save() 
{


    if (Npc::Save())
    {
        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            if (!Npc::Save()) {
                cout << "Сохранение не удалось\nПопробуйте позже\n ";
                return false;
            }

            saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
            saveSystem.close();
            return true;

           
        }
        else
        {
            cout << "сохранение не удалось" << endl;
            return false;
        }
    }
};
Warrior Warrior::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    Warrior warrior; //временное хранилище для считывания данных из файла
    warrior = Npc::Load();
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Связь с небесами нарушена\nПамять о ваших прошлых путешествиях повреждена\n";
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
        
    }
    else
    {
        cout << "Связь с небесами нарушена\nПамять о ваших прошлых путешествиях повреждена\n";
        return false;
    }
    loadSystem.close();
    return true;


};


Warrior::Warrior() //конструктор по умолчанию, когда нет аргументов
{
    name = "воин";
    health = 35;
    damage = 10;
}
//кастомный конструктор
Warrior::Warrior(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор война" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Warrior::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Warrior::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Warrior::Create() 
{
    cout << "Вы создали война" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Warrior::operator == (const Warrior& warrior) const
{
    return ((warrior.damage == this->damage) && (warrior.health == this->health)
        && (warrior.strenght == this->strenght));
}
void Warrior::operator = (Npc npc)
{
    if (this != &npc) {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        return *this;

    }
    
}

//деструктор - метод, который вызывается автоматически при высвобождении памяти
//при окончании работы с экземпляром класса (нельзя вызвать вручную)
Warrior::~Warrior() //деструктор всегда без аргументов
{
    cout << name << " пал смертью храбрых" << endl;
}

