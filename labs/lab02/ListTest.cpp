//	Modified: 8/30/2006: mc2zk
//  CS216 Lab 1 - Test Harness
//   by Michael Crane
//
//  Integrate this test harness with your List implementation to
//  thoroughly test your design.  I have only used functions that were
//  explicitly defined in the specification, with one exception:
//
//  I have assumed a global print function whose prototype is
//      void printList(List l, bool forward);
//
//  If the 'forward' parameter is true,
//      the list is printed in forward order
//  if the 'forward' parameter is false,
//      the list is printed in reverse order


#include <iostream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
using namespace std;

//Make sure your own files for the List and ListItr
//classes are included here.  These are the names I used.
#include "List.h"
#include "ListItr.h"


int      menu (string option[], int n_opt);

//set up menu options
string   option[] =   { "Quit",
                        "New List",
                        "Show List elements",
                        "Set ListItr with first()",
                        "Set ListItr with find()",
                        "Set ListItr with last()",
                        "Move ListItr forward",
                        "Move ListItr backward",
                        "Retrieve element at ListItr",
                        "Insert element before",
                        "Insert element after",
                        "Insert element at tail",
                        "Remove element",
                        "Cardinality (size)",
                        "Copy list w/copy constructor",
                        "Copy list with operator=",
                        "Make list empty",
                      };
int      const n_choice = 17;

int   main ()
/*
**  This main driver program interactively exercises a
**   list package.
**  It assumes a linked list implementation, and its real
**   purpose is to exercise the underlying list manipulation
**   procedures.
**  It uses a menu to accept commands from the terminal,
**   then performs the indicated command.
*/
{
    int      command;
    string   response;
    List     *list = NULL;
    ListItr  *itr = NULL;
    // Initialize this run
    cout << "--------------------------------------------------\n";
    cout << "\tThis test harness operates with one List\n"
         << "\tobject and one ListItr object.\n\n"
         << "\tUse the menu options to manipulate these\n"
         << "\tobjects.\n";

    while (1) {
        command = menu(option, n_choice);

        switch (command) {
            case 1:                        // Quit
                cout << "\tDo you really want to quit? (y/n) > ";
                cin  >> response;

                if (response[0] == 'y' || response[0] == 'Y') {                 // Normal Exit
                    if (list != NULL) delete list;
                    if (itr != NULL) delete itr;
                    return 0;
                }

                break;

            case 2:                        // New list
                if (list != NULL) delete list;
                list = new List;

                cout << "\tYou have created an empty list\n";
                cout << "\tDo you want to initialize it with elements? (y/n) > ";
                cin  >> response;

                if (response[0] != 'y' && response[0] != 'Y')
                    break;
                // accept elements
                cout << "\t\tEnter elements one by one as integers.\n";
                cout << "\t\tAny non-numeric character, e.g. #, ";
                cout << "will terminate input\n";

                cout << "\tEnter first element: ";
                cin >> response;

                while (isdigit(response[0])) {
                    int element = atoi(response.c_str());
                    list->insertAtTail(element);

                    cout << "\tEnter next element: ";
                    cin >> response;
                }

                cout << endl << "The elements in forward order: " << endl;
                printList(*list, true);
                break;

            case 3:                      // show elements
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }
                cout << "\tPrint the list forwards or backwards? (f/b) > ";
                cin  >> response;

                if (response[0] == 'b' || response[0] == 'B') {
                    cout << endl << "The elements in reverse order:" << endl;
                    printList(*list, false);
                } else {
                    cout << endl << "The elements in forward order:" << endl;
                    printList(*list, true);
                }
                break;

            case 4:                      // test first()
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }
                cout << "\tSetting the ListItr to the first element..." << endl;
                itr = new ListItr((list->first()));
                break;

            case 5:                      // test find()
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }
                cout << "\tEnter element to find: ";
                cin >> response;

                if (isdigit(response[0])) {
                    int element = atoi(response.c_str());
                    itr = new ListItr((list->find(element)));
                    cout << "\tSetting the ListItr to find("
                         << element << ")..." << endl;
                } else {
                    cout << "\tPlease enter an integer." << endl;
                }
                break;

            case 6:                      // test last()
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }
                cout << "\tSetting the ListItr to the last element..." << endl;
                itr = new ListItr((list->last()));
                break;

            case 7:                      // test moveForwards()
                if (itr == NULL) {
                    cout << endl << "\tCreate a ListItr first." << endl;
                    break;
                }
                cout << "\tMoving the ListItr forwards..." << endl;
                itr->moveForward();
                break;

            case 8:                      // test move_backwards()
                if (itr == NULL) {
                    cout << endl << "\tCreate a ListItr first." << endl;
                    break;
                }
                cout << "\tMoving the ListItr backwards..." << endl;
                itr->moveBackward();
                break;

            case 9:                      // test retrieve()
                if (itr == NULL) {
                    cout << endl << "\tCreate a ListItr first." << endl;
                    break;
                }

                if (itr->isPastBeginning())
                    cout << "\tThe ListItr is past the beginning." << endl;
                else if (itr->isPastEnd())
                    cout << "\tThe ListItr is past the end." << endl;
                else
                    cout << "\tElement retrieved: " << itr->retrieve() << endl;
                break;

            case 10:                        // Insert element before
                if (list == NULL || itr == NULL) {
                    cout << endl << "\tCreate a List and ListItr first." << endl;
                    break;
                }

                cout << "\tEnter element to insert: ";
                cin >> response;

                if (isdigit(response[0])) {
                    int element = atoi(response.c_str());
                    list->insertBefore(element, *itr);
                    cout << "\tInserting " << element
                         << " before the current ListItr" <<endl;
                } else {
                    cout << "\tPlease enter an integer." << endl;
                    break;
                }

                cout << endl << "The elements in forward order: " << endl;
                printList(*list, true);
                break;

            case 11:                        // Insert element after
                if (list == NULL || itr == NULL) {
                    cout << endl << "\tCreate a List and ListItr first." << endl;
                    break;
                }

                cout << "\tEnter element to insert: ";
                cin >> response;

                if (isdigit(response[0])) {
                    int element = atoi(response.c_str());
                    list->insertAfter(element, *itr);
                    cout << "\tInserting " << element
                         << " after the current ListItr" <<endl;
                } else {
                    cout << "\tPlease enter an integer." << endl;
                    break;
                }

                cout << endl << "The elements in forward order: " << endl;
                printList(*list, true);
                break;

            case 12:                        // Insert element at tail
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }

                cout << "\tEnter element to insert: ";
                cin >> response;

                if (isdigit(response[0])) {
                    int element = atoi(response.c_str());
                    list->insertAtTail(element);
                    cout << "\tInserting " << element
                         << " at the tail of the list" <<endl;
                } else {
                    cout << "\tPlease enter an integer." << endl;
                    break;
                }

                cout << endl << "The elements in forward order: " << endl;
                printList(*list, true);
                break;

            case 13:                        // Remove element
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }

                cout << "\tEnter element to remove: ";
                cin >> response;

                if (isdigit(response[0])) {
                    int element = atoi(response.c_str());
                    list->remove(element);
                    cout << "\tRemoving " << element
                         << " from list" <<endl;
                } else {
                    cout << "\tPlease enter an integer." << endl;
                    break;
                }

                cout << endl << "The elements in forward order: " << endl;
                printList(*list, true);
                break;

            case 14:                      // test size()
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }

                cout << "\tSize of list: " << list->size() << endl;
                break;

            case 15: {                    // test copy constructor
                List* old_list=list;
                list=new List(*old_list);
                old_list->makeEmpty();

                cout << "The new list is (forward ): ";
                printList(*list, true);
                cout << "The new list is (backward): ";
                printList(*list, false);
                cout << "The old list was made empty (forward ): ";
                printList(*old_list, true);
                cout << "The old list was made empty (backward): ";
                printList(*old_list, false);
                cout << "The old list should be destroyed now." << endl;
                delete old_list;
                break;
            }
            case 16: {                    // test equals operator
                List* old_list=list;
                list=new List();
                *list=*old_list;
                old_list->makeEmpty();

                cout << "The new list is (forward ): ";
                printList(*list,true);
                cout << "The new list is (backward): ";
                printList(*list,false);
                cout << "The old list was made empty (forward ): ";
                printList(*old_list,true);
                cout << "The old list was made empty (backward): ";
                printList(*old_list,false);
                cout << "The old list should be destroyed now." << endl;

                delete old_list;
                break;
            }

            case 17:                      // test makeEmpty()
                if (list == NULL) {
                    cout << endl << "\tCreate a List first." << endl;
                    break;
                }

                cout << "The list is (forward ): ";
                printList(*list,true);
                cout << "The list is (backward): ";
                printList(*list,false);
                list->makeEmpty();
                cout << "The list was made empty (forward): ";
                printList(*list,true);
                cout << "The list was made empty (backward): ";
                printList(*list,false);
        }               // end of switch (command)
    }            // end of while (1)
}     // end of main()

int   menu (string option[], int n_opt)
/*
**  This simple routine takes an array of 'n_opt' options
**  (pointers to strings, describing the 'option')
**  displays these options on the screen,
**  and requests a choice on the part of the user
**  It returns the integer number (position in the list)
**  of the chosen option.
**
**  NOTE, all input and output uses 'stdin' and 'stdout'
*/
{
    int      choice, i;
    string   input;

    cout << "     - - - - - -  MENU - - - - - -\n\n";

    for (i = 0; i < n_opt; ++i)
        cout << "\t" << (i+1) << " - " << option[i] << endl;

    cout << "\n";
    cout << "     - - - - - - - - - - - - - - -\n";

    while (input.empty()) {
        cout << "     Enter number of choice > ";
        cin >> input;

        if (isdigit(input[0])) {
            choice = atoi(input.c_str());

            if (choice <= n_opt && choice > 0) {
                return choice;
            } else {          /* choice out of range */
                cout << "\tYour response MUST be between 1 and "
                     << n_opt << endl;
                input = "";
            }
        } else {                /* Non-numeric input, ignore */
            cout << "\tYour response MUST be a number!\n";
            input = "";
        }
    }

    return 1;
}          // end of menu()
