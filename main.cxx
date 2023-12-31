#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;

/**
 * @brief This class represents a string as a singly linked list.
 */
class StringAsSinglyLinkedList {
private:
    /**
     * @brief This nested class represents a node in the linked list.
     */
    class Node {
        char data; /** The character that represents the data stored in the node. */
        Node * next; /** A pointer to the next node in the linked list. */
        /**
         * @brief A constructor that creates a new node with the given data and next pointer.
         * @param data The character that represents the data stored in the node.
         * @param next A pointer to the next node in the linked list.
         */
        Node(const char data, Node * next) : data(data), next(next) {}
        friend class StringAsSinglyLinkedList;
    };
    Node * head; /**< A pointer to the first node in the linked list. */
    Node * tail; /**< A pointer to the last node in the linked list. */

public:
    /**
     * @brief A constructor that creates a new instance of the StringAsSinglyLinkedList class with the given C-style string.
     * @param s The C-style string to initialize the linked list with. The string must be contain exactly one space character.
     */
    StringAsSinglyLinkedList(const char * s) : head(nullptr), tail(nullptr) {
        Node * node = nullptr;
        for (int i = strlen(s) - 1; i >= 0; i--) {
            node = new Node(s[i], node);
            if (i == 0) {
                tail = node;
            }
        }
        head = node;
    }

    /**
     * @brief A method that restructures the linked list by effectively swapping the first word and the second word in the list.
     * It does this by finding the first space character in the list, breaking the list at that point,
     * and then appending the first part of the list to the end of the second part.
     */
    void restructure() {
        Node * current_node = head;
        Node * end_of_the_first_word = nullptr;
        // Loop to find the end of the first word and the space character in the string.
        while(current_node) {
            if (current_node->data == ' ') {
                break;
            }
            end_of_the_first_word = current_node;
            current_node = current_node->next;
        }
        if (current_node) { // Check to make sure the string contains a space character.
            if (current_node->next) { // Check to make sure the string contains more than one word.
                Node * node_containing_space = current_node; // Create a node to store the node containing the space character.
                Node * temporary_node = head; // Create a temporary node to store the head.
                head = node_containing_space->next; // Make the head point to the beginning of the second word.
                tail = end_of_the_first_word; // Make the tail point to the end of the first word.
                end_of_the_first_word->next = nullptr; // Break the list at the end of the first word.
                current_node = head;
                // Loop to find the end of the second word.
                while(current_node->next) {
                    current_node = current_node->next;
                }
                current_node->next = node_containing_space; // Append the space character to the end of the second word.
                node_containing_space->next = temporary_node; // Append the first word to the end of the second word.
            }
        }
    }

    /**
     * @brief A method that displays the characters in the linked list in their original order.
     */
    void display() {
        Node * node = head;
        while(node) {
            cout << node->data;
            node = node->next;
        }
        cout << endl;
    }

    /**
     * @brief A destructor that frees the memory allocated for the linked list.
     */
    ~StringAsSinglyLinkedList() {
        while(head) {
            Node * node = head->next;
            delete head;
            head = node;
        }
    }
};

/**
 * @brief The main function creates an instance of the StringAsSinglyLinkedList class with the string "Srikanth Anantharam".
 * It then displays the original string and the restructured string by calling the display method before and after calling the restructure method, respectively.
 * @return 0 if the program exits successfully.
 */
int main()
{
    auto sasll = StringAsSinglyLinkedList("Srikanth Anantharam");
    sasll.display();
    sasll.restructure();
    sasll.display();

    return 0;
}
