# Student_management_system_using_C


## 📘 `README.md` – Student Management System (C Project)

````markdown
# 🎓 Student Management System in C

A simple console-based application to manage student records using the C programming language. This project allows users to **Add**, **View**, **Search**, **Edit**, and **Delete** student data, with all information stored persistently using **binary file handling**.

---

## 📌 Features

- ✅ Add new student records
- 📋 View all student records
- 🔍 Search a student by Roll Number
- ✏️ Edit an existing student’s data
- ❌ Delete a student record
- 💾 File-based data storage (`students.dat`)

---

## 🧑‍💻 Tech Stack

- **Language**: C
- **IDE/Compiler**: GCC / Turbo C / Code::Blocks / Dev C++
- **Storage**: Binary file (`students.dat`)

---

## 🧱 Data Structure

```c
struct Student {
    int roll_no;
    char name[50];
    float marks;
};
````

---

## 📂 Project Structure

```
student_management.c        ← Main project file
students.dat                ← Binary file storing student records (auto-created)
README.md                   ← This file
```

---

## 🚀 How to Run

### 🔧 Compile

Using GCC:

```bash
gcc student_management.c -o student_management
```

### ▶️ Run

```bash
./student_management
```

Or use any C IDE and click **Run** after compiling.

---

## 📸 Sample Output

```
========== Student Management System ==========
1. Add Student
2. View All Students
3. Search Student
4. Edit Student
5. Delete Student
0. Exit
===============================================
Enter your choice: 1
Enter Roll No: 101
Enter Name: John Doe
Enter Marks: 89.5
Student added successfully!
```

---

## 🎯 Learning Outcomes

* Use of **`struct`** for custom data types
* Mastery of **file I/O in binary mode**
* Application of **menu-driven programming**
* Handling **CRUD operations**
* Real-world simulation in a command-line environment

---

## 📄 License

This project is open-source and free to use .

---

## 🙋‍♂️ Author

**Balaji A**
BE Computer Science and Engineering
Vel Tech Multi Tech Dr. Rangarajan Dr. Sakunthala Engineering College

---

```

---

Would you like this exported as a `.md` file or zipped along with the `.c` file? I can also help you write the documentation/report if needed for submission.
```
