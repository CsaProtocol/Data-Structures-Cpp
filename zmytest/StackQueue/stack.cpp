//
// Created by yoote on 23/04/2023.
//
#include <iostream>
#include <random>
#include <string>
#include "../../stack/stack.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"
#include "Stack.hpp"
//Int
void StackVecInt(){
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    lasd::StackVec<int> StackVecInt;
    while (j < dim){
        StackVecInt.Push(dist(gen));
        j++;
    }
    int elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Stack\n"
                  << "  2: Rimuovere l'elemento in cima a Stack\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Stack\n"
                  << "  4: Visualizzare l'elemento in cima a Stack\n"
                  << "  5: Verificare se Stack è vuoto\n"
                  << "  6: Visualizzare la dimensione di Stack\n"
                  << "  7: Svuotare Stack\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch(choice){
            case '1': //Push
                std::system("clear");
                std::cout << "Inserire elemento da inserire in Stack: \n";
                std::cin >> elemento;
                StackVecInt.Push(elemento);
                break;
            case '2':
                std::system("clear"); //Pop
                StackVecInt.Pop();
                break;
            case '3': //TopNPop
                std::system("clear"); //TopNPop
                StackVecInt.TopNPop();
                break;
            case '4':
                std::system("clear"); //Top
                StackVecInt.Top();
                break;
            case '5':
                std::system("clear"); //Empty
                if(StackVecInt.Empty()) {
                    std::cout << "Stack vuoto \n";
                } else { std::cout << "Stack non vuoto \n"; }
                break;
            case '6':
                std::system("clear"); //StackSize
                std::cout << "Dimensione dello stack pari a " << StackVecInt.Size() << std::endl;
                break;
            case '7': //StackClear
                std::system("clear");
                std::cout<< "Struttura ora vuota.\n";
                StackVecInt.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while(!exit);
}

void StackLstInt(){
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    lasd::StackLst<int> StackLstInt;
    while (j < dim){
        StackLstInt.Push(dist(gen));
        j++;
    }
    int elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Stack\n"
                  << "  2: Rimuovere l'elemento in cima a Stack\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Stack\n"
                  << "  4: Visualizzare l'elemento in cima a Stack\n"
                  << "  5: Verificare se Stack è vuoto\n"
                  << "  6: Visualizzare la dimensione di Stack\n"
                  << "  7: Svuotare Stack\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch(choice){
            case '1': //Push
                std::system("clear");
                std::cout << "Inserire elemento da inserire in Stack: \n";
                std::cin >> elemento;
                StackLstInt.Push(elemento);
                break;
            case '2':
                std::system("clear"); //Pop
                StackLstInt.Pop();
                break;
            case '3': //TopNPop
                std::system("clear"); //TopNPop
                StackLstInt.TopNPop();
                break;
            case '4':
                std::system("clear"); //Top
                StackLstInt.Top();
                break;
            case '5':
                std::system("clear"); //Empty
                if(StackLstInt.Empty()) {
                    std::cout << "Stack vuoto \n";
                } else { std::cout << "Stack non vuoto \n"; }
                break;
            case '6':
                std::system("clear"); //StackSize
                std::cout << "Dimensione dello stack pari a " << StackLstInt.Size() << std::endl;
                break;
            case '7': //StackClear
                std::system("clear");
                std::cout<< "Struttura ora vuota.\n";
                StackLstInt.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while(!exit);
}

void StackVecDouble(){
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione dello stack di double" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(std::numeric_limits<double>::min(),std::numeric_limits<double>::max());

    lasd::StackVec<double> StackVecDouble;
    while (j < dim){
        StackVecDouble.Push(dist(gen));
        j++;
    }

    double elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Stack\n"
                  << "  2: Rimuovere l'elemento in cima a Stack\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Stack\n"
                  << "  4: Visualizzare l'elemento in cima a Stack\n"
                  << "  5: Verificare se Stack è vuoto\n"
                  << "  6: Visualizzare la dimensione di Stack\n"
                  << "  7: Svuotare Stack\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch(choice){
            case '1': //Push
                std::system("clear");
                std::cout << "Inserire elemento da inserire in Stack: \n";
                std::cin >> elemento;
                StackVecDouble.Push(elemento);
                break;
            case '2':
                std::system("clear"); //Pop
                StackVecDouble.Pop();
                break;
            case '3': //TopNPop
                std::system("clear"); //TopNPop
                StackVecDouble.TopNPop();
                break;
            case '4':
                std::system("clear"); //Top
                StackVecDouble.Top();
                break;
            case '5':
                std::system("clear"); //Empty
                if(StackVecDouble.Empty()) {
                    std::cout << "Stack vuoto \n";
                } else { std::cout << "Stack non vuoto \n"; }
                break;
            case '6':
                std::system("clear"); //StackSize
                std::cout << "Dimensione dello stack pari a " << StackVecDouble.Size() << std::endl;
                break;
            case '7': //StackClear
                std::system("clear");
                std::cout<< "Struttura ora vuota.\n";
                StackVecDouble.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while(!exit);
}

void StackLstDouble(){
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione dello stack di double" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(std::numeric_limits<double>::min(),std::numeric_limits<double>::max());

    lasd::StackLst<double> StackLstDouble;
    while (j < dim){
        StackLstDouble.Push(dist(gen));
        j++;
    }

    double elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Stack\n"
                  << "  2: Rimuovere l'elemento in cima a Stack\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Stack\n"
                  << "  4: Visualizzare l'elemento in cima a Stack\n"
                  << "  5: Verificare se Stack è vuoto\n"
                  << "  6: Visualizzare la dimensione di Stack\n"
                  << "  7: Svuotare Stack\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch(choice){
            case '1': //Push
                std::system("clear");
                std::cout << "Inserire elemento da inserire in Stack: \n";
                std::cin >> elemento;
                StackLstDouble.Push(elemento);
                break;
            case '2':
                std::system("clear"); //Pop
                StackLstDouble.Pop();
                break;
            case '3': //TopNPop
                std::system("clear"); //TopNPop
                StackLstDouble.TopNPop();
                break;
            case '4':
                std::system("clear"); //Top
                StackLstDouble.Top();
                break;
            case '5':
                std::system("clear"); //Empty
                if(StackLstDouble.Empty()) {
                    std::cout << "Stack vuoto \n";
                } else { std::cout << "Stack non vuoto \n"; }
                break;
            case '6':
                std::system("clear"); //StackSize
                std::cout << "Dimensione dello stack pari a " << StackLstDouble.Size() << std::endl;
                break;
            case '7': //StackClear
                std::system("clear");
                std::cout<< "Struttura ora vuota.\n";
                StackLstDouble.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while(!exit);
}

void StackVecString(){
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione dello stack di double" << std::endl;
    std::cin >> dim;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist('A', 'Z');
    std::string result;

    lasd::StackVec<std::string> StackVecString;
    while (j < dim){
        result += static_cast<char>(dist(gen));
        StackVecString.Push(result);
        j++;
    }

    std::string elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Stack\n"
                  << "  2: Rimuovere l'elemento in cima a Stack\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Stack\n"
                  << "  4: Visualizzare l'elemento in cima a Stack\n"
                  << "  5: Verificare se Stack è vuoto\n"
                  << "  6: Visualizzare la dimensione di Stack\n"
                  << "  7: Svuotare Stack\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch(choice){
            case '1': //Push
                std::system("clear");
                std::cout << "Inserire elemento da inserire in Stack: \n";
                std::cin >> elemento;
                StackVecString.Push(elemento);
                break;
            case '2':
                std::system("clear"); //Pop
                StackVecString.Pop();
                break;
            case '3': //TopNPop
                std::system("clear"); //TopNPop
                StackVecString.TopNPop();
                break;
            case '4':
                std::system("clear"); //Top
                StackVecString.Top();
                break;
            case '5':
                std::system("clear"); //Empty
                if(StackVecString.Empty()) {
                    std::cout << "Stack vuoto \n";
                } else { std::cout << "Stack non vuoto \n"; }
                break;
            case '6':
                std::system("clear"); //StackSize
                std::cout << "Dimensione dello stack pari a " << StackVecString.Size() << std::endl;
                break;
            case '7': //StackClear
                std::system("clear");
                std::cout<< "Struttura ora vuota.\n";
                StackVecString.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while(!exit);
}

void StackLstString(){
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione dello stack di double" << std::endl;
    std::cin >> dim;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist('A', 'Z');
    std::string result;

    lasd::StackLst<std::string> StackLstString;
    while (j < dim){
        result += static_cast<char>(dist(gen));
        StackLstString.Push(result);
        j++;
    }

    std::string elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Stack\n"
                  << "  2: Rimuovere l'elemento in cima a Stack\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Stack\n"
                  << "  4: Visualizzare l'elemento in cima a Stack\n"
                  << "  5: Verificare se Stack è vuoto\n"
                  << "  6: Visualizzare la dimensione di Stack\n"
                  << "  7: Svuotare Stack\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch(choice){
            case '1': //Push
                std::system("clear");
                std::cout << "Inserire elemento da inserire in Stack: \n";
                std::cin >> elemento;
                StackLstString.Push(elemento);
                break;
            case '2':
                std::system("clear"); //Pop
                StackLstString.Pop();
                break;
            case '3': //TopNPop
                std::system("clear"); //TopNPop
                StackLstString.TopNPop();
                break;
            case '4':
                std::system("clear"); //Top
                StackLstString.Top();
                break;
            case '5':
                std::system("clear"); //Empty
                if(StackLstString.Empty()) {
                    std::cout << "Stack vuoto \n";
                } else { std::cout << "Stack non vuoto \n"; }
                break;
            case '6':
                std::system("clear"); //StackSize
                std::cout << "Dimensione dello stack pari a " << StackLstString.Size() << std::endl;
                break;
            case '7': //StackClear
                std::system("clear");
                std::cout<< "Struttura ora vuota.\n";
                StackLstString.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while(!exit);
}
