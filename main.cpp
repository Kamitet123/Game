#include <iostream>
#include "windows.h"
#include "gameClasses.h"
#include "mainClass.h"
#include "Evil.h"

using namespace std;
//
//class Product
//{
//public: Product() = default ;
//};
//
//class Bread :public Product
//{
//public: Bread() = default;
//};
//
//class Chips : public Product
//{
//public: Chips() = default;
//};
//class Creator
//{
//public:
//    Creator() = default;
//    virtual Product FactoryMethod() { return Product(); }
//};
//class BreadCreator : Creator
//{
//public:
//    BreadCreator() = default;
//    Product FactoryMethod() override { return Bread(); }
//};
//class ChipsCreator :public Creator
//{
//public:
//    ChipsCreator() = default;
//    Product FactoryMethod() override { return Chips(); }
//};













enum class ValueQuality
{
    мусор, обычное, редкое, мифическое, легендарное
};
//модификаторы доступа:
// private - приватный, запрещает доступ к свойствам и классам
//           за пределами самого класса
// protected - защищенный, можно передавать свойства и методы
//        в классы наследники, но все еще нельзя использовать
//        в основном потоке программы
// public - публичный, общедоступный, можно использовать везде


//базовый класс - абстрактный (класс у которого все методы виртуальные)
struct Treasure // приват но по умл
{
    string name{ "добыча" };
    ValueQuality quiality = ValueQuality::мифическое;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::мусор:
            cout << "качесвто плохое\n";
            break;
        }
        switch (quality)
        {
        case ValueQuality::обычное:
            cout << "качество среднее\n";
            break;
        }
        switch (quality)
        {
        case ValueQuality::редкое:
            cout << "качество хорошее\n";
            break;
        }
        switch (quality)
        {
        case ValueQuality::мифическое:
            cout << "качество отличное\n";
            break;
        }
        switch (quality)
        {
        case ValueQuality::легендарное:
            cout << "качество замечательное\n";
            break;
        default:
            break;
        }
    }
};
struct Cloth : Treasure //
{
    Cloth(ValueQuality quality) : Treasure(quality) {};
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };
};

enum class character {
    UNKNOWN = 0,
    WARRIOR,
    WIZARD,
    PALADIN
};

unique_ptr<Npc> CreateCharacter(character type)
{
    switch (type)
    {
    case character::UNKNOWN:
        return make_unique < Npc>();
        break;
    case character::WARRIOR:
        return make_unique < Warrior>();
        break;
    case character::WIZARD:
        return make_unique < Wizard>();
        break;
    case character::PALADIN:
        return make_unique < Paladin>();
        break;
    default:
        invalid_argument("Неизвестный тип персонажа");
        break;
    }
}
/*
class Treasure // приват но по умл
{
public:
    string name{ "добыча" };
    string valueQuality[5]{ "мусор", "обычное", "редкое", "мифическое", "легендарное" };
    string quality = valueQuality[0];
    unsigned int price{ 0 };
};
class Cloth : Treasure //
{
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };
};
*/
int main()
{
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Player* player = new Player();
    cout << "Привет, путник\nПрисядь у костра и расскажи о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";
    if (TestChoise(2, "Наверное ты ошибся, повтори снова"))
    {
        cout << 
    }


    /*Treasure treasure;
    treasure.name = "древняя тарелка";
    treasure.price = 30;
    treasure.quality = treasure.valueQuality[3];
    cout << treasure.name << '\n' << treasure.price << '\n' << treasure.quality << '\n';
*/
    Cloth cloth(ValueQuality::мифическое);
    cloth.armor = 10;
    cloth.site = cloth.valueSite[2];
    cloth.name = "Шлем властителя подземелий";
    cloth.price = 50;
    cout << cloth.name << '\n' << cloth.valueSite << '\n' << cloth.armor << '\n' << cloth.price << '\n';

    //Warrior* warrior = new Warrior();
    //Warrior* warrior2 = new Warrior();
    //cout << (*warrior == *warrior2) << endl;

    //Wizard* wizard = new Wizard();
    //Paladin* paladin = new Paladin();
    //Player* player = new Player();

    cout << "Привет, путник\nПрисядь у костра и расскажи о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";
    unsigned short choise = 1;
    cin >> choise;
    while (choise > 2 || choise < 1)
    {
        cout << "Наверное ты ошибся, повтори снова\n";
        cin >> choise;
    }
    /*
    unsigned short maxChoise = 3;
    unsigned short TestChoise(unsigned short maxChoise, string text);
    {
        unsigned short choise = 1;
        cin >> choise;
        while (choise > maxChoise || choise < 1)
        {
            cout << "Наверное ты ошибся, повтори снова\n";
            cin >> choise;
        }
        return choise;


    };

    */

    if (choise == 1)
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        unique_ptr<Npc> character;
        switch (TestChoise(3, ""))
        // тут уже будет вызвана ваша красивая функция
       

       /* switch (choise)
        {
        case 1: {
            player->Create(warrior);
            delete wizard;
            wizard = nullptr;
            delete paladin;
            paladin = nullptr;
            break;
        }
        case 2: {
            player->Create(wizard);
            delete warrior;
            warrior = nullptr;
            delete paladin;
            paladin = nullptr;
            cout << " " << endl;
            break;
        }
        case 3: {
            player->Create(paladin);
            delete warrior;
            warrior = nullptr;
            delete wizard;
            wizard = nullptr;
            break;
        }
        }*/

   // }

    else
    {
        player->Load(warrior);
    }

    cout << "сделаем остановку тут?\n\t1 - сохранить игру\n\t2 - продолжить\n";
    cin >> choise;
    if (choise == 1)
    {
        if (warrior != nullptr) player->Save(warrior);
        if (wizard != nullptr) player->Save(wizard);
        if (paladin != nullptr) player->Save(paladin);
    }



    return 0;
