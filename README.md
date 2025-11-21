# Warehouse Management System 

Abstract

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

 
