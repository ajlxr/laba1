#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct TeacherSurvey {
    string Familia;
    string Predmet;
    int Dostupnost;
    int Practica;
    int Objectivnost;
};

vector<TeacherSurvey> database; 
const string filename = "База данных.txt";

void createDatabase();
void displayDatabase();
void addRecord();
void deleteRecord();
void sortDatabase();

void createDatabase() {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Файл не найден. Создание базы данных." << endl;
        return;
    }

    TeacherSurvey survey;
    while (inputFile >> survey.Familia >> survey.Predmet >> survey.Dostupnost
        >> survey.Practica >> survey.Objectivnost) {
        database.push_back(survey);
    }

    inputFile.close();

    cout << "База данных успешно создана." << endl;
}

void displayDatabase() {
    if (database.empty()) {
        cout << "База данных пуста." << endl;
        return;
    }

    cout << "Содержимое базы данных:" << endl;
    for (size_t i = 0; i < database.size(); ++i) {
        const TeacherSurvey& survey = database[i];
        cout << "Запись " << i + 1 << ": " << survey.Familia << ", " << survey.Predmet
            << ", Лекции: " << survey.Dostupnost
            << ", Практика: " << survey.Practica
            << ", Оценка: " << survey.Objectivnost << endl;
    }
}

void addRecord() {
    TeacherSurvey newRecord;
    cout << "Введите фамилию преподавателя: ";
    cin >> newRecord.Familia;
    cout << "Введите предмет: ";
    cin >> newRecord.Predmet;
    cout << "Введите доступность изложения материала на лекции (целое число): ";
    cin >> newRecord.Dostupnost;
    cout << "Введите доступность изложения материала на практических занятиях (целое число): ";
    cin >> newRecord.Practica;
    cout << "Введите объективность оценки знаний (целое число): ";
    cin >> newRecord.Objectivnost;

    database.push_back(newRecord);

    ofstream outputFile(filename, ios::app);
    outputFile << newRecord.Familia << ' ' << newRecord.Predmet << ' '
        << newRecord.Dostupnost << ' ' << newRecord.Practica
        << ' ' << newRecord.Objectivnost << endl;
    outputFile.close();

    cout << "Запись успешно добавлена в базу данных." << endl;
}

void deleteRecord() {
    if (database.empty()) {
        cout << "База данных пуста. Невозможно удалить запись." << endl;
        return;
    }

    int recordNumber;
    cout << "Введите номер записи для удаления: ";
    cin >> recordNumber;
    if (recordNumber < 1 || recordNumber > static_cast<int>(database.size())) {
        cout << "Некорректный номер записи." << endl;
        return;
    }

    database.erase(database.begin() + recordNumber - 1);

    ofstream outputFile(filename);
    for (const auto& survey : database) {
        outputFile << survey.Familia << ' ' << survey.Predmet << ' '
            << survey.Dostupnost << ' ' << survey.Practica
            << ' ' << survey.Objectivnost << endl;
    }
    outputFile.close();

    cout << "Запись успешно удалена из базы данных." << endl;
}

void sortDatabase() {
    if (database.empty()) {
        cout << "База данных пуста. Нечего сортировать." << endl;
        return;
    }


    sort(database.begin(), database.end(),
        [](const TeacherSurvey& a, const TeacherSurvey& b) {
            return make_pair(a.Objectivnost, a.Familia) <
                make_pair(b.Objectivnost, b.Familia);
        });

    cout << "База данных успешно отсортирована." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
    
        cout << "Меню:" << endl
        << "1 - Создать базу данных" << endl
        << "2 - Вывести содержимое базы данных" << endl
        << "3 - Добавить запись в базу данных" << endl
        << "4 - Удалить запись из базы данных" << endl
        << "5 - Сортировать базу данных" << endl
        << "6 - Выход" << endl
        << "Выберите пункт меню (1-6): ";

        cin >> choice;

        switch (choice) {
        case 1:
            createDatabase();
            break;
        case 2:
            displayDatabase();
            break;
        case 3:
            addRecord();
            break;
        case 4:
            deleteRecord();
            break;
        case 5:
            sortDatabase();
            break;
        case 6:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный выбор. Пожалуйста, выберите от 1 до 6." << endl;
        }
    } while (choice != 6);

    return 0;
}