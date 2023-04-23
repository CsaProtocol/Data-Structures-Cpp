#include "test.hpp"


/* ************************************************************************ */

// Main Menu
using uint = unsigned int;
using ulong = unsigned long;
using ushort = unsigned short int;

#include <iostream>
#include "../zlasdtest/test.hpp"

#include "test.hpp"
#include "../Stack/Stack.hpp"
#include "../Queue/Queue.hpp"
#include "Stack/stack.hpp"

void stackQueueTest(){
    bool quit = false;
    char scelta;
    std::cout << "Scegli il tipo di struttura: "<< std::endl;
    std::cout<<"Stack implementato con vettori (1 -> int; 2 -> double; 3 -> string)"<< std::endl;
    std::cout<<"Stack implementato con lista (4 -> int; 5 -> double; 6 -> string)"<< std::endl;
    std::cout<<"Queue implementata con vettori (a -> int; b -> double; c -> string)"<< std::endl;
    std::cout<<"Queue implementato con lista (d -> int; e -> double; f -> string)"<< std::endl;
    std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;

    while (scelta != 'q'){
        std::cin >> scelta;

        if ((scelta != '1') && (scelta != '2') && (scelta != '3') &&
            (scelta != '4') && (scelta != '5') && (scelta != '6') &&
            (scelta != 'a') && (scelta != 'b') && (scelta != 'c') &&
            (scelta != 'd') && (scelta != 'e') && (scelta != 'f') &&
            (scelta != 'q')) {
            std::cout << "ERRORE: scelta non valida\n";
        }
        if (scelta == '1') {
            std::system("clear");
            //StackVecInt();
        }
        if (scelta == '2') {
            std::system("clear");
            //StackVecDouble();
            quit = true;
        }

        if (scelta == '3') {
            std::system("clear");
            //StackVecString();
            quit = true;
        }
        if (scelta == '4') {
            std::system("clear");
            //StackListInt();
            quit = true;
        }

        if (scelta == '5') {
            std::system("clear");
            //StackListDouble();
            quit = true;
        }
        if (scelta == '6') {
            std::system("clear");
            //StackListString();
            quit = true;
        }
        if (scelta == 'a') {
            std::system("clear");
            //QueueVecInt();
            quit = true;
        }
        if (scelta == 'b') {
            std::system("clear");
            //QueueVecDouble();
            quit = true;
        }
        if (scelta == 'c') {
            std::system("clear");
            //QueueVecString();
            quit = true;
        }
        if (scelta == 'd') {
            std::system("clear");
            //QueueListInt();
            quit = true;
        }
        if (scelta == 'e') {
            std::system("clear");
            //QueueListDouble();
            quit = true;
        }
        if (scelta == 'f') {
            std::system("clear");
            //QueueListString();
            quit = true;
        }
    }
}

//dataStructureTest
void dataStructureTest() {
    int choice;

    std::cout << "Seleziona una struttura dati:\n";
    std::cout << "1. List & Vector\n";
    std::cout << "3. Stack & Queue\n";
    std::cout << "Scrivi il numero corrispondente alla tua scelta: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Vector & Lista selezionato.\n";
            break;
        case 2:
            std::cout << "Stack & Queue selezionato.\n";
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