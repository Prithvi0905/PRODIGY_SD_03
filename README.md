# PRODIGY_SD_03
Contact Manager (C++)

Overview

This is a console-based Contact Manager application written in C++. It allows users to manage their personal contacts by adding, viewing, editing, and deleting contact entries. Contacts are saved persistently to a text file, so data is retained between program runs.

Features

- Add new contacts with Name, Phone, and Email.
- View a list of all saved contacts.
- Edit existing contacts, with option to update any field.
- Delete contacts by selecting from the list.
- Persistent storage: contacts are loaded from and saved to a text file (contacts.txt).
- Input validation for required fields.
- User-friendly menu-driven interface.

How It Works

- On startup, the program reads existing contacts from contacts.txt into memory.
- The user interacts with a simple menu to manage contacts.
- All changes (add, edit, delete) are saved back to the file upon exit.
- Contacts are stored in CSV format inside the file: each line contains name,phone,email.

Code Structure

- Contact struct: represents an individual contact and handles CSV serialization/deserialization.
- ContactManager class: maintains the list of contacts, handles file I/O, and provides methods for add/edit/delete/list operations.
- main function: instantiates ContactManager and starts the user interaction loop.

Usage

Run the program and choose from the menu options:

1. List Contacts — displays all saved contacts.
2. Add Contact — prompts for contact details and adds a new entry.
3. Edit Contact — lets you update fields of an existing contact.
4. Delete Contact — removes a contact by number.
5. Exit — saves all changes and closes the program.

Example

Contact Manager
1. List Contacts
2. Add Contact
3. Edit Contact
4. Delete Contact
5. Exit
Choose an option: 2

Enter name: John Doe
Enter phone: 123-456-7890
Enter email: john@gmail.com
Contact added.

Choose an option: 1
1. John Doe | 123-456-7890 | john@gmail.com

Notes

- All fields are required when adding a new contact.
- When editing, leaving a field blank keeps the current value.
- The data file contacts.txt is created in the program’s working directory.
- Designed for command-line use with simple text input/output.
