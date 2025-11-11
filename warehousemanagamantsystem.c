 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addItem();
void displayItems();
void searchItem();
void updateQuantity();
void deleteItem();

int main() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Quantity\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: displayItems(); break;
            case 3: searchItem(); break;
            case 4: updateQuantity(); break;
            case 5: deleteItem(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void addItem() {
    FILE *fp = fopen("warehouse.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    struct Item newItem;
    printf("Enter Item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter Item Name: ");
    scanf("%s", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);

    fwrite(&newItem, sizeof(struct Item), 1, fp);
    fclose(fp);
    printf("Item added successfully!\n");
}

void displayItems() {
    FILE *fp = fopen("warehouse.dat", "rb");
    if (fp == NULL) {
        printf("No inventory records found.\n");
        return;
    }
    struct Item item;
    printf("\nID\tName\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    while (fread(&item, sizeof(struct Item), 1, fp)) {
        printf("%d\t%s\t%d\t\t%.2f\n", item.id, item.name, item.quantity, item.price);
    }
    fclose(fp);
}

void searchItem() {
    int id, found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &id);
    FILE *fp = fopen("warehouse.dat", "rb");
    if (fp == NULL) {
        printf("No inventory records found.\n");
        return;
    }
    struct Item item;
    while (fread(&item, sizeof(struct Item), 1, fp)) {
        if (item.id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", item.id, item.name, item.quantity, item.price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
    fclose(fp);
}

void updateQuantity() {
    int id, found = 0, newQty;
    printf("Enter Item ID to update quantity: ");
    scanf("%d", &id);
    FILE *fp = fopen("warehouse.dat", "rb+");
    if (fp == NULL) {
        printf("No inventory records found.\n");
        return;
    }
    struct Item item;
    while (fread(&item, sizeof(struct Item), 1, fp)) {
        if (item.id == id) {
            printf("Current quantity: %d\n", item.quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQty);
            item.quantity = newQty;
            fseek(fp, -sizeof(struct Item), SEEK_CUR);
            fwrite(&item, sizeof(struct Item), 1, fp);
            found = 1;
            printf("Quantity updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Item not found!\n");
    }
    fclose(fp);
}

void deleteItem() {
    int id, found = 0;
    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    FILE *fp = fopen("warehouse.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file\n");
        return;
    }

    struct Item item;
    while (fread(&item, sizeof(struct Item), 1, fp)) {
        if (item.id == id) {
            found = 1; // Skip this item to delete it
            continue;
        }
        fwrite(&item, sizeof(struct Item), 1, temp);
    }
    fclose(fp);
    fclose(temp);

    if (found) {
        remove("warehouse.dat");
        rename("temp.dat", "warehouse.dat");
        printf("Item deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Item not found!\n");
    }
}
