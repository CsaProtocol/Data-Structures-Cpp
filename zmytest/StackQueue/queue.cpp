//
// Created by yoote on 23/04/2023.
//
#include <iostream>
#include <random>
#include <climits>
#include "../../queue/queue.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"
#include "queue.hpp"

void QueueVecInt() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della Queue di interi" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    lasd::QueueVec<int> QueueVecInt;
    while (j < dim) {
        QueueVecInt.Enqueue(dist(gen));
        j++;
    }
    int elemento;
    do {
        std::cout << "Selezionare un'operazione da eseguire:\n"
                  << "  1: Inserire un elemento in Queue\n"
                  << "  2: Rimuovere l'elemento in cima a Queue\n"
                  << "  3: Visualizzare e rimuovere l'elemento in cima a Queue\n"
                  << "  4: Visualizzare l'elemento in cima a Queue\n"
                  << "  5: Verificare se Queue è vuoto\n"
                  << "  6: Visualizzare la dimensione di Queue\n"
                  << "  7: Svuotare Queue\n"
                  << "  q: Uscire dal programma\n"
                  << "Scelta: ";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in: \n";
                std::cin >> elemento;
                QueueVecInt.Enqueue(elemento);
                break;
            case '2':
                QueueVecInt.Dequeue();
                break;
            case '3':
                QueueVecInt.HeadNDequeue();
                break;
            case '4':
                QueueVecInt.Head();
                break;
            case '5':
                if (QueueVecInt.Empty()) {
                    std::cout << "Queue vuota \n";
                } else { std::cout << "Queue non vuota \n"; }
                break;
            case '6':
                std::cout << "Dimensione della Queue pari a " << QueueVecInt.Size() << std::endl;
                break;
            case '7':
                std::cout << "Struttura ora vuota.\n";
                QueueVecInt.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

void QueueLstInt() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura di interi" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);

    lasd::QueueLst<int> QueueLstInt;
    while (j < dim) {
        QueueLstInt.Enqueue(dist(gen));
        j++;
    }
    int elemento;
    do {
        std::cout << "Scegli una delle seguenti opzioni:\n"
                  << "1. Enqueue\n"
                  << "2. Dequeue\n"
                  << "3. HeadNDequeue\n"
                  << "4. Head\n"
                  << "5. Empty\n"
                  << "6. QueueSize\n"
                  << "7. QueueClear\n"
                  << "q. Esci dal programma\n"
                  << "Scelta: \n";
        std::cin >> choice;
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in: \n";
                std::cin >> elemento;
                QueueLstInt.Enqueue(elemento);
                break;
            case '2':
                QueueLstInt.Dequeue();
                break;
            case '3':
                QueueLstInt.HeadNDequeue();
                break;
            case '4':
                QueueLstInt.Head();
                break;
            case '5':
                if (QueueLstInt.Empty()) {
                    std::cout << "Queue vuota \n";
                } else { std::cout << "Queue non vuota \n"; }
                break;
            case '6':
                std::cout << "Dimensione della Queue pari a " << QueueLstInt.Size() << std::endl;
                break;
            case '7':
                std::cout << "Struttura ora vuota.\n";
                QueueLstInt.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}
void QueueVecDouble() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura di double" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(std::numeric_limits<double>::min(),std::numeric_limits<double>::max());

    lasd::QueueVec<double> QueueVecDouble;
    while (j < dim){
        QueueVecDouble.Enqueue(dist(gen));
        j++;
    }

    double elemento;
    do {
        std::cout << "Scegli una delle seguenti opzioni:\n"
                  << "1. Enqueue\n"
                  << "2. Dequeue\n"
                  << "3. HeadNDequeue\n"
                  << "4. Head\n"
                  << "5. Empty\n"
                  << "6. QueueSize\n"
                  << "7. QueueClear\n"
                  << "q. Esci dal programma\n"
                  << "Scelta: \n";
        std::cin >> choice;        
        switch (choice) {
            case '1':
                 std::cout << "Inserire elemento da inserire in: \n";
                std::cin >> elemento;
                QueueVecDouble.Enqueue(elemento);
                break;
            case '2':
                QueueVecDouble.Dequeue();
                break;
            case '3':
                QueueVecDouble.HeadNDequeue();
                break;
            case '4':
                QueueVecDouble.Head();
                break;
            case '5':
                if (QueueVecDouble.Empty()) {
                    std::cout << "Queue vuota \n";
                } else { std::cout << "Queue non vuota \n"; }
                break;
            case '6':
                std::cout << "Dimensione della Queue pari a " << QueueVecDouble.Size() << std::endl;
                break;
            case '7': 
                 std::cout << "Struttura ora vuota.\n";
                QueueVecDouble.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

void QueueLstDouble() {
    unsigned int dim;
    unsigned int j = 0;

    bool exit = false;
    char choice = 'm';
    std::cout << "Inserire la dimensione della struttura  di double" << std::endl;
    std::cin >> dim;

    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(std::numeric_limits<double>::min(),std::numeric_limits<double>::max());

    lasd::QueueLst<double> QueueLstDouble;
    while (j < dim){
        QueueLstDouble.Enqueue(dist(gen));
        j++;
    }

    double elemento;
    do {
        std::cout << "Scegli una delle seguenti opzioni:\n"
                  << "1. Enqueue\n"
                  << "2. Dequeue\n"
                  << "3. HeadNDequeue\n"
                  << "4. Head\n"
                  << "5. Empty\n"
                  << "6. QueueSize\n"
                  << "7. QueueClear\n"
                  << "q. Esci dal programma\n"
                  << "Scelta: \n";
        std::cin >> choice;        
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in: \n";
                std::cin >> elemento;
                QueueLstDouble.Enqueue(elemento);
                break;
            case '2':
                QueueLstDouble.Dequeue();
                break;
            case '3': //TopNPop
                QueueLstDouble.HeadNDequeue();
                break;
            case '4':
                QueueLstDouble.Head();
                break;
            case '5':
                if (QueueLstDouble.Empty()) {
                    std::cout << "Queue vuota \n";
                } else { std::cout << "Queue non vuota \n"; }
                break;
            case '6':
                std::cout << "Dimensione della Queue pari a " << QueueLstDouble.Size() << std::endl;
                break;
            case '7': 
                std::cout << "Struttura ora vuota.\n";
                QueueLstDouble.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

void QueueVecString() {
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

    lasd::QueueVec<std::string> QueueVecString;
    while (j < dim){
        result += static_cast<char>(dist(gen));
        QueueVecString.Enqueue(result);
        j++;
    }

    std::string elemento;
    do {
        std::cout << "Scegli una delle seguenti opzioni:\n"
                  << "1. Enqueue\n"
                  << "2. Dequeue\n"
                  << "3. HeadNDequeue\n"
                  << "4. Head\n"
                  << "5. Empty\n"
                  << "6. QueueSize\n"
                  << "7. QueueClear\n"
                  << "q. Esci dal programma\n"
                  << "Scelta: \n";
        std::cin >> choice;        
        switch (choice) {
            case '1':
                std::cout << "Inserire elemento da inserire in: \n";
                std::cin >> elemento;
                QueueVecString.Enqueue(elemento);
                break;
            case '2':
                QueueVecString.Dequeue();
                break;
            case '3':
                QueueVecString.HeadNDequeue();
                break;
            case '4':
                QueueVecString.Head();
                break;
            case '5':
                if (QueueVecString.Empty()) {
                    std::cout << "Queue vuota \n";
                } else { std::cout << "Queue non vuota \n"; }
                break;
            case '6':
                std::cout << "Dimensione della Queue pari a " << QueueVecString.Size() << std::endl;
                break;
            case '7': 
                std::cout << "Struttura ora vuota.\n";
                QueueVecString.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

void QueueLstString() {
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

    lasd::QueueLst<std::string> QueueLstString;
    while (j < dim){
        result += static_cast<char>(dist(gen));
        QueueLstString.Enqueue(result);
        j++;
    }

    std::string elemento;
    do {
        std::cout << "Scegli una delle seguenti opzioni:\n"
                  << "1. Enqueue\n"
                  << "2. Dequeue\n"
                  << "3. HeadNDequeue\n"
                  << "4. Head\n"
                  << "5. Empty\n"
                  << "6. QueueSize\n"
                  << "7. QueueClear\n"
                  << "q. Esci dal programma\n"
                  << "Scelta: \n";
        std::cin >> choice;        
        switch (choice) {
            case '1': 
                std::cout << "Inserire elemento da inserire in: \n";
                std::cin >> elemento;
                QueueLstString.Enqueue(elemento);
                break;
            case '2':
                QueueLstString.Dequeue();
                break;
            case '3':
                QueueLstString.HeadNDequeue();
                break;
            case '4':
                QueueLstString.Head();
                break;
            case '5':
                if (QueueLstString.Empty()) {
                    std::cout << "Queue vuota \n";
                } else { std::cout << "Queue non vuota \n"; }
                break;
            case '6':
                std::cout << "Dimensione della Queue pari a " << QueueLstString.Size() << std::endl;
                break;
            case '7':
                std::cout << "Struttura ora vuota.\n";
                QueueLstString.Clear();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}