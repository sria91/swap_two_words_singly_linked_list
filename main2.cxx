/**
 * @file main2.cxx
 * @brief A program that demonstrates the String class that can restructure a two word string by swapping their locations.
 */
#include <forward_list>
#include <iostream>
#include <string_view>

/**
 * @brief A class that represents a string as a singly linked list.
 */
struct String final {
    /**
     * @brief Constructs a String object from a string view.
     * @param sv The string view to construct the String object from.
     */
    String(std::string_view sv) : chars(sv.begin(), sv.end()) {}

    /**
     * @brief Restructures the string by swapping the first word and the second word.
     */
    void restructure()
    {
        auto it = chars.begin();
        if (it == chars.end()) return; // return if the string is empty

        for (auto prev = it++; it != chars.end(); ++it, ++prev) {
            if (*it == ' ') { // if we find a space
                // use splice_after to move the space to the beginning
                // the first argument to splice_after is the position to move the element to
                // the second argument is the list to move the element from
                // the third argument is the position of the element to move
                chars.splice_after(chars.before_begin(), chars, prev);

                // and then move the remaining chars to the beginning
                // the first argument to splice_after is the position to move the elements to
                // the second argument is the list to move the elements from
                // the third and fourth arguments are the range of elements to move
                chars.splice_after(chars.before_begin(), chars, prev, chars.end());
                return;
            }
        }
    }

    /**
     * @brief Outputs the string to an output stream.
     * @param os The output stream to output the string to.
     * @param s The String object to output.
     * @return The output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const String& s)
    {
        for (auto c : s.chars) os << c;
        return os;
    }

  private:
    std::forward_list<char> chars;
};

/**
 * @brief The main function that demonstrates the String class.
 * @return 0 on success.
 */
int main() {
    String name("Srikanth Anantharam");
    std::cout << name << std::endl;
    name.restructure();
    std::cout << name << std::endl;
}
