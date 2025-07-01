#include <stdio.h>
#include <stdlib.h> // mallocとfreeのために必要

#define DATATYPE int

// ListNodeの型定義
typedef struct listNode {
    DATATYPE data;
    struct listNode *next;
} ListNode;

// 初期化
void init(ListNode *node) {
    node->next = NULL;
}

// リストをすべて出力
void print(ListNode *node) {
    ListNode *now = node->next;
    printf("list: ");
    while (now != NULL) {
        printf("%d ", now->data);
        now = now->next;
    }
    printf("\n");
}

// リストの末尾にノードを追加する
void append(ListNode *node, DATATYPE data) {
    ListNode *current = node;
    // リストの末尾まで移動
    while (current->next != NULL) {
        current = current->next;
    }
    // 新しいノードを作成
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        perror("malloc failed");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    // 新しいノードをリストに追加
    current->next = newNode;
}

// リストの指定した位置にノードを挿入する
void insert(ListNode *node, DATATYPE data, int number) {
    ListNode *current = node;
    // 指定した位置の直前まで移動
    for (int i = 0; i < number && current != NULL; i++) {
        current = current->next;
    }
    // numberがリストの範囲外の場合は何もしない
    if (current == NULL) {
        return;
    }
    // 新しいノードを作成
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        perror("malloc failed");
        return;
    }
    newNode->data = data;
    // 新しいノードを挿入
    newNode->next = current->next;
    current->next = newNode;
}

// リストの末尾の要素を取得して削除する
DATATYPE pop(ListNode *node) {
    // リストが空の場合
    if (node->next == NULL) {
        fprintf(stderr, "Error: Cannot pop from an empty list.\n");
        return -1; // エラー値
    }
    ListNode *current = node;
    // 末尾から2番目のノードまで移動
    while (current->next->next != NULL) {
        current = current->next;
    }
    // 末尾のノードを削除
    ListNode *lastNode = current->next;
    DATATYPE data = lastNode->data;
    current->next = NULL;
    free(lastNode);
    return data;
}

// リストの先頭の要素を取得して削除する
DATATYPE dequeue(ListNode *node) {
    if (node->next == NULL) {
        fprintf(stderr, "Error: Cannot dequeue from an empty list.\n");
        return -1; // エラー値
    }
    // 先頭のノードを削除
    ListNode *firstNode = node->next;
    DATATYPE data = firstNode->data;
    node->next = firstNode->next;
    free(firstNode);
    return data;
}

// リストの指定した位置の要素を取得して削除する
DATATYPE delete(ListNode *node, int number) {
    ListNode *current = node;
    // 指定した位置の直前まで移動
    for (int i = 0; i < number && current->next != NULL; i++) {
        current = current->next;
    }
    // 削除するノードが存在しない場合
    if (current->next == NULL) {
        fprintf(stderr, "Error: Deletion index out of bounds.\n");
        return -1; // エラー値
    }
    // ノードを削除
    ListNode *deleteNode = current->next;
    DATATYPE data = deleteNode->data;
    current->next = deleteNode->next;
    free(deleteNode);
    return data;
}

int main() {
    ListNode list;

    init(&list); // アドレスを渡す

    append(&list, 5); // (list: 5)
    append(&list, 3); // (list: 5 3)
    append(&list, 8); // (list: 5 3 8)

    //print(&list);// テスト

    insert(&list, 1, 1); // (list: 5 1 3 8)

    printf("delete(2): %d\n", delete(&list, 2)); // delete: 3
    
    printf("pop: %d\n", pop(&list)); // pop: 8

    printf("dequeue: %d\n", dequeue(&list)); // dequeue: 5
    
    print(&list); // list: 1
    
    return 0;
}
