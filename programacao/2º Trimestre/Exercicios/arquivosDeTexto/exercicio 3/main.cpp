#include <iostream>
#include <fstream>
#include <string>

int main() {
    int espaco = 0, linhas = 0, vogais = 0, artigos = 0;
    char letter, line[200];
    std::string word, name;
    std::fstream file, out;

    std::cout << "fala o nome do arquivo infeliz: ";
    std::cin >> name;

    file.open(name + ".txt", std::ios::in);
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

    file.open(name + ".txt", std::ios::in);
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

    file.open(name + ".txt", std::ios::in);
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

    
    out.open(name + "_ref.txt", std::ios::out);
    if (!out) {
        std::cerr << "deu xabu piazada";
        return -1;
    }

    out << "espacos: " << espaco << std::endl;
    out << "linhas: " << linhas << std::endl;
    out << "vogais: " << vogais << std::endl;
    out << "artigos: " << artigos << std::endl;

    out.close();
}