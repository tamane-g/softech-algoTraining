#include <stdio.h> // 標準入出力ライブラリをインクルード

#define DATATYPE int

typedef struct listNode {
DATATYPE data;
ListNode *next;
} ListNode;

// 初期化
// アドレスを受け取り、参照することで関数から直接アクセスする
void init(ListNode *node) {
node->next = NULL;
}

// リストをすべて出力
int print(ListNode *node) {
    ListNode *now = node->next;
    ListNode *now = node;
// 次のノードがNULLになるまで出力
printf("list: ");
while (now != NULL) {
 -27,44 +27,53 
}
}

void append(ListNode *node, DATATYPE data) {
// リストの末尾にノードを挿入する
    ListNode *now = node;
    while (now->next != NULL) {
        now = now->next;
    }
    ListNode *new;
    new = (ListNode *)malloc(sizeof(List)); // メモリの動的確保（ListNode分のメモリを確保する）
    new->data = data;
    new->next = NULL;
    now->next = new;
}

void insert(ListNode *node, DATATYPE data, int number) {
// リストのnumber番目にノードを挿入する
// プログラミングでは基本0から数え始める
}

DATATYPE pop(ListNode *node) {
// リストの末尾のdataを取得して削除
}

DATATYPE dequeue(ListNode *node) {
// リストの先頭のdataを取得して削除
// 2番目を先頭にする
}

DATATYPE delete(ListNode *node, int number) {
// リストのnumber番目のdataを取得して削除
// number+1番目をnumber-1番目のnextにつなぐ
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
