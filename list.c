#include <stdio.h> // 標準入出力ライブラリをインクルード
#include <stdlib.h> // メモリ管理のためにstdlib.hライブラリをインクルード

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
    ListNode *now = node->next;
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
    ListNode *new, *now = node;
    
    while (now->next != NULL) {
        now = now->next;
    }
    new = (ListNode *)malloc(sizeof(ListNode)); // メモリの動的確保（ListNode分のメモリを確保する）
    new->data = data;
    new->next = NULL;
    now->next = new;
}

void insert(ListNode *node, DATATYPE data, int number) {
    // リストのnumber番目にノードを挿入する
    // プログラミングでは基本0から数え始める
    ListNode *new, *now = node;
    
    for (int i = 0; i < number && now != NULL; i++)
        now = now->next;
    
    new = (ListNode *)malloc(sizeof(ListNode));
    new->next = now->next;
    new->data = data;
    now->next = new;
}

DATATYPE pop(ListNode *node) {
    // リストの末尾のdataを取得して削除
    ListNode *prev, *now = node;
    DATATYPE buf;
    
    while (now->next != NULL) {
        prev = now;
        now = now->next;
    }
    
    buf = now->data;
    free(prev->next);
    prev->next = NULL;
    
    return buf;
}

DATATYPE dequeue(ListNode *node) {
    // リストの先頭のdataを取得して削除
    // 2番目を先頭にする
    DATATYPE buf = node->next->data;
    ListNode *prev, *now = node->next;
    
    while (now->next != NULL) {
        now->data = now->next->data;
        prev = now;
        now = now->next;
    }
    
    free(prev->next);
    prev->next = NULL;
    
    return buf;
}

DATATYPE delete(ListNode *node, int number) {
    // リストのnumber番目のdataを取得して削除
    // number+1番目をnumber-1番目のnextにつなぐ
    DATATYPE buf;
    ListNode *prev, *now = node->next;
    
    for (int i = 0; i < number && now != NULL; i++) {
        prev = now;
        now = now->next;
    }
    
    buf = now->data;
    now = now->next;
    free(prev->next);
    prev->next = now;
    
    return buf;
}

int main() {
    ListNode list;

    init(&list); // アドレスを渡す

    append(&list, 5); // (list: 5)
    append(&list, 3); // (list: 5 3)
    append(&list, 8); // (list: 5 3 8)

    insert(&list, 1, 1); // (list: 5 1 3 8)
    
    print(&list);

    printf("delete(2): %d\n", delete(&list, 2)); // delete: 3
    
    printf("pop: %d\n", pop(&list)); // pop: 8

    printf("dequeue: %d\n", dequeue(&list)); // dequeue: 5
    
    print(&list); // list: 1
    
    return 0;
}