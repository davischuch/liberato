#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

int main() {
    std::string name, word;
    std::fstream in, out;
    std::unordered_map<std::string, int> map;

    std::cout << "fala o nome do arquivo ai bixo: ";
    std::cin >> name;

    in.open(name + ".txt", std::ios::in);
    if (!in) {
        std::cerr << "deu xabu piazada";
        return -1;
    }

    while (in >> word) {
        for (auto & x : word) {
            x = tolower(x);
        }
        map[word] += 1;
    }

    out.open(name + "_ref.txt", std::ios::out);
    for (auto & it : map) {
        out << it.first << ": " << it.second << std::endl;
    }
    in.close();
    out.close();
}