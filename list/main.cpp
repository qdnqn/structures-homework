#include <iostream>
#include "Lista.h"
#include "Struct.h"

using namespace std;

int main(){
  Lista<ToDoTask> obaveze;

  int option;
  bool quit = false;

  cout << "-------------------------------------------------" << endl;
  cout << "Vaš personalni notes!" << endl;
  cout << "-------------------------------------------------" << endl;
  
  do {
    cout << endl;

    cout << "[1] Novi unos " << endl;
    cout << "[2] Pregledaj obaveze" << endl;
    cout << "[3] Označite završene obaveze " << endl;
    cout << "[4] Zatvorite program " << endl << endl;
    cout << "Vaš odabir: ";
    
    if(cin >> option){
      if(option == 1){
        ToDoTask temp;
        temp.id = generateId();

        cout << "Unesite naslov: ";
        cin >> temp.title;
        cout << "Unesite opis: ";
        cin >> temp.description;
        cout << "Unesite priorite([1] Visok, [2] Normalan): ";
        cin >> temp.priority;  
      
        obaveze.add(temp);
      } else if (option == 2){
        auto it = obaveze.begin();

        while(it != obaveze.end()){
          auto obaveza = (*it).value;
          
          cout << "------------------------------------------" << endl;
          cout << "Id: " << obaveza.id << endl;
          cout << "Naslov: " << obaveza.title << endl;
          cout << "Opis: " << obaveza.description << endl;

          if(obaveza.priority == 1){
            cout << "Prioritet: VISOK" << endl;
          } else {
            cout << "Prioritet: Normalan" << endl;
          } 

          cout << "------------------------------------------" << endl;

          ++it;
        }    
      } else if (option == 3){
        int idTemp;

        cout << "Unesite ID obaveze koju želite označiti završenom: ";
        
        if(cin >> idTemp){
          auto it = obaveze.find([idTemp](Node<ToDoTask> node) -> bool {
                if(node.value.id == idTemp){
                  return true;
                } else {
                  return false;
                }
              });

          if(it != nullptr){
            cout << "Uspješno ste uklonili obavezu: " << (*it).value.title;
            obaveze.remove(it);
          } else {
            cout << "Obaveza sa ID: " << idTemp << ", ne postoji!" << endl;
          }
        } else {
          quit = true;
        }
      } else {
        quit = true;
      }
    } else {
      quit = true;
    }   
  } while(!quit);
  
  return 0;
}
