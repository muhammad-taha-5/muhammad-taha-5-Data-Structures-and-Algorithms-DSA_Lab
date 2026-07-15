#include<iostream>
using namespace std;

class TextEditor {
private:
    string text;

    string undoStack[100];
    int undoTop;

    string redoStack[100];
    int redoTop;

public:
    TextEditor() {
        text = "";
        undoTop = -1;
        redoTop = -1;
    }

    // Type character
    void typeChar(char ch) {
        undoStack[++undoTop] = text;  // save state
        text += ch;

        redoTop = -1; // clear redo
    }

    // Delete last character
    void deleteChar() {
        if (text == "") {
            cout << "Nothing to delete\n";
            return;
        }

        undoStack[++undoTop] = text;
        text.pop_back();

        redoTop = -1;
    }

    // Undo
    void undo() {
        if (undoTop == -1) {
            cout << "Nothing to undo\n";
            return;
        }

        redoStack[++redoTop] = text;
        text = undoStack[undoTop--];
    }

    // Redo
    void redo() {
        if (redoTop == -1) {
            cout << "Nothing to redo\n";
            return;
        }

        undoStack[++undoTop] = text;
        text = redoStack[redoTop--];
    }

    void display() {
        cout << "Current Text: " << text << endl;
    }
};


int main() {

    TextEditor editor;

    int choice;
    char ch;

    do {
        cout << "\n===== TEXT EDITOR =====\n";
        cout << "1. Type Character\n";
        cout << "2. Delete Character\n";
        cout << "3. Undo\n";
        cout << "4. Redo\n";
        cout << "5. Display Text\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter character: ";
            cin >> ch;
            editor.typeChar(ch);
            break;

        case 2:
            editor.deleteChar();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}