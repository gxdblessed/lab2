#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {

    Node* front = nullptr;
    Node* back = nullptr;
    int size = 0;

    int count() {
        return size;
    }

    void queue(int value) {
        Node* node = new Node();
        node->data = value;
        node->next = nullptr;

        if (front == nullptr) { 
            front = node;
            back = front;
        }
        else { 
            back->next = node;
            back = node;
        }

        size++;
    }

    int unqueue() {
        if (size == 0) {
            return 0; 
        }

        Node* toDelete = front;
        int result = toDelete->data;
        front = front->next;

        delete toDelete;
        size--;

        if (size == 0) { 
            back = nullptr;
        }

        return result;
    }

    void clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
        back = nullptr;
    }

    int count(int value) {
        int count = 0;
        Node* current = front;

        while (current != nullptr) {
            if (current->data == value) {
                count++;
            }
            current = current->next;
        }

        return count;
    }

    void removeNegative() {
        Node* current = front;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data < 0) {
                if (prev == nullptr) { 
                    front = current->next;
                }
                else {
                    prev->next = current->next;
                }

                if (current == back) { 
                    back = prev;
                }

                Node* temp = current;
                current = current->next;
                delete temp;
                size--;
            }
            else {
                prev = current;
                current = current->next;
            }
        }
    }

    void insertBeforeNegative() {
        Node* current = front;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data < 0) {
                Node* newElem = new Node();
                newElem->data = 1;

                if (prev == nullptr) { 
                    newElem->next = front;
                    front = newElem;
                }
                else {
                    newElem->next = current;
                    prev->next = newElem;
                }

                size++;
            }

            prev = current;
            current = current->next;
        }
    }
};

int main() {
	setlocale(LC_ALL, "Rus");
    Queue queue;
    int choice;

    do {
        cout << "1. Добавить элемент в очередь\n";
        cout << "2. Извлечь элемент из очереди\n";
        cout << "3. Размер очереди\n";
        cout << "4. Очистить очередь\n";
        cout << "5. Подсчет количество элемента в очереди\n";
        cout << "6. Удаление отрицательных элементов из очереди\n";
        cout << "7. Вставка перед каждым отрицательным элементом числа 1\n";
        cout << "0. Завершение программы\n";
        cout << "Выберите функцию: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int num;
            cout << "Введите число: ";
            cin >> num;
            queue.queue(num);
            break;

        case 2:
            cout << "Удаленный элемент: " << queue.unqueue() << endl;
            break;

        case 3:
            cout << "Размер очереди: " << queue.count() << endl;
            break;

        case 4:
            queue.clear();
            cout << "Очередь очищена\n";
            break;

        case 5:
            int val;
            cout << "Введите число для подсчета: ";
            cin >> val;
            cout << "Количество: " << queue.count(val) << endl;
            break;

        case 6:
            queue.removeNegative();
            cout << "Отрицательные элементы удалены\n";
            break;

        case 7:
            queue.insertBeforeNegative();
            cout << "Вставлена 1 перед каждым отрицательным элементом\n";
            break;

        case 0:
            break;

        default:
            cout << "Неизвестная команда\n";
            break;
        }
    } while (choice != 0);

    return 0;
}