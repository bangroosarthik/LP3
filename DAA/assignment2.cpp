#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    long long freq;
    Node *left, *right;
    
    Node(char data, long long freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

class Compare {
public:
    bool operator()(Node* l, Node* r) {
        if (l->freq == r->freq)
            return l->data > r->data;
        return l->freq > r->freq;
    }
};

class HuffmanCoding {
private:
    Node* root;
    map<char, string> codes;
    
    void generateCodes(Node* root, string str) {
        if (!root) return;
        //leaf
        if (!root->left && !root->right) {
            codes[root->data] = str;
            return;
        }
        //upto root
        generateCodes(root->left, str + "0");
        generateCodes(root->right, str + "1");
    }
    
public:
    void buildTree() {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        int n;
        cout << "Enter number of characters: ";
        cin >> n;
        
        for(int i = 0; i < n; i++) {
            char ch;
            int freq;
            cout << "Enter character and frequency: ";
            cin >> ch >> freq;
            minHeap.push(new Node(ch, freq));
        }
        
        while(minHeap.size() > 1) {
            Node* left = minHeap.top();
            minHeap.pop();
            
            Node* right = minHeap.top();
            minHeap.pop();
            
            Node* parent = new Node('$', left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            
            minHeap.push(parent);
        }
        
        root = minHeap.top();
        codes.clear();
        generateCodes(root, "");
    }
    
    void displayCodes() {
        cout << "\nHuffman Codes:" << endl;
        for(auto pair : codes) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
    
    string encode(string text) {
        string encoded = "";
        for(char c : text) {
            if(codes.find(c) != codes.end()) {
                encoded += codes[c];
            }
        }
        return encoded;
    }
    
    string decode(string encoded) {
        string decoded = "";
        Node* current = root;
        
        for(char bit : encoded) {
            if(bit == '0') 
                current = current->left;
            else 
                current = current->right;
                
            if(!current->left && !current->right) {
                decoded += current->data;
                current = root;
            }
        }
        return decoded;
    }
};

int main() {
    HuffmanCoding huffman;
    int choice;
    
    while(true) {
        cout << "\nHuffman Coding Menu\n";
        cout << "1. Build Huffman Tree\n";
        cout << "2. Display Codes\n";
        cout << "3. Encode Text\n";
        cout << "4. Decode Text\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                huffman.buildTree();
                break;
            }
            case 2: {
                huffman.displayCodes();
                break;
            }
            case 3: {
                string text;
                cout << "Enter text to encode: ";
                cin >> text;
                cout << "Encoded: " << huffman.encode(text) << endl;
                break;
            }
            case 4: {
                string encoded;
                cout << "Enter binary string to decode: ";
                cin >> encoded;
                cout << "Decoded: " << huffman.decode(encoded) << endl;
                break;
            }
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}