# 🏋️ Gym Management System

<div align="center">

### 📚 [**View Learning Journey**](https://walaa86.github.io/gym-management-system/learning-journey/) | 💻 [**View on GitHub**](https://github.com/walaa86/gym-management-system)

*Educational documentation with step-by-step guides and tutorials*

---

</div>

A comprehensive C++ console application for managing gym members, built with file-based data storage.

## 📋 Features

### Core Functionality
- **Member Management**
  - Add new members with unique ID validation
  - View all members in formatted table
  - Update member information
  - Delete members with confirmation
  - Search for members by ID

### Data Validation
- Prevents duplicate member IDs
- Input validation for all fields
- Safe file operations with error handling

### User Interface
- Interactive menu system
- Formatted data display with proper alignment
- Clear navigation between operations
- Confirmation prompts for critical operations

## 🛠️ Technical Details

### Built With
- **Language:** C++ (C++17 standard)
- **Data Storage:** Text file (Members.txt)
- **Data Structure:** Vector-based in-memory storage
- **File Format:** Delimited text (#//#)

### Project Structure
```
GymManagementSystem/
├── GymProject.cpp       # Main source code
├── Members.txt          # Data storage file
└── README.md           # Project documentation
```

### Data Structure
```cpp
struct stMember {
    string MemberId;     // Unique identifier
    string Name;         // Member full name
    string Phone;        // Contact number
    int Age;            // Member age
    bool MarkForDelet;  // Deletion flag
};
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++17 support (g++, clang++, MSVC)
- Terminal/Console access

### Compilation

**On Linux/Mac:**
```bash
g++ -std=c++17 GymProject.cpp -o GymProject
./GymProject
```

**On Windows:**
```bash
g++ -std=c++17 GymProject.cpp -o GymProject.exe
GymProject.exe
```

### First Run
The program will automatically create `Members.txt` if it doesn't exist.

## 📖 How to Use

### Main Menu Options
```
[1] Show All Members    - Display all registered members
[2] Add New Member      - Register a new member
[3] Delete Member       - Remove a member from system
[4] Update Member       - Modify member information
[5] Search For Member   - Find member by ID
[6] Exit               - Close the application
```

### Adding a Member
1. Select option [2] from main menu
2. Enter unique Member ID
3. Enter member name
4. Enter phone number
5. Enter age
6. Member is saved automatically

### Updating a Member
1. Select option [4]
2. Enter Member ID to update
3. Confirm update operation
4. Enter new information
5. Changes are saved automatically

### Deleting a Member
1. Select option [3]
2. Enter Member ID to delete
3. Review member details
4. Confirm deletion
5. Member is removed from system

## 🎯 Key Learning Outcomes

This project demonstrates:
- File I/O operations in C++
- Vector manipulation and data structures
- String parsing and manipulation
- Input validation techniques
- Menu-driven program architecture
- Data persistence without databases
- Error handling and edge cases
- Code organization and modularity

## 🔒 Data Safety Features

- **Duplicate Prevention:** System checks for existing IDs before adding
- **Confirmation Dialogs:** Critical operations require user confirmation
- **Data Validation:** Input is validated before processing
- **Safe Deletion:** Marks records for deletion before removing from file
- **File Backup:** Original data preserved during updates

## 📊 Sample Output

```
======================================
            Main Menu
======================================
[1] Show All Members
[2] Add New Member
[3] Delete Member
[4] Update Member
[5] Search For Member
[6] Exit
======================================

                     Member List (3) Member(s).
-------------------------------------------------------------------------
| Member ID      | Member Name                   | Phone       | Age         
-------------------------------------------------------------------------
| M001          | John Doe                      | 555-1234    | 25          
| M002          | Jane Smith                    | 555-5678    | 30          
| M003          | Mike Johnson                  | 555-9012    | 28          
-------------------------------------------------------------------------
```

## 📚 Learning Journey

This project includes comprehensive educational documentation with step-by-step guides:

### 🌐 [**View Interactive Documentation**](https://walaa86.github.io/gym-management-system/learning-journey/)

The learning journey includes:
- **File Operations** - Deep dive into C++ file handling
- **Data Structures** - Understanding vectors and structs
- **Project Phases** - Step-by-step development guide
- **Feature Implementation** - Detailed tutorials for each feature
- **Code Examples** - Practical demonstrations

All documentation is available in both English and Arabic, with interactive examples and visual guides.

---

## 🔄 Future Enhancements

Potential features for expansion:
- [ ] Subscription management with expiry dates
- [ ] Attendance tracking system
- [ ] Payment records and financial reporting
- [ ] Trainer assignment system
- [ ] Workout plan management
- [ ] Member statistics and analytics
- [ ] Advanced search filters
- [ ] Data export to CSV/Excel

## 👨‍💻 Development

### Code Quality
- Clean and readable code structure
- Consistent naming conventions
- Proper function separation
- Commented for clarity
- Error handling implemented

### Testing Considerations
- Tested with various input types
- Edge cases handled (empty file, invalid input)
- Duplicate ID prevention verified
- File operations validated

## 📝 Notes

- Data is stored in plain text format for educational purposes
- Member IDs must be unique across the system
- File operations use append mode for efficient additions
- Screen clearing uses system-specific commands (clear/cls)

## 🤝 Contributing

This is an educational project. Suggestions for improvements are welcome!

## 📜 License

This project is created for educational purposes.

## 📧 Contact

Feel free to reach out for questions or suggestions about this project.

---

**Project Status:** ✅ Fully Functional  
**Last Updated:** November 2025  
**Version:** 1.0

---

### 🌟 Acknowledgments

Built as a practical implementation of:
- File handling in C++
- Data structures and algorithms
- Menu-driven program design
- Real-world application development

---

*This project demonstrates fundamental programming concepts and serves as a foundation for more complex system development.*
