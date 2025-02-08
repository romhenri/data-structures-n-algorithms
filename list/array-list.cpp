#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class ArrayList {
private:
    std::vector<int> array;
    int size;
    int maxSize = 100;

public:
    ArrayList(int maxSize = 100) {
        this->size = 0;
        this->maxSize = maxSize;
        array.reserve(maxSize);
    }

    bool is_empty() {
        return size == 0;
    }

    bool is_full() {
        return size == maxSize;
    }

    int get_size() {
        return size;
    }

    int get_max_size() {
        return maxSize;
    }

    int get_element(int pos) {
        if (pos > size + 1 || pos <= 0)
            throw std::out_of_range("Invalid position");
        return array[pos-1];
    }

    int get_pos(int element) {
        for (int i = 0; i < size; i++) {
            if (array[i] == element) {
                return i + 1;
            }
        }
        return -1;
    }

    void insert(int pos, int value) {
        if (is_full()) 
            throw std::overflow_error("List is full");
        if (pos > size + 1 || pos <= 0) 
            throw std::out_of_range("Invalid position");

        array[pos-1] = value;
        size++;
    }

    void set_element(int pos, int value) {
        if (pos > size || pos <= 0) 
            throw std::out_of_range("Invalid position");

        array[pos - 1] = value;
    }

    void remove(int pos) {
        if (is_empty()) 
            throw std::underflow_error("List is empty");
        if (pos > size || pos <= 0)  
            throw std::out_of_range("Invalid position");

        for (int i = pos - 1; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Cenário 1
    // Inserção e acesso de elementos
    ArrayList list(3);
    list.print();
    list.insert(1, 10);
    list.print();
    list.insert(2, 20);
    list.print();
    list.insert(3, 30);
    list.print();
    cout << "Acess pos 1: " << list.get_element(1) << endl;
    cout << "Acess value 20: " << list.get_pos(20) << endl;

    // Cenário 2
    // Inserção além do tamanho máximo
    // ArrayList list(2);
    // list.print();
    // list.insert(1, 10);
    // list.print();
    // list.insert(3, 30); // Erro

    // Cenário 3
    // Alteração de um elemento
    // ArrayList list(3);
    // list.insert(1, 10);
    // list.insert(2, 20);
    // list.insert(3, 30);
    // list.print();
    // list.set_element(2, 25);
    // list.print();

    // Cenário 4
    // Remoção de um elemento
    // ArrayList list(3);
    // list.insert(1, 10);
    // list.insert(2, 20);
    // list.insert(3, 30);
    // list.print();
    // list.remove(2);
    // list.print();

    return 0;
}
