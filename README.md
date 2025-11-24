# Warehouse Management System 

## Abstract

This project is a  **C-based Warehouse Management System** that uses file handling to store and manage item records. The system allows users to add, view, search, update, and delete inventory items using a binary data file.

---

## Features

### 1. **Add Item**

* Adds a new item to the warehouse.
* Stores details such as ID, name, quantity, and price.
* Saves data in `warehouse.dat`.

### 2. **Display Items**

* Shows all stored items in a tabular format.
* Reads from the binary file and displays: ID, Name, Quantity, Price.

### 3. **Search Item by ID**

* Searches the binary file for a specific item using its ID.
* Displays full details if found.

### 4. **Update Quantity**

* Allows modifying the quantity of an existing item.
* Locates the item in the file and updates its record.

### 5. **Delete Item**

* Deletes an item by ID.
* Copies remaining items into a temporary file and replaces the original.

### 6. **Exit**

* Closes the program.

---

##  How It Works

The program uses a `struct Item` to represent each inventory record:


struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};
```

Items are stored in a binary file (`warehouse.dat`) using the `fwrite()` and `fread()` functions.

The menu-driven interface allows continuous interaction until the user chooses to exit.

---

##  Running the Program

1. **Compile the code** using any C compiler (e.g., GCC):

```bash
gcc warehouse.c -o warehouse
```

2. **Run the executable:**

```bash
./warehouse
```

---

## Files Used

### **warehouse.dat**

* Stores all warehouse inventory records in binary form.

### **temp.dat**

* Temporary file used during record deletion.
  
--
 
## Output photos

 ### **Main Menue**

   <img width="293" height="160" alt="Screenshot 2025-11-21 201415" src="https://github.com/user-attachments/assets/d82c1aa6-6647-43ae-8cb4-6ba8ae638694" />

 ### **Add Item**

 <img width="242" height="131" alt="Screenshot 2025-11-21 202050" src="https://github.com/user-attachments/assets/74ae3dba-9fe5-4e52-85ce-d4bba4d99af2" />

 ### **Display Items**

 <img width="423" height="212" alt="Screenshot 2025-11-21 202544" src="https://github.com/user-attachments/assets/46705735-9e08-4edb-8aed-9a00ef248794" />

 ### **Search Item by ID**

 <img width="278" height="181" alt="Screenshot 2025-11-21 202228" src="https://github.com/user-attachments/assets/7f13078c-539e-4c48-9c46-f677f26f9c80" />

### ** Update Quantity**

<img width="390" height="116" alt="Screenshot 2025-11-21 202741" src="https://github.com/user-attachments/assets/0bb715f6-3fbe-4839-85aa-76be7ab198f0" />

### ** Delete Item**

<img width="319" height="81" alt="Screenshot 2025-11-21 202818" src="https://github.com/user-attachments/assets/24be019c-f6a2-4570-8b6e-a6adab3d35e3" />

Before

<img width="423" height="212" alt="Screenshot 2025-11-21 202544" src="https://github.com/user-attachments/assets/93e5dcfa-43ad-42bd-9b92-85e79f82db70" />

After

<img width="438" height="161" alt="Screenshot 2025-11-21 202839" src="https://github.com/user-attachments/assets/97b7d3f9-87c9-46c3-b871-312fd67da3c4" />









 
