#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    public:
    
        Queue(int capacity)
        {
            this->capacity = capacity;
            sequence = new int[capacity];
            head = tail = enqueued = 0;
        }

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


        bool fullQueue()
        {
            return enqueued == capacity;
        }


        bool emptyQueue()
        {
            return enqueued == 0;
        }


        void enqueue(int value)
        {
            if(fullQueue())
            {
                throw fullQueueEx();
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


        void dequeue()
        {
            if(emptyQueue())
            {
                throw emptyQueueEx();
            }

            sequence[head] = -1;

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
