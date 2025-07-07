#include <stdio.h> // 標準入出力ライブラリをインクルード
#include <stdlib.h>

#define DATATYPE int

typedef struct listNode {
    DATATYPE data;
    struct listNode *next;
} ListNode;

// 初期化
// アドレスを受け取り、参照することで関数から直接アクセスする
void init(ListNode *node) {
    node->next = NULL;
}

// リストをすべて出力
void print(ListNode *node) {
    ListNode *now = node;
    // 次のノードがNULLになるまで出力
    printf("list: ");
    while (now != NULL) {
        printf("%d ", now->data);
        now = now->next;
    }
    printf("\n");
}

void append(ListNode *node, DATATYPE data) {
    // リストの末尾にノードを挿入する
    ListNode *now = node;

    while (now->next != NULL) {
        now = now->next;
    }
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    now->next = newNode;
}

void insert(ListNode *node, DATATYPE data, int number) {
    // リストのnumber番目にノードを挿入する
    // プログラミングでは基本0から数え始める
    ListNode *now = node;
    int i = 0;

    while (i < number && now->next != NULL) {
        now = now->next;
        i ++;
    }
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = now->next;
    now->next = newNode;
}

DATATYPE pop(ListNode *node) {
    // リストの末尾のdataを取得して削除
    ListNode *prev = NULL;
    ListNode *now = node;
    DATATYPE del_data;

    while (now->next != NULL) {
        prev = now;
        now = now->next;
    }
    prev->next = NULL;
    del_data = now->data;
    return del_data;
}

DATATYPE dequeue(ListNode *node) {
    // リストの先頭のdataを取得して削除
    // 2番目を先頭にする
    ListNode *first = node;
    DATATYPE del_data;

    first = node->next;
    del_data = first->data;
    node->next = first->next;
    return del_data;
}

DATATYPE delete(ListNode *node, int number) {
    // リストのnumber番目のdataを取得して削除
    // number+1番目をnumber-1番目のnextにつなぐ
    ListNode *prev = NULL;
    ListNode *now = node;
    DATATYPE del_data;
    int i = 0;

    while (i <= number && now != NULL) {
        prev = now;
        now = now->next;
        i ++;
    }
    del_data = now->data;
    prev->next = now->next;
    return del_data;
}

int main() {
    ListNode list;

    init(&list); // アドレスを渡す

    append(&list, 5); // (list: 5)
    append(&list, 3); // (list: 5 3)
    append(&list, 8); // (list: 5 3 8)

    insert(&list, 1, 1); // (list: 5 1 3 8)

    printf("delete(2): %d\n", delete(&list, 2)); // delete: 3

    printf("pop: %d\n", pop(&list)); // pop: 8

    printf("dequeue: %d\n", dequeue(&list)); // dequeue: 5

    print(&list); // list: 1
    
    return 0;
}