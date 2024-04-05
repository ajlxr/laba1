#include <iostream>
using namespace std;


//ОДНОКЛЕТОЧНЫЕ
class Onecell 
{
public:
    int size;

    Onecell() = default;
    
    Onecell(int size_onecell) {
        size = size_onecell;
    }

     int get_size() {
        return size;
    }
      void set_size(int new_size) { 
        size = new_size; 
    }
      void size_up (int size_up) {
          size += size_up;
      }

      
};
class Infusoria : public Onecell
{
    
public:

    Infusoria() = default;
    Infusoria(int size_onecell) {
        size = size_onecell;
    }   
    void size_info() {
        cout << "Размер Инфузории = " << size << "клеток" << endl;
    };
        
};
class Apicomplex : public Onecell
{

public:

    Apicomplex() = default;
    Apicomplex (int size_onecell) {
        size_onecell;
    }
    void size_info() {
        cout << "Размер Апикомплексы = " << size << "клеток" << endl;
    };
};



//МНОГОКЛЕТОЧНЫЕ
class Manycells : public Onecell
{

public:
    string name;
    double massa;

    Manycells() = default;
    Manycells(int CountMassa) {
        massa = CountMassa;
    }
    int get_massa() {
        return massa;
    }

    string get_name() {
        return name;
    }
   
    void set_massa(int new_massa) {
        massa = new_massa;
    }

    void massa_up(int massa_up) {
        massa += massa_up;
    }
};

class Hordovie : public Manycells
{

public:

    Hordovie() = default;
    Hordovie(int CountMassa) {
        massa = CountMassa;
    }
    void massa_info() {
        cout << "Масса Хордового = " << massa << "кг" << endl;
    };
};

class Animals : public Manycells
{

public:

    Animals() = default;
    Animals(int CountMassa) {
        massa = CountMassa;
    }
    void massa_info() {
        cout << "Масса Животного = " << massa << "кг" << endl;
    };
};

class molusk : public Manycells

{

public:

    molusk() = default;
    molusk(int CountMassa) {
        massa = CountMassa;
    }
    void massa_info() {
        cout << "Масса Молюска = " << massa << "кг" << endl;
    };

};

class Членистоногие : public Manycells
{

public:

    Членистоногие() = default;
    Членистоногие(int CountMassa, string name_chlenistonogi) {
        massa = CountMassa;
    }
    void massa_info() {
        cout << "Масса Членистоногого = " << massa << "кг" << endl;
    };
};


int main()
{
    setlocale(LC_ALL, "Rus");


    Infusoria infusoria(3);
    infusoria.size_info();
    cout << "прошло 2 дня," << " " << "продросла:" << endl;
    infusoria.size_up(5);
    infusoria.size_info();

   
    Членистоногие spider(24, "паук");
    spider.massa_info();
    cout << "прошло 2 дня," << spider.get_name() << "продрос" << endl;\
    spider.massa_up(2);
    spider.massa_info();
    
}
/* 
Общие требования к выполнению лабораторной работы:
⦁	На основе перечисленных классов создать иерархию классов (1 базовый (абстрактный) класс, производные классы (2), финальные классы (5-6));
⦁	Все классы должны содержать конструкторы по умолчанию и конструкторы с параметрами;
⦁	Придумать и реализовать не менее двух-трёх методов для каждого класса (исключая методы для получения / установки), добавить все необходимые для функциональности поля;
⦁	Для всех полей классов должен быть установлен уровень доступа не ниже protected, для получения / установки значений полей использовать соответствующие методы (get, set);
⦁	В программе необходимо соблюсти принцип разделения интерфейса и реализации класса (иными словами, не забывайте выделять заголовочные файлы);
⦁	Предусмотреть чистый виртуальный метод базового класса, переопределенный в производных (например, метод вычисления площади, метод вычисления расстояния и т.д.);
⦁	В базовом классе предусмотреть наследуемые поля;
⦁	Предусмотреть статические поля и методы (например, единицы измерения или количество создаваемых объектов);
⦁	В каждом варианте необходимо написать программу, иллюстрирующую применение всех методов ваших классов.
Вариант 9
Одноклеточные, инфузории, многоклеточные, хордовые, апикомплексы, животные, моллюски, членистоногие.
*/