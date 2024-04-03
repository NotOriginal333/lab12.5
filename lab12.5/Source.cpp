#include <iostream>
#include <fstream>
#include <string>

// Структура елементу стеку
struct Node {
    std::string data;
    Node* next;

    Node(const std::string& value) : data(value), next(nullptr) {}
};

// Додавання елементу до стеку
void push(Node*& top, const std::string& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

// Видалення верхнього елементу зі стеку
void pop(Node*& top) {
    if (top == nullptr) {
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

// Перегляд верхнього елементу стеку
std::string peek(Node* top) {
    if (top == nullptr) {
        return ""; // Повертаємо порожній рядок, якщо стек порожній
    }
    return top->data;
}

// Виведення стеку на екран
void printStack(Node* top) {
    std::cout << "Stack contents: ";
    while (top != nullptr) {
        std::cout << top->data << " ";
        top = top->next;
    }
    std::cout << std::endl;
}

// Створення стеку слів з текстового файлу
void createStackFromFile(const std::string& filename, Node*& top) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        push(top, word);
    }

    file.close();
}

// Обчислення довжини стеку
int stackLength(Node* top) {
    int length = 0;
    while (top != nullptr) {
        length++;
        top = top->next;
    }
    return length;
}

// Підрахунок кількості повторень слів у стеці
int countWordOccurrences(Node* top, const std::string& word) {
    int count = 0;
    while (top != nullptr) {
        if (top->data == word) {
            count++;
        }
        top = top->next;
    }
    return count;
}

// Знаходження найдовшого слова та його порядкового номера
std::pair<std::string, int> findLongestWord(Node* top) {
    std::string longestWord = "";
    int longestLength = 0;
    int position = 0;
    int currentPosition = 0;

    while (top != nullptr) {
        if (top->data.length() > longestLength) {
            longestWord = top->data;
            longestLength = top->data.length();
            position = currentPosition;
        }
        top = top->next;
        currentPosition++;
    }

    return std::make_pair(longestWord, position);
}

// Знаходження найкоротшого слова та його порядкового номера
std::pair<std::string, int> findShortestWord(Node* top) {
    std::string shortestWord = "";
    int shortestLength = INT_MAX;
    int position = 0;
    int currentPosition = 0;

    while (top != nullptr) {
        if (top->data.length() < shortestLength) {
            shortestWord = top->data;
            shortestLength = top->data.length();
            position = currentPosition;
        }
        top = top->next;
        currentPosition++;
    }

    return std::make_pair(shortestWord, position);
}

int main() {
    Node* top = nullptr;
    std::string filename = "words.txt"; 

    createStackFromFile(filename, top);

    printStack(top);

    std::cout << "Stack length: " << stackLength(top) << std::endl;

    std::cout << "Word occurrences:" << std::endl;
    std::string wordToCount = "apple"; 
    std::cout << wordToCount << ": " << countWordOccurrences(top, wordToCount) << std::endl;

    auto longestWordInfo = findLongestWord(top);
    std::cout << "Longest word: " << longestWordInfo.first << ", Position: " << longestWordInfo.second << std::endl;

    auto shortestWordInfo = findShortestWord(top);
    std::cout << "Shortest word: " << shortestWordInfo.first << ", Position: " << shortestWordInfo.second << std::endl;

    while (top != nullptr) {
        pop(top);
    }

    return 0;
}
