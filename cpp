#include "BaseClass.h"

string Npc::GetName()
{
    return name;
}
unsigned int Npc::GetHealth()
{
    return health;
}
float Npc::GetDamage()
{
    return damage;
}
unsigned int Npc::GetLvl()
{
    return lvl;
}
void Npc::GetInfo() //метод класса
{
    cout << "Имя - " << name << endl;
    cout << "Здоровье - " << health << endl;
    cout << "Урон - " << damage << endl;
}
bool Npc::Save()
{

    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        saveSystem.write(reinterpret_cast<const char*>(&name), sizeof(name));
        saveSystem.write(reinterpret_cast<const char*>(&health), sizeof(health));
        saveSystem.write(reinterpret_cast<const char*>(&damage), sizeof(damage));
        saveSystem.write(reinterpret_cast<const char*>(&lvl), sizeof(lvl));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "сохранение не удалось" << endl;
        return false;
    }
    saveSystem.close();
};
bool Npc::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    Npc npc; //временное хранилище для считывания данных из файла
    if (loadSystem.is_open())
    {
        size_t nameLenght;
        loadSystem.read(reinterpret_cast<char*>(&nameLenght), sizeof(nameLenght));
        char* buffer = new char[nameLenght + 1];
        loadSystem.read(buffer, nameLenght);
        buffer[nameLenght] = '\0';
        name = string(buffer);
        delete[] buffer;

        loadSystem.read(reinterpret_cast<char*>(&name), sizeof(name));
        loadSystem.read(reinterpret_cast<char*>(&health), sizeof(health));
        loadSystem.read(reinterpret_cast<char*>(&damage), sizeof(damage));
        loadSystem.read(reinterpret_cast<char*>(&lvl), sizeof(lvl));
        return loadSystem.good();
    }
    else
    {
        cout << "связь с базой нарушена\nПамять утерена" << endl;
        return false;
    }
    loadSystem.close();
    


};


void Player::Create(Npc* player)
{
    player->Create();
}
void Player::Save(Npc* player)
{
    player->Save();
}
void Player::Load(Npc* player)
{
    player->Load();
}
