
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Npc
{
protected: //модификатор 0 защищенный (дает доступ внутри класса родителя и наследника)
    //но все еще не дает доступ в основном потоке программы

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:    //публичный модификатор доступ (использовать метод можно в любом месте)
    string GetName();
    unsigned int GetHealth();
    float GetDamage();
    unsigned int GetLvl();
    virtual void GetInfo();

    virtual void Create() {};
    virtual bool Save();
    virtual ~Npc() = default;
   
    Npc Load();
    



};
class Player
{
private:
    unique_ptr<Npc> currentCharacter{ nullptr };
public:
    void Create(unique_ptr<Npc> player)
    {
        currentCharacter = move(player);
        currentCharacter->Create();

    }
    void Create() {
        if (currentCharacter != nullptr)
            currentCharacter->Create();
    }
    bool Save() {
        return currentCharacter ? currentCharacter->Save() : false;
    }
    bool Load(unique_ptr<Npc> player) 
    {
        if (player->Load()) {
            currentCharacter = move(player);
            return true;
        }
        return false;
    }
    Npc* GetCharacter() {
        return currentCharacter.get();
    }
    
};


