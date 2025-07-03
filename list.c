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
int print(ListNode *node) {
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
    ListNode* new = malloc(sizeof(ListNode));
    new->data = data;
    new->next = NULL;

    while (node->next != NULL) {
        node = node->next;
    }

    node->next = new;
}

void insert(ListNode *node, DATATYPE data, int number) {
    // リストのnumber番目にノードを挿入する
    // プログラミングでは基本0から数え始める

    for (int i = 0; i < number; i++) {
        node = node->next;
    }

    ListNode* new = malloc(sizeof(ListNode));
    new->data = data;
    new->next = node->next;

    node->next = new;
}

DATATYPE pop(ListNode *node) {
    // リストの末尾のdataを取得して削除
    DATATYPE data;
    ListNode* prev;

    while (node->next != NULL) {
        prev = node;
        node = node->next;
    }

    data = node->data;
    prev->next = NULL;

    free(node);

    return data;
}

DATATYPE dequeue(ListNode *node) {
    // リストの先頭のdataを取得して削除
    // 2番目を先頭にする
    ListNode* first = node->next;
    DATATYPE data = first->data;
    node->next = first->next;

    free(first);

    return data;
}

DATATYPE delete(ListNode *node, int number) {
    // リストのnumber番目のdataを取得して削除
    // number+1番目をnumber-1番目のnextにつなぐ
    ListNode* prev;
    DATATYPE data;

    for (int i = 0; i < number + 1; i++) {
        prev = node;
        node = node->next;
    }

    data = node->data;
    prev->next = node->next;
    
    free(node);

    return data;
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