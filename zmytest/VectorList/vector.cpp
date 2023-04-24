//
// Created by yoote on 23/04/2023.
//
#include <iostream>
#include <random>
#include "../../vector/vector.hpp"
#include "vector.hpp"

void VectorInt() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura di interi" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    lasd::Vector<int> VecInt(dim);
    while (j < dim) {
        VecInt[j] = (dist(gen));
        j++;
    }

    int elemento;
    unsigned int index = 0;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in vector a un determinato indice\n"
                  << "  2: Visualizzare l'elemento in cima a vector\n"
                  << "  3: Verificare l'elemento in coda a vector\n"
                  << "  4: Visualizzare la dimensione di vector\n"
                  << "  5: Svuotare vector\n"
                  << "  6: Ordinamento vector\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1': //Insert
                std::system("clear");
                std::cout << "Inserire elemento da inserire in vector: \n";
                std::cin >> elemento;
                std::cout << "Inserire indice a cui inserire in vector: \n";
                std::cin >> index;
                VecInt[index] = elemento;
                break;
            case '2': //Front
                std::system("clear"); //FrontNRemove
                std::cout << "Elemento in cima a Vector: " << VecInt.Front() << std::endl;
                break;
            case '3': //Back
                std::system("clear"); //FrontNRemove
                std::cout << "Elemento in coda a Vector: " << VecInt.Back() << std::endl;
                break;
            case '4':
                std::system("clear"); //Size
                std::cout << "Dimensione del Vector pari a " << VecInt.Size() << std::endl;
                break;
            case '5': //ListClear
                std::system("clear");
                std::cout << "Struttura ora vuota.\n";
                VecInt.Clear();
                break;
            case  '6':
                std::system("clear");
                std::cout << "Vector ordinato.\n";
                VecInt.Sort();
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}
void VectorDouble() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura di double" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(std::numeric_limits<double>::min(),std::numeric_limits<double>::max());

    lasd::Vector<int> VecDouble(dim);
    while (j < dim) {
        VecDouble[j] = (dist(gen));
        j++;
    }

    int elemento;
    unsigned int index = 0;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in vector a un determinato indice\n"
                  << "  2: Visualizzare l'elemento in cima a vector\n"
                  << "  3: Verificare l'elemento in coda a vector\n"
                  << "  4: Visualizzare la dimensione di vector\n"
                  << "  5: Svuotare vector\n"
                  << "  6: Ordinamento vector\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1': //Insert
                std::system("clear");
                std::cout << "Inserire elemento da inserire in vector: \n";
                std::cin >> elemento;
                std::cout << "Inserire indice a cui inserire in vector: \n";
                std::cin >> index;
                VecDouble[index] = elemento;
                break;
            case '2': //Front
                std::system("clear"); //FrontNRemove
                std::cout << "Elemento in cima a Vector: " << VecDouble.Front() << std::endl;
                break;
            case '3': //Back
                std::system("clear"); //FrontNRemove
                std::cout << "Elemento in coda a Vector: " << VecDouble.Back() << std::endl;
                break;
            case '4':
                std::system("clear"); //Size
                std::cout << "Dimensione del Vector pari a " << VecDouble.Size() << std::endl;
                break;
            case '5': //ListClear
                std::system("clear");
                std::cout << "Struttura ora vuota.\n";
                VecDouble.Clear();
                break;
            case  '6':
                std::system("clear");
                std::cout << "Vector ordinato.\n";
                VecDouble.Sort();
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

void VectorString() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura di double" << std::endl;
    std::cin >> dim;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist('A', 'Z');
    std::string result;

    lasd::Vector<std::string> VecString(dim);
    while (j < dim) {
        result += static_cast<char>(dist(gen));
        VecString[j] = result;
        j++;
    }

    int elemento;
    unsigned int index = 0;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in vector a un determinato indice\n"
                  << "  2: Visualizzare l'elemento in cima a vector\n"
                  << "  3: Verificare l'elemento in coda a vector\n"
                  << "  4: Visualizzare la dimensione di vector\n"
                  << "  5: Svuotare vector\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1': //Insert
                std::system("clear");
                std::cout << "Inserire elemento da inserire in vector: \n";
                std::cin >> elemento;
                std::cout << "Inserire indice a cui inserire in vector: \n";
                std::cin >> index;
                VecString[index] = elemento;
                break;
            case '2': //Front
                std::system("clear"); //FrontNRemove
                std::cout << "Elemento in cima a Vector: " << VecString.Front() << std::endl;
                break;
            case '3': //Back
                std::system("clear"); //FrontNRemove
                std::cout << "Elemento in coda a Vector: " << VecString.Back() << std::endl;
                break;
            case '4':
                std::system("clear"); //Size
                std::cout << "Dimensione del Vector pari a " << VecString.Size() << std::endl;
                break;
            case '5': //ListClear
                std::system("clear");
                std::cout << "Struttura ora vuota.\n";
                VecString.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}