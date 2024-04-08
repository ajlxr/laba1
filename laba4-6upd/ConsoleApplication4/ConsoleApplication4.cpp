#include <iostream>
using namespace std;


//ОДНОКЛЕТОЧНЫЕ
class Onecell
{
protected:
    int size;
    string name;
public:

    Onecell() = default;

    Onecell(int size_onecell, string new_name) {
        size = size_onecell;
        name = new_name;
    }

    int get_size() {
        return size;
    }
    void set_size(int new_size) {
        size = new_size;
    }
    void size_up(int size_up) {
        size += size_up;
    }
    string set_name(string new_name) {
        name = new_name;
    }
    string get_name() {
        return name;
    }


};
class Infusoria : public Onecell
{

public:

    Infusoria() = default;
    Infusoria(int size_onecell, string new_name) {
        size = size_onecell;
        name = new_name;
    }
    void size_info() {
        cout << "Размер Инфузории = " << size << " клет" << suffix() << endl;
    };

    string suffix() {
        if (size == 1 ) {
            return "ка";
        }
        else if (size > 4) {
            return "ок";
        }
        else {
            return "ки";
        }
    }

};
class Apicomplex : public Onecell
{

public:

    Apicomplex() = default;
    Apicomplex(int size_onecell, string new_name) {
        size_onecell;
        name = new_name;
    }
    void size_info() {
        cout << "Размер Апикомплексы = " << size << " клет" << suffix() << endl;
    };
    string suffix() {
        if (size == 1) {
            return "ка";
        }
        else if (size > 4) {
            return "ок";
        }
        else {
            return "ки";
        }
    }
};



//МНОГОКЛЕТОЧНЫЕ
class Manycells : public Onecell
{

protected:
    string name;
    double massa;
public:
    Manycells() = default;
    Manycells(int CountMassa, string new_name) {
        massa = CountMassa;
        name = new_name;

    }

    int get_massa() {
        return massa;
    }
    void set_massa(int new_massa) {
        massa = new_massa;
    }
    string set_name(string new_name) {
        name = new_name;
    }
    string get_name() {
        return name;
    }
    void massa_up(int massa_up) {
        massa += massa_up;
    }
};

class Hordovie : public Manycells
{

public:

    Hordovie() = default;
    Hordovie(int CountMassa, string new_name) {
        massa = CountMassa;
        name = new_name;
    }
    void massa_info() {
        cout << "Масса Хордового = " << massa << "кг" << endl;
    };
};

class Animals : public Manycells
{

public:

    Animals() = default;
    Animals(int CountMassa, string new_name) {
        massa = CountMassa;
        name = new_name;
    }
    void massa_info() {
        cout << "Масса Животного = " << massa << "кг" << endl;
    };
};

class molusk : public Manycells

{

public:

    molusk() = default;
    molusk(int CountMassa, string new_name) {
        massa = CountMassa;
        name = new_name;
    }
    void massa_info() {
        cout << "Масса Молюска = " << massa << "кг" << endl;
    };

};

class Членистоногие : public Manycells
{

public:

    Членистоногие() = default;
    Членистоногие(int CountMassa, string new_name) {
        name = new_name;
        massa = CountMassa;

    }
    void massa_info() {
        cout << "Масса "<< get_name()+'a' << " " << massa << " кг" << endl;
    };
};


int main()
{
    setlocale(LC_ALL, "Rus");

    Infusoria infusoria(3, "Инфузория");

    infusoria.size_info();
    cout << "прошло 2 дня," << infusoria.get_name() << " продросла:" << endl;
    infusoria.size_up(5);
    infusoria.size_info();

    Членистоногие spider(24, "паук");

    spider.massa_info();
    cout << "прошло 2 дня," << spider.get_name() << " продрос" << endl;
    spider.massa_up(2);
    spider.massa_info();
    return 0;
}

