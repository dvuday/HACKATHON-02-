#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Todo {
    int id;
    char startDate[50];
    char endDate[50];
    char content[100];
    bool status;
};

struct Todo todoList[100];
int numberOfTodos = 2;

void displayMenu() {
    printf("************************MENU**************************\n");
    printf("1. In toan bo danh sach Todo co o trong mang todoList tren cung mot hang\n");
    printf("2. Thuc hien chuc nang them moi todo vao vi tri cuoi cung cua todoList\n");
    printf("3. Thuc hien chuc nang cap nhat thong tin cua mot todo\n");
    printf("4. Thuc hien chuc nang xoa mot todo\n");
    printf("5. Thuc hien chuc nang sap xep va in ra danh sach todoList da duoc sap xep\n");
    printf("*******************************************************\n");
}

void printTodoList() {
    printf("Danh sach Todo:\n");
    for (int i = 0; i < numberOfTodos; ++i) {
        printf("ID: %d, Noi dung: %s, Trang thai: %s\n", todoList[i].id, todoList[i].content,
               todoList[i].status ? "Hoan thanh" : "Chua hoan thanh");
    }
}

void addTodo() {
    struct Todo newTodo;
    printf("Nhap thong tin cho Todo moi:\n");
    printf("Noi dung: ");
    scanf("%s", newTodo.content);
    newTodo.id = ++numberOfTodos;
    newTodo.status = false;

    todoList[numberOfTodos - 1] = newTodo;
    printf("Todo moi da duoc them.\n");
}

void updateTodo() {
    char searchContent[100];
    printf("Nhap noi dung cua Todo can cap nhat: ");
    scanf("%s", searchContent);

    int foundIndex = -1;
    for (int i = 0; i < numberOfTodos; ++i) {
        if (strcmp(todoList[i].content, searchContent) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Nhap thong tin moi cho Todo:\n");
        printf("Noi dung: ");
        scanf("%s", todoList[foundIndex].content);
        printf("Thong tin Todo da duoc cap nhat.\n");
    } else {
        printf("Khong tim thay Todo can cap nhat.\n");
    }
}

void deleteTodo() {
    char searchContent[100];
    printf("Nhap noi dung cua Todo can xoa: ");
    scanf("%s", searchContent);

    int foundIndex = -1;
    for (int i = 0; i < numberOfTodos; ++i) {
        if (strcmp(todoList[i].content, searchContent) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < numberOfTodos - 1; ++i) {
            todoList[i] = todoList[i + 1];
        }
        --numberOfTodos;
        printf("Todo da duoc xoa.\n");
    } else {
        printf("Khong tim thay Todo can xoa.\n");
    }
}

void sortTodoList() {
    for (int i = 0; i < numberOfTodos - 1; ++i) {
        for (int j = i + 1; j < numberOfTodos; ++j) {
            if (strcmp(todoList[i].content, todoList[j].content) > 0) {
                struct Todo temp = todoList[i];
                todoList[i] = todoList[j];
                todoList[j] = temp;
            }
        }
    }
printf("Danh sach Todo da duoc sap xep theo noi dung.\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Nhap lua chon cua ban (1-5, 0 de thoat): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printTodoList();
                break;
            case 2:
                addTodo();
                break;
            case 3:
                updateTodo();
                break;
            case 4:
                deleteTodo();
                break;
            case 5:
                sortTodoList();
                printTodoList();
                break;
            case 0:
                printf("Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
