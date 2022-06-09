//
// Created by migue on 09/06/2022.
//

#ifndef GYMAPPLICATION_MOCKDATA_H
#define GYMAPPLICATION_MOCKDATA_H
#include <string>
#include <vector>
#include "gym.h"

using namespace std;
class mockdata{
private:
    int ENROLLS_NR = 5;
    int LECTURES_NR = 5;
    int FEEDBACK_NR = 1;
    const vector<string> n_clients = {"Daniela Melo", "Davi Lucas da Mata", "Alicia Pinto", "Cecilia Caldeira", "Camila Costa", "Vitor Hugo Barros", "Enzo Gabriel Melo", "Maria Julia Cavalcanti", "Stella Souza", "Nathan da Paz", "Eduarda Novaes", "Leonardo Vieira","Stella Ramos", "Carolina Ribeiro", "Luiz Henrique Azevedo", "Ana Carolina Moura", "Helena da Rocha","Ana Julia Caldeira","Stephany Moraes","Luna da Rosa","Larissa Rezende","Joao Miguel Viana","Maria Clara Duarte","Alicia Moura","Clarice Teixeira","Luiz Fernando Martins","Kevin Pires","Pietro Barbosa","Isis Araujo","Ana Luiza Moura","Caue Azevedo","Larissa da Cunha","Nathan Alves","Lucas Gabriel Barros","Lucas Barbosa","Mariana Campos","Mirella Cardoso","Amanda Monteiro","Emilly Mendes","Luiz Otavio Rodrigues","Antonio Sales","Julia Caldeira","Diogo Freitas","Levi Moura","Ana Livia Moura","Maria Clara Oliveira","Yuri Fogaca","Alicia Duarte","Maysa Mendes","Otavio Ribeiro"};
    const vector<string> n_emp = {"Kevin Lima","Igor Souza","Ana Beatriz Ramos","Sarah Azevedo","Bernardo Pinto","Bruna da Rosa","Camila Aragao","Bruna Alves","Ana Livia Costa","Vitoria Moraes"};
    const vector<string> n_i_emp = {"KNLA", "IRSZ", "ABRS","SHAO", "BOPO","BDRA", "CAAO", "BAAS", "ALCA", "VAMS"};
    const vector<string> n_classes = {"Cycling", "Hidroginastica", "BodyPump","BodyCombat", "Pilates"};
    const vector<string> n_i_cla = {"CYNG", "HICA", "BOMP","BOAT", "PIES"};
    const vector<string> age = {"18", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80"};
    const vector<string> feed = {"Não Gostei", "Gostei", "Gostei Muito", "Sem opinião"};
    void insertClients(ClientContainer& container);
    void insertEmployees(EmployeeContainer& container);
    void insertClasses(ClassContainer& container);
    void insertEnrolls(ClientContainer& clients, ClassContainer& classes, EnrollContainer & container);
    void insertFeedbackCla(ClientContainer& clients, ClassContainer& classes, FeedbackContainer & container);
    void insertLecture(ClassContainer & classes, EmployeeContainer& employees);
    Class * getRandomClass(ClassContainer& classes);
public:
    void generateData(gym& gym);
};

#endif //GYMAPPLICATION_MOCKDATA_H
