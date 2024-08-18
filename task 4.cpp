#include <iostream>
#include <string>

class TextEditor {
private:
    std::string text;
    size_t cursorPosition;

public:
    TextEditor() : cursorPosition(0) {}

    void left() {
        if (cursorPosition > 0) {
            cursorPosition--;
        }
    }

    void right() {
        if (cursorPosition < text.length()) {
            cursorPosition++;
        }
    }

    void insert(char c) {
        text.insert(cursorPosition, 1, c);
        cursorPosition++;
    }

    void deleteChar() {
        if (cursorPosition < text.length()) {
            text.erase(cursorPosition, 1);
        }
    }

    void display() {
        std::cout << text << std::endl;
        for (size_t i = 0; i < cursorPosition; i++) {
            std::cout << " ";
        }
        std::cout << "^" << std::endl;
    }
};

int main() {
    TextEditor editor;
    editor.insert('H');
    editor.insert('e');
    editor.insert('l');
    editor.insert('l');
    editor.insert('o');
    editor.display();

    editor.left();
    editor.deleteChar();
    editor.display();

    editor.right();
    editor.insert('!');
    editor.display();

    return 0;
}
