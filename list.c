#include <stdio.h> // 標準入出力ライブラリをインクルード
#include <stdlib.h>

#define DATATYPE int

typedef struct listNode {
    DATATYPE data;
    struct listNode *next;
    struct listNode *prev;
} ListNode;

// 初期化
// アドレスを受け取り、参照することで関数から直接アクセスする
void init(ListNode *node) {
    node->next = NULL;
    node->prev = NULL;
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
    ListNode *now = node;
    while (now->next != NULL) {
        now = now->next;
    }
    ListNode *new;
    new = (ListNode *)malloc(sizeof(ListNode)); // メモリの動的確保（ListNode分のメモリを確保する）
    new->data = data;
    new->next = NULL;
    now->next = new;
    new->prev = now;
}

void insert(ListNode *node, DATATYPE data, int number) {
    // リストのnumber番目にノードを挿入する
    // プログラミングでは基本0から数え始める
    DATATYPE tmp;
    ListNode *now = node->next;
    if ( number >= 0 ) {
        for ( int i = 0; i <= number; i ++ ) {
            if ( now->next == NULL && number != i ) {
                break;
            } else if ( number == i ) {
                do {
                    tmp = now->data;
                    now->data = data;
                    data = tmp;
                    if ( now->next == NULL )
                        break;
                    now = now->next;
                } while ( 1 );
                break;
            }
            now = now->next;
        }
    } else if ( number < 0 ) {
        while ( now->next != NULL ) {
            now = now->next;
        }
        for ( int i = -1; i > number; i -- ) {
            if ( now->prev->prev == NULL ) 
                break;
            now = now->prev;
        }
        do {
            tmp = now->data;
            now->data = data;
            data = tmp;
            if ( now->next == NULL )
                break;
            now = now->next;
        } while ( 1 );
    }    
    ListNode *new;
    new = (ListNode *)malloc(sizeof(ListNode));
    new->data = data;
    new->next = NULL;
    new->prev = now;
    now->next = new;
}

DATATYPE pop(ListNode *node) {
    // リストの末尾のdataを取得して削除
    ListNode *now = node->next;
    while ( now->next->next != NULL ) {
        now = now->next;
    }
    DATATYPE tmp = now->next->data;
    now->next = NULL;
    return tmp;
}

DATATYPE dequeue(ListNode *node) {
    // リストの先頭のdataを取得して削除
    // 2番目を先頭にする
    ListNode *now = node->next;
    DATATYPE tmp = now->data;
    if( now->next != NULL ) {
        do {
            now->data = now->next->data;
            if ( now->next->next == NULL )
                break;
            now = now->next;
        } while ( 1 );
    } else {
        ListNode new;
        node->data = new.data;
    }
    now->next = NULL;
    return tmp;
}

DATATYPE delete(ListNode *node, int number) {
    // リストのnumber番目のdataを取得して削除
    // number+1番目をnumber-1番目のnextにつなぐ
    ListNode *now = node->next;
    ListNode new;
    DATATYPE tmp;
    if ( now->next == NULL ) {
        tmp = now->data;
        now->data = new.data;
    } else {
        for ( int i = 0; i < number; i ++ ) {
            if ( now->next->next == NULL && i + 1 == number ) {
                tmp = now->data;
                now->next = NULL;
                return tmp;
            }
            now = now->next;
        }
        tmp = now->data;
        while ( 1 ) {
            now->data = now->next->data;
            if ( now->next->next == NULL ) {
                now->next = NULL;
                break;
            }
            now = now->next;
        }
    }
    return tmp;
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