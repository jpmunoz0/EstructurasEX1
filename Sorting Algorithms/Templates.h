
#ifndef EXAMEN_1_ORDENAMIENTOS_TEMPLATES_H
#define EXAMEN_1_ORDENAMIENTOS_TEMPLATES_H

using namespace std;

template <typename T> struct Node
{
    Node<T> *next;
    T data;

    Node<T>(T _data)
    {
        this->next = nullptr;
        this->data = _data;
    }
};

template <typename T> struct Queue
{
    Node<T> *first, *last;

    Queue<T>()
    {
        this->first = this->last = nullptr;
    }

    bool isEmpty() { return this->first == nullptr; }

    void queue(T data)
    {
        if (this->isEmpty())
            this->last = this->first = new Node<T>(data);
        else
        {
            this->last->next = new Node<T>(data);
            this->last = this->last->next;
        }
    }

    Node<T> * dequeue()
    {
        Node<T> * borrado = first;
        if(!isEmpty()){
            first = first->next;
            borrado->next = nullptr;
        }
        return borrado;
    }

    void print()
    {
        Node<T> * temp = first;
        cout << " [ ";
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]\n";
    }
};

template <typename T> struct SimpleList
{
    Node<T> *first, *last;

    SimpleList<T>()
    {
        this->first = this->last = nullptr;
    }

    bool isEmpty() { return this->first == nullptr; }

    void insert(T data)
    {
        if (this->isEmpty())
            this->last = this->first = new Node<T>(data);
        else
        {
            this->last->next = new Node<T>(data);
            this->last = this->last->next;
        }
    }

    int size()
    {
        Node<T> * temp = this->first;
        int count = 0;
        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node<T> * getPosition(int position)
    {
        Node<T> * temp = this->first;
        if (position < this->size())
        {
            for (int i = 0; i < position; i++)
                temp = temp->next;
            return  temp;
        }
        return nullptr;
    }
};

#endif //EXAMEN_1_ORDENAMIENTOS_TEMPLATES_H
