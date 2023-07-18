#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<string, Node*> children;
    Node* parent;  // Added parent pointer
};

class FileSystem {
private:
    Node* root;
    Node* currentDirectory;

public:
    FileSystem() {
        root = new Node();
        root->parent = nullptr; 
        currentDirectory = root;
    }

    void executeCommand(const string& command) {
        string cmd, arg;
        size_t spacePos = command.find(' ');

        if (spacePos != string::npos) {
            cmd = command.substr(0, spacePos);
            arg = command.substr(spacePos + 1);
        } else {
            cmd = command;
        }

        if (cmd == "pwd") {
            printCurrentDirectoryPath();
        } else if (cmd == "mkdir") {
            createDirectory(arg);
        } else if (cmd == "cd") {
            changeDirectory(arg);
        }
    }

private:
    void printCurrentDirectoryPath() {
        Node* node = currentDirectory;
        string path = "";

        while (node != root) {
            for (const auto& pair : node->parent->children) {
                if (pair.second == node) {
                    path = "/" + pair.first + path;
                    break;
                }
            }
            node = node->parent;
        }

        cout << path << endl;
    }

    void createDirectory(const string& directoryName) {
        Node* newNode = new Node();
        newNode->parent = currentDirectory;
        currentDirectory->children[directoryName] = newNode;
    }

    void changeDirectory(const string& directoryName) {
        if (directoryName == "..") {
            if (currentDirectory != root) {
                currentDirectory = currentDirectory->parent;
            }
        } else if (currentDirectory->children.count(directoryName) > 0) {
            currentDirectory = currentDirectory->children[directoryName];
        }
    }
};

int main() {
    FileSystem fs;

    fs.executeCommand("pwd");
    fs.executeCommand("mkdir abc");
    fs.executeCommand("cd abc");
    fs.executeCommand("pwd");
    fs.executeCommand("cd ..");
    fs.executeCommand("pwd");

    return 0;
}