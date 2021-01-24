#ifndef QUEUE_H
#define QUEUE_H

#include <limits>
#include "FullQueueEx.h"
#include "EmptyQueueEx.h"

/**
*
* class Queue
*
* Meine Implementierung einer Warteschlange mit Funktionen zum Einreihen und Entfernen von Objekten mit dem Datentyp "int".
*
* @author LL
*
**/
class Queue
{
    public:
    
        /**
        *
        * Konstruktor mit Parameter.
        *
        * @param capacity: Übergibt die maximale Anzahl an Objekten die von dem Feld der Warteschlange gehalten werden können.
        *
        * Beschreibung: Allokiert Speicher für das Feld "sequence".
        *
        **/
        Queue(int capacity)
        {
            this->capacity = capacity;
            sequence = new int[capacity];
            head = tail = enqueued = 0;
        }

        /**
        *
        * Destruktor.
        *
        * Beschreibung: Gibt den von dem Feld "sequence" verwendeten Speicher wieder frei.
        *
        **/
        ~Queue()
        {
            delete[] sequence;
        }

    private:
    
        int *sequence;
        int head;
        int tail;
        int capacity;
        int enqueued;

        /**
        *
        * Methode.
        *
        * @param Keine Parameter.
        * @return (enqueued == capacity): Ausdruck zum Überprüfen, ob die Warteschlange voll ist (Anzahl der eingereihten Elemente entspricht der Anzahl der maximal einreihbaren Elemente).
        *
        * Beschreibung: Überprüft ob die Warteschlange voll ist.
        *
        **/
        bool fullQueue()
        {
            return enqueued == capacity;
        }

        /**
        *
        * Methode.
        *
        * @param Keine Parameter.
        * @return (enqueued == 0): Ausdruck zum Überprüfen, ob die Warteschlange leer ist (Anzahl der eingereihten Elemente entspricht der Zahl "0").
        *
        * Beschreibung: Überprüft ob die Warteschlange leer ist.
        *
        **/
        bool emptyQueue()
        {
            return enqueued == 0;
        }


        /**
        *
        * Methode.
        *
        * @param int value: Der Wert welcher der Warteschlange hinzugefügt werden soll.
        * @return Kein Rückgabewert.
        *
        * Beschreibung: Reiht ein Objekt vom Typ "int" in die Warteschlange ein.
        *
        * Wenn die Warteschlange voll ist wird eine Exception vom Typ fullQueueEx() geworfen.
        *
        * Wenn das letzte Element erreicht ist, wird das Element am Anfang des Feldes zum "tail".
        *
        **/
        void enqueue(int value)
        {
            if(fullQueue())
            {
                throw FullQueueEx();
            }
            
            sequence[tail] = value;

            enqueued++;

            if(tail == capacity-1)
            {
                tail = 0;
            }
            else
            {
                tail++;
            }
        }

        /**
        *
        * Methode.
        *
        * @param Keine Parameter.
        * @return Kein Rückgabewert.
        *
        * Beschreibung: Entfernt ein Objekt aus der Warteschlange.
        *
        * Wenn die Warteschlange leer ist wird eine Exception vom Typ emptyQueueEx() geworfen.
        *
        * Wenn das letzte Element erreicht ist, wird das Element am Anfang des Feldes zum "head".
        *
        **/
        void dequeue()
        {
            if(emptyQueue())
            {
                throw EmptyQueueEx();
            }

            sequence[head] = std::numeric_limits<int>::max();

            enqueued--;

            if(head == capacity-1)
            {
                head = 0;
            }
            else
            {
                head++;
            }
        }
};

#endif // QUEUE_H
