/* This file contains the List class, a singly linked unordered
 * templated list class.  struct List_Link is the data structure for
 * the list links.
 *
 * Copyright (c) 1994, 2014 by Aaron Bloomfield
 * Released under a CC BY-SA license
 *
 * Revision history
 * 05-01-94: Main code written
 * 07-12-95: Bug updates
 * 01-13-14: Modified to fit modern C++ compilers; reformatted
 *
 * The tail of the list, in this implementation, is where the elements
 * are pushed (added) to and popped (removed) from.  For example:
 *
 * head <-- element <-- element <-- element <-- element <-- tail
 *
 *
 * Methods:
 *
 * List()                 Constructor, initilized an empty list
 * ~List()                Destructor, deletes the entire list
 * void push(T item);     Adds an item to the tail of the list
 * T* pop();              Removes an item from the tail of the list
 * int size();            Returns the size (length) of the list
 * void display();        Displays the list
 * int empty();           Returns 1 if the list is empty, 0 otherwise
 * void clear();          Clears (removes all elements from) the list
 * T* push_head();        Adds an item to the head of the list
 * T* tail();             Returns the tail data
 * T* head();             Returns the head data
 * int element (T item);  Returns 1 if T is in the list, 0 otherwise
 * pop_head (T item);     Removes an item from the head of the list
 * int remove (T item)    Removes item, returns 1 if sucessful, else 0
 * T* getptr (T item)     Returns the pointer to the parameter or NULL
 * void save(FILE *fp)    Saves the list- calls the objects methods
 *
 *
 * The List class requires <iostream> to be included, as it uses
 * cout's in the display method.
 *
 * In order to use the List class, the data type T must either be a
 * standard type, or be a class with the '==' operator overloaded.  To
 * use the display method, the data type must also have the '<<'
 * operator overloaded.  Examples follow, using a Complex class with
 * two attributes, real and imag (both ints).  The operator overloads
 * need to be functions outside the class declaration, and the
 * attributes used need to be public.
 *
 *      class Complex {
 *        public:
 *          int real, imag;
 *          Complex () { real = imag = 0; }
 *          Complex (int r, int i) { real = r; imag = i; }
 *          ~Complex () { }
 *          void set (int r, int i) { real = r; imag = i; }
 *      };
 *
 *      int operator == (Complex c1, Complex c2) {
 *        return ( (c1.real == c2.real) && (c1.imag == c2.imag) );
 *      }
 *
 *      int operator != (Complex c1, Complex c2) {
 *        return ( (c1.real != c2.real) || (c1.imag != c2.imag) );
 *      }
 *
 *      ostream& operator << (ostream& out, Complex c) {
 *        return (out << c.real << " + " << c.imag << "i");
 *      }
 *
 */

#include <iostream>
using namespace std;


template <class T>
struct List_Link {
    T *data;
    List_Link<T> *next;
};


template <class T>
class List {
    friend class Fsm;
    /*  head <-- element <-- element <-- element <-- element <-- tail       */
private:
    List_Link<T> *_head, *_tail;

public:
    List() {
        _head = _tail = NULL;
    } // cout << "List Constructor called.\n"; }

    ~List() {
        clear();
    }

    void push(T item) {
//    cout << "push(): called with element: " << item << endl;
        if ( _head == NULL ) {
            _head = _tail = new List_Link<T>;
            _head->next = NULL;
        } else {
            List_Link<T> *temp;
            temp = _tail;
            _tail = new List_Link<T>;
            _tail->next = temp;
        }
        _tail->data = new T;
        *_tail->data = item;
    }

    T* pop() {
        if ( _head == NULL )
            return NULL;
        else {
            List_Link<T> *temp;
            T *ret;
            temp = _tail;
            if ( _head == _tail )
                _tail = _head = NULL;
            else
                _tail = _tail->next;
            ret = temp->data;
            delete temp;
            return ret;
        }
    }

    int size() {
        if ( _tail == NULL )
            return 0;
        else {
            int s = 0;
            List_Link<T> *temp;
            for ( temp = _tail; temp != NULL; temp = temp->next )
                ++s;
            return s;
        }
    }

    void save(FILE *fp) {
        if ( _head == NULL ) {}
        else {
            List_Link<T> *temp;
            for ( temp = _tail; temp != NULL; temp = temp->next )
                temp->data->save(fp);
        }
    }

    void display() {
        if ( _head == NULL )
            cout << "List is empty.\n";
        else {
//      cout << "display(): List is printed reverse: List is not empty.\n\t";
            List_Link<T> *temp;
            for ( temp = _tail; temp != NULL; temp = temp->next )
                cout << *temp->data << " ";
            cout << endl;
        }
    }

    int empty() {
        return ( _head == NULL );
    }

    T* tail() {
        if ( _tail == NULL )
            return NULL;
        else
            return _tail->data;
    }

    T* head() {
        if ( _head == NULL )
            return NULL;
        else
            return _head->data;
    }

    int element (T item) {
        List_Link<T> *temp;
        if ( _tail == NULL )
            return 0;
        for ( temp = _tail; temp != NULL; temp = temp->next )
            if ( *temp->data == item )
                return 1;
        return 0;
    }

    T* getptr (T item) {
        List_Link<T> *temp;
        if ( _tail == NULL )
            return NULL;
        for ( temp = _tail; temp != NULL; temp = temp->next )
            if ( *temp->data == item )
                return temp->data;
        return NULL;
    }

    void clear() {
        while ( this->pop() != NULL ) { }
    }

    void push_head (T item) {
        if ( _head == NULL ) {
            _head = _tail = new List_Link<T>;
            _head->next = NULL;
        } else {
            List_Link<T> *temp;
            temp = _head;
            _head = new List_Link<T>;
            temp->next = _head;
            _head->next = NULL;
        }
        _head->data = new T;
        *_head->data = item;
    }

    T* pop_head() {
        if ( _head == NULL )
            return NULL;
        else {
            List_Link<T> *temp;
            T *ret;
            for ( temp = _tail; temp->next != _head; temp = temp->next ) { }
            ret = _head->data;
            _head = temp;
            temp = temp->next;
            delete temp;
            _head->next = NULL;
            return ret;
        }
    }

    int remove (T item) {
        if ( this->element(item) ) {
            cout << "remove(): element '" << item << "' exists.\n";
            if ( _head == _tail ) {
                delete _head;
                _head = _tail = NULL;
            } else if ( *_tail->data == item ) {
                List_Link<T> *temp;
                temp = _tail;
                _tail = _tail->next;
                delete temp;
            } else {
                List_Link<T> *temp, *temp2;
                for ( temp = _tail;
                        *temp->next->data != item;
                        temp = temp->next ) { }
                temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
            }
            return 1;
        } else {
            cout << "remove(): element '" << item << "' does not exist.\n";
            return 0;
        }
    }

};
