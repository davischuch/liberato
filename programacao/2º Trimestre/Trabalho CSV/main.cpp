#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <map>
#include <regex>
using namespace std;

map<string, array<array<string, 5>, 11>> matrix;

int main() {
    int l = 1, lines = -1;
    string disciplina, identificacao, linha, turma, last, periodos[] = {"07:30", "08:20", "09:10", "10:20", "11:10", "13:10", "14:00", "14:50", "16:00", "16:50", "17:40"};
    fstream alocacao, horarios, output;
    map<string, vector<string>> lab;
    map<string, int> errors;

    string lastD, lastT;

    alocacao.open("alocacao.csv", ios::in);
    if (!alocacao) {
        cerr << "alocacao.csv nao pode ser aberto" << endl;
        return -1;
    }
    horarios.open("horarios.csv", ios::in);
    if (!horarios) {
        cerr << "horarios.csv nao pode ser aberto" << endl;
        return -1;
    }
    output.open("labs.csv", ios::out);
    if (!output) {
        cerr << "labs.csv nao pode ser aberto" << endl;
        return -1;
    }

    while(getline(alocacao, linha)){
        if (l > 2) {
            int i;
            for(i = 0; linha[i] != ',' && i < linha.size(); i++) disciplina.push_back(linha[i]);
            for(i = i + 5; i < linha.size(); i++) identificacao.push_back(linha[i]);
            identificacao.pop_back();
            lab[identificacao].push_back(disciplina);
            disciplina = "";
            identificacao = "";
        }
        l++;
    }
    alocacao.close();

    int i = 0;
    while(getline(horarios, linha)){
        if(linha.substr(0, 5) == "07:30") i = 0;
        if(linha.substr(0, 5) == "Turma") {
            turma = linha.substr(6, 4);
            continue;
        } else if(linha.substr(2, 1) == ":") {       
            int k = 6;
            int j = 0;
            for(; k < linha.size(); k++){
                if (linha[k] == ',') {
                    disciplina = "";
                    j++;
                } else {
                    disciplina.push_back(linha[k]);
                    for (auto & l : lab) {
                        for (int m = 0; m < l.second.size(); m++) {
                            if (disciplina == l.second[m]) {
                                if (matrix[l.first][i][j] != "") {
                                    regex pattern("-\\s*(\\d{4})");
                                    std::smatch match;
                                    if (regex_search(matrix[l.first][i][j], match, pattern)) {
                                        string t = match.str(1);
                                        if (t != turma) {
                                            errors[l.first]++;
                                            matrix[l.first][i][j] += " / " + disciplina + " - " + turma;
                                        }
                                    }
                                } else {
                                    matrix[l.first][i][j] = disciplina + " - " + turma;
                                }
                            }
                        }
                    }
                }
            }
            disciplina = "";
            i++;
        }
    }
    horarios.close();

    for (auto & it : matrix) {
        output << it.first << ",,,,,\n,,,,,\n,Segunda,Terça,Quarta,Quinta,Sexta\n";
        
        for (int i = 0; i < 11; i++) {
            output << periodos[i] << ",";
            for (int j = 0; j < 5; j++) {
                output << it.second[i][j];
                if(j != 4) output << ",";
                else output << "\n";
            }
        }

        output << ",,,,,\n";
    }

    output << "relatorio" << std::endl;
    output << "sala,conflito" << std::endl;
    output << "," << std::endl;
    for (auto & it : errors) {
        output << it.first << "," << it.second << endl;
    }
    output.close();
}