#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;

    std::string toString() const {
        return name + " | " + phone + " | " + email;
    }

    std::string toFileString() const {
        return name + "," + phone + "," + email;
    }

    static Contact fromFileString(const std::string& line) {
        std::stringstream ss(line);
        std::string name, phone, email;

        std::getline(ss, name, ',');
        std::getline(ss, phone, ',');
        std::getline(ss, email, ',');

        return Contact{ name, phone, email };
    }
};

class ContactManager {
    std::vector<Contact> contacts;
    const std::string filename = "contacts.txt";

public:
    ContactManager() {
        loadContacts();
    }

    ~ContactManager() {
        saveContacts();
    }

    void loadContacts() {
        std::ifstream file(filename);
        if (!file.is_open()) return;

        std::string line;
        while (std::getline(file, line)) {
            if (!line.empty()) {
                contacts.push_back(Contact::fromFileString(line));
            }
        }
        file.close();
    }

    void saveContacts() {
        std::ofstream file(filename);
        for (const auto& contact : contacts) {
            file << contact.toFileString() << "\n";
        }
        file.close();
    }

    void addContact() {
        Contact c;
        std::cout << "Enter name: ";
        std::getline(std::cin, c.name);
        std::cout << "Enter phone: ";
        std::getline(std::cin, c.phone);
        std::cout << "Enter email: ";
        std::getline(std::cin, c.email);

        if (c.name.empty() || c.phone.empty() || c.email.empty()) {
            std::cout << "All fields are required.\n";
            return;
        }
        contacts.push_back(c);
        std::cout << "Contact added.\n";
    }

    void listContacts() const {
        if (contacts.empty()) {
            std::cout << "No contacts available.\n";
            return;
        }
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". " << contacts[i].toString() << "\n";
        }
    }

    void editContact() {
        listContacts();
        if (contacts.empty()) return;

        std::cout << "Enter contact number to edit: ";
        size_t index;
        std::cin >> index;
        std::cin.ignore(); // clear newline from input buffer
        if (index < 1 || index > contacts.size()) {
            std::cout << "Invalid index.\n";
            return;
        }
        Contact& c = contacts[index - 1];

        std::cout << "Editing contact: " << c.toString() << "\n";
        std::cout << "Enter new name (leave blank to keep current): ";
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty()) c.name = input;

        std::cout << "Enter new phone (leave blank to keep current): ";
        std::getline(std::cin, input);
        if (!input.empty()) c.phone = input;

        std::cout << "Enter new email (leave blank to keep current): ";
        std::getline(std::cin, input);
        if (!input.empty()) c.email = input;

        std::cout << "Contact updated.\n";
    }

    void deleteContact() {
        listContacts();
        if (contacts.empty()) return;

        std::cout << "Enter contact number to delete: ";
        size_t index;
        std::cin >> index;
        std::cin.ignore();
        if (index < 1 || index > contacts.size()) {
            std::cout << "Invalid index.\n";
            return;
        }
        contacts.erase(contacts.begin() + index - 1);
        std::cout << "Contact deleted.\n";
    }

    void run() {
        while (true) {
            std::cout << "\nContact Manager\n";
            std::cout << "1. List Contacts\n";
            std::cout << "2. Add Contact\n";
            std::cout << "3. Edit Contact\n";
            std::cout << "4. Delete Contact\n";
            std::cout << "5. Exit\n";
            std::cout << "Choose an option: ";

            int choice;
            std::cin >> choice;
            std::cin.ignore(); // ignore leftover newline

            switch (choice) {
            case 1: listContacts(); break;
            case 2: addContact(); break;
            case 3: editContact(); break;
            case 4: deleteContact(); break;
            case 5:
                saveContacts();
                std::cout << "Goodbye!\n";
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
            }
        }
    }
};

int main() {
    ContactManager cm;
    cm.run();
    return 0;
}
