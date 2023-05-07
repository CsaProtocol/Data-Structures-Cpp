//
// Created by yoote on 23/04/2023.
//
#include <iostream>
#include <random>
#include <climits>
#include "../../list/list.hpp"

#include "list.hpp"

void ListInt() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della lista di interi" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    lasd::List<int> ListInt;
    while (j < dim) {
        ListInt.InsertAtFront(dist(gen));
        j++;
    }

    int elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in list\n"
                  << "  2: Rimuovere l'elemento in cima a list\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a list\n"
                  << "  4: Verificare se list è vuoto\n"
                  << "  5: Visualizzare la dimensione di list\n"
                  << "  6: Svuotare list\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in lista: \n";
                std::cin >> elemento;
                ListInt.InsertAtFront(elemento);
                break;
            case '2':
                ListInt.RemoveFromFront();
                break;
            case '3':
                std::cout << "Elemento rimosso: " << ListInt.FrontNRemove() << std::endl;
                break;
            case '4':
                if (ListInt.Empty()) {
                    std::cout << "Lista vuota \n";
                } else { std::cout << "Lista non vuota \n"; }
                break;
                break;
            case '5':
                std::cout << "Dimensione della lista pari a " << ListInt.Size() << std::endl;
                break;
            case '6':
                std::cout << "Struttura ora vuota.\n";
                ListInt.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}


void ListDouble() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della lista di double" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(std::numeric_limits<double>::min(),std::numeric_limits<double>::max());

    lasd::List<double> ListDouble;
    while (j < dim) {
        ListDouble.InsertAtFront(dist(gen));
        j++;
    }

    double elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in list\n"
                  << "  2: Rimuovere l'elemento in cima a list\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a list\n"
                  << "  4: Verificare se list è vuoto\n"
                  << "  5: Visualizzare la dimensione di list\n"
                  << "  6: Svuotare list\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in lista: \n";
                std::cin >> elemento;
                ListDouble.InsertAtFront(elemento);
                break;
            case '2':
                ListDouble.RemoveFromFront();
                break;
            case '3':
                std::cout << "Elemento rimosso: " << ListDouble.FrontNRemove() << std::endl;
                break;
            case '4':
                if (ListDouble.Empty()) {
                    std::cout << "Lista vuota \n";
                } else { std::cout << "Lista non vuota \n"; }
                break;
                break;
            case '5':
                std::cout << "Dimensione della struttura pari a " << ListDouble.Size() << std::endl;
                break;
            case '6':
                std::cout << "Struttura ora vuota.\n";
                ListDouble.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}
void ListString() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura di stringhe" << std::endl;
    std::cin >> dim;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist('A', 'Z');
    std::string result;

    lasd::List<std::string> ListString;
    while (j < dim){
        result += static_cast<char>(dist(gen));
        ListString.InsertAtFront(result);
        j++;
    }

    std::string elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in list\n"
                  << "  2: Rimuovere l'elemento in cima a list\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a list\n"
                  << "  4: Verificare se list è vuoto\n"
                  << "  5: Visualizzare la dimensione di list\n"
                  << "  6: Svuotare list\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in lista: \n";
                std::cin >> elemento;
                ListString.InsertAtFront(elemento);
                break;
            case '2':
                ListString.RemoveFromFront();
                break;
            case '3':
                std::cout << "Elemento rimosso: " << ListString.FrontNRemove() << std::endl;
                break;
            case '4':
                if (ListString.Empty()) {
                    std::cout << "Lista vuota \n";
                } else { std::cout << "Lista non vuota \n"; }
                break;
            case '5':
                std::cout << "Dimensione della struttura pari a " << ListString.Size() << std::endl;
                break;
            case '6':
                std::cout << "Struttura ora vuota.\n";
                ListString.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}
