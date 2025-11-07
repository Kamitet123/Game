#include <iostream>
#include "windows.h"
#include "BaseClass.h"
#include "StartClasses.h"


//отличие sctruct от class
//
//struct Treasure//всё по умолчанию внутри public
//{
//    string name{ "добыча" };
//    string valueQuality[5]{ "мусор, обычное, редкое, мифическое, легендарное" };
//    string quality = valueQuality[0];
//    unsigned int price{ 0 };

enum class  ValueQuality
{
    trash,common , rare, mythic, legendary // эквивалент перечисления чисел

    };


    struct Treasure { // всё по умолчанию внутри private
        string name{ "добыча" };
        ValueQuality quality = ValueQuality::mythic;
        //string valueQuality[5]{ "мусор,обычное ,редкое,мифическое ,легендарное" };
       // string quality = valueQuality[0];

        unsigned int price{ 0 };
        Treasure(ValueQuality quality)
        {
            switch (quality)
            {
            case ValueQuality::trash:
                cout << "качество плохое\n ";
                break;
            case ValueQuality::common:
                cout << "качество средненькое\n ";
                break;
            case ValueQuality::rare:
                cout << "качество хорошее\n ";
                break;
            case ValueQuality::mythic:
                cout << "качество крутое\n ";
                break;
            case ValueQuality::legendary:
                cout << "качество идеальное\n ";
                break;
            default:
                break;
            }
        }
    };
    struct Cloth : Treasure // нвследование по умолчанию private
    {
        Cloth(ValueQuality quality): Treasure(quality){}
        string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
        string site{ NULL };
        unsigned short armor{ 1 };
    };

using namespace std;

//модификаторы доступа:
// private - приватный, запрещает доступ к свойствам и классам
//           за пределами самого класса
// protected - защищенный, можно передавать свойства и методы
//        в классы наследники, но все еще нельзя использовать
//        в основном потоке программы
// public - публичный, общедоступный, можно использовать везде


//базовый класс - абстрактный (класс у которого все методы виртуальные)



int main()
{
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Cloth cloth(ValueQuality::mythic);
    cloth.armor = 10;
    cloth.site = cloth.valueSite[2];
    cloth.name = "Шлем властителя подземелий";
    cloth.price = 50;
    cout << cloth.name << '\n' << cloth.site << '\n' << cloth.armor << '\n' << cloth.price << '\n';

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    cout << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Paladin* paladin = new Paladin();
    Player* player = new Player();

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

        // тут уже будет вызвана ваша красивая функция
        cin >> choise;
        while (choise > 3 || choise < 1)
        {
            cout << "Такого еще не было в наших краях\nНе мог бы ты повторить\n";
            cin >> choise;
        }


        switch (choise)
        {
        case 1: {
            player->Create(warrior);
            delete wizard;
            wizard = nullptr;
            delete paladin;
            paladin = nullptr;
            break; }
        case 2: {
            player->Create(wizard);
            delete warrior;
            warrior = nullptr;
            delete paladin;
            paladin = nullptr;
            cout << " " << endl;
            break; }
        case 3: {
            player->Create(paladin);
            delete warrior;
            warrior = nullptr;
            delete wizard;
            wizard = nullptr;
            break; }
        }

    }

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
}
