#include "test.hpp"


/* ************************************************************************ */

// Main Menu
using uint = unsigned int;
using ulong = unsigned long;
using ushort = unsigned short int;

#include <iostream>

void vectorListTest(){

    bool exit = false;

    char choice;

    do {

        std::cout << "Scegli il tipo di struttura: "<< std::endl;
        std::cout<<"List (1 -> int; 2 -> double; 3 -> string)"<< std::endl;
        std::cout<<"Vector (4 -> int; 5 -> double; 6 -> string)"<< std::endl;
        std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;

        std::cin >> choice;

        switch(choice){
            case '1':
                ListInt();
                break;
            case '2':
                ListDouble();
                break;
            case '3':
                ListString();
                break;
            case '4':
                VectorInt();
                break;
            case '5':
                VectorDouble();
                break;
            case '6':
                VectorString();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

//StackQueue
void stackQueueTest(){

    bool exit = false;

    char choice;

    do {

        std::cout << "Scegli il tipo di struttura: "<< std::endl;
        std::cout<<"StackVec (1 -> int; 2 -> double; 3 -> string)"<< std::endl;
        std::cout<<"StackLst (4 -> int; 5 -> double; 6 -> string)"<< std::endl;
        std::cout<<"QueueVec (a -> int; b -> double; c -> string)"<< std::endl;
        std::cout<<"QueueLst (d -> int; e -> double; f -> string)"<< std::endl;
        std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;

        std::cin >> choice;

        switch(choice){
            case '1':
                StackVecInt();
                break;
            case '2':
                StackVecDouble();
                break;
            case '3':
                StackVecString();
                break;
            case '4':
                StackLstInt();
                break;
            case '5':
                StackLstDouble();
                break;
            case '6':
                StackLstString();
                break;
            case 'a':
                QueueVecInt();
                break;
            case 'b':
                QueueVecDouble();
                break;
            case 'c':
                QueueVecString();
                break;
            case 'd':
                QueueLstInt();
                break;
            case 'e':
                QueueLstDouble();
                break;
            case 'f':
                QueueLstString();
                break;
            case 'q':
                exit = true;
                break;
            default:
                break;
        }
    } while (!exit);
}

//dataStructureTest
void dataStructureTest() {
    int choice;

    std::cout << "Seleziona una struttura dati:\n";
    std::cout << "1. List & Vector\n";
    std::cout << "2. StackQueue & Queue\n";
    std::cout << "Scrivi il numero corrispondente alla tua scelta: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Vector & Lista selezionato.\n";
            vectorListTest();
            break;
        case 2:
            std::cout << "StackQueue & Queue selezionato.\n";
            stackQueueTest();
            break;
        default:
            std::cout << "Scelta non valida.\n";
            break;
    }
}

//Menu principale
void Menu(){

    bool exit = false;
    ushort choice;

    do{

        std::cout<<"\tWelcome to the Menu!\nWhat do you want to run?\n";
        std::cout<<"0) LASD Test Suite\n";
        std::cout<<"1) Data Structure Test\n";
        std::cout<<"2) Exit\n";

        std::cin>>choice;

        switch(choice){
            case 0:{
                lasdtest();
                break;}

            case 1:{
                dataStructureTest();
                break;}

            case 2:{
                std::cout<<"GoodBye!\n";
                exit = true;
                break;}

            default:
                break;
        }
    }while(!exit);
}

/* ************************************************************************ */