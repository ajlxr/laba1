#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
  
    int ChisloSlov;

    cout << "Введите число слов: ";
    cin >> ChisloSlov;

    string ImyaFaila;

    ifstream file("C:/Users/kiril/Desktop/laba7.txt");

    string sentence;

    while (getline(file, sentence)) {
 
        vector<string> words;

        istringstream iss(sentence);
        do {
            string word;
            iss >> word;

            if (!word.empty()) {
                words.push_back(word);
            }
        } while (iss);

        
        if (words.size() == ChisloSlov) {
            cout << sentence << endl;
        }
    }

    file.close();

    return 0;
}