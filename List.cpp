#include <iostream>
#include "List.h"
/**
*
* Konstruktor.
*
* Beschreibung:
* Initialisiert "head" und "tail" als nullptr.
*
**/
List::List()
{
    head = tail = nullptr;
}
/**
*
* Destruktor.
*
* Beschreibung:
* Gibt den von den Elementen (Typ "Node") reservierten Speicher frei.
*
**/
List::~List()
{
    remove_all();
}
/**
*
* Methode.
*
* @param value: Wert nachdem in der Liste gesucht werden soll.
* @return check: Boolean der nur "true" ist, wenn die Liste ein Element mit dem übergebenen Wert "append" hält.
*
*
* Beschreibung:
* Läuft über die Liste vom Anfang bis zum Ende und überprüft, ob der übergebene Wert in der Liste enthalten ist.
* Gibt "true" zurück wenn der Wert in der Liste enthalten ist.
*
**/
bool List::contains(int value)
{
    bool check = false;
    Node *temp = head;

    while(temp != nullptr)
    {
	    if(append == temp->data)
	    {
	    	check = true;
	    }
	    temp = temp->next;
    }

    return check;
}
/**
*
* Methode.
*
* @param append: Wert der am Ende der Liste angehangen werden soll.
* @return Kein Rückgabewert.
*
* Beschreibung:
* Wenn die Liste leer ist wird ein Element erstellt, welches weder Vor- noch Nachgänger besitzt.
* Ansonsten wird ein Element am Ende der Liste hinzugefügt..
*
**/
void List::add_last(int append)
{
    if(head == nullptr)
    {
    Node* any = new Node();

    any->data = append;
    any->next = nullptr;
    any->before = nullptr;
    head = any;
    tail = any;
    }
    else
    {
    Node *any = new Node();

    any->data = append;
    tail->next = any;
    any->before = tail;
    any->next = nullptr;

    tail = any;
    }
}
/**
*
* Methode.
*
* @param append: Wert der am Ende der Liste angehangen werden soll.
* @return Kein Rückgabewert.
*
* Beschreibung:
* Wenn die Liste leer ist wird ein Element erstellt, welches weder Vor- noch Nachgänger besitzt.
* Ansonsten wird ein Element am Anfang der Liste hinzugefügt..
*
**/
void List::add_first(int append) {

    if(head == nullptr)
	{
        Node* any = new Node();

        any->data = append;
        any->next = nullptr;
        any->before = nullptr;
        head = any;
        tail = any;
    }
    else
    {
        Node *any = new Node();

        any->data = append;
        head->before = any;
        any->next = head;
        any->before = nullptr;

        head = any;
    }
}
/**
*
* Methode.
*
* @param Keine Parameter.
* @return Kein Rückgabewert.
*
* Beschreibung:
* Wenn die Liste leer ist wird eine Exception vom Typ "EmptyListEx" geworfen.
* Ansonten wird das Element am Ende der Liste entfernt.
*
**/
void List::remove_last()
{
    if(head == nullptr)
    {
        throw EmptyListEx();
    }

    Node *temp = tail;

    temp = temp->before;
    temp->next = nullptr;

    delete tail;

    tail = temp;
}
/**
*
* Methode.
*
* @param Keine Parameter.
* @return Kein Rückgabewert.
*
* Beschreibung:
* Wenn die Liste leer ist wird eine Exception vom Typ "EmptyListEx" geworfen.
* Ansonten wird das Element am Anfang der Liste entfernt.
*
**/
void List::remove_first()
{
    if(head == nullptr)
    {
        throw EmptyListEx();
    }

    Node *temp = head;

    temp = temp->next;

    temp->before = nullptr;

    delete head;

    head = temp;
}
/**
*
* Methode.
*
* @param Keine Parameter.
* @return Kein Rückgabewert.
*
* Beschreibung:
* Jedes Element der Liste wird entfernt.
*
**/
void List::remove_all()
{
    Node *temp = head;

    while(head != nullptr)
    {
        temp = temp->next;

        delete head;

        head = temp;
    }
    tail = nullptr;
}
