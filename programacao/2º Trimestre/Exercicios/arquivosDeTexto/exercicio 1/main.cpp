#include <iostream>
#include <fstream>
#include <string>

int main() {
    int espaco = 0, linhas = 0, vogais = 0, artigos = 0;
    char letter, line[200];
    std::string word;
    std::fstream file;

    file.open("text.txt", std::ios::in);
    if (!file) {
        std::cerr << "deu merda" << std::endl;
        return -1;
    }

    while (file >> letter) {
        switch (letter) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vogais++;
                break;
        }
    }
    file.close();

    file.open("text.txt", std::ios::in);
    if (!file) {
        std::cerr << "deu merda" << std::endl;
        return -1;
    }
    while (file >> word) {
        if (word == "o" || word == "a" || word == "os" || word == "as") {
            artigos++;
        }
        espaco++;
    }
    file.close();

    file.open("text.txt", std::ios::in);
    if (!file) {
        std::cerr << "deu merda" << std::endl;
        return -1;
    }
    while (file.getline(line, 200)) {
        linhas++;
    }
    file.close();

    std::cout << "espacos: " << espaco << std::endl;
    std::cout << "linhas: " << linhas << std::endl;
    std::cout << "vogais: " << vogais << std::endl;
    std::cout << "artigos: " << artigos << std::endl;
}