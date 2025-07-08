#include <stdio.h> // 標準入出力ライブラリをインクルード
#include <stdlib.h>

#define DATATYPE int //作業状態　とりあえず書いてみた　おそらく全然ちがう　ブランチは立ち上げ移動済み

typedef struct listNode {
    DATATYPE data;
    struct ListNode *next;
} ListNode;

// 初期化
// アドレスを受け取り、参照することで関数から直接アクセスする
void init(ListNode *node) {
    node->next = NULL;  //-> はアロー演算子　アドレスにいってさらにメンバにアクセスするのに便利
}

// リストをすべて出力

int print(ListNode *node) { //アドレスを受けとる処理?
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
    while (now->next != NULL) { //末尾をさがす(=NULLを探す)
        now = now->next; //先頭からアドレスを入れていくからどんどん奥のアドレスが入っていき末尾まで移動できる？
    }
    ListNode *new; //mallocはメモリの取得
    new = (ListNode *)malloc(sizeof(ListNode)); //-> はアロー演算子　アドレスにいってさらにメンバにアクセスするのに便利
    new->data = data; //メンバにデータを入れる　上の処理で末尾に移動済み
    new->next = NULL; //末尾にデータ入れたので新しい末尾を表すNULLを作成
    now->next = new; //新しくデータを追加
} 

    /**node = data;
    return *node;
}*/

void insert(ListNode *node, DATATYPE data, int number) {
    // リストのnumber番目にノードを挿入する
    // プログラミングでは基本0から数え始める

    
    ListNode *now = node; //指定した場所にデータを追加　上の処理がない追加した後が消える
    for(int i = 0;i < number /*&& 範囲外に出ないように*/ ;i++ ) { 
        now = now->next; //先頭からアドレスを入れていくからどんどん奥のアドレスが入っていきまで移動できる？
    }
    ListNode *new; 
    new = (ListNode *)malloc(sizeof(ListNode)); 
    new->data = data; //new(今作成した場所)にデータを入れる　上の処理で移動済み
    new->next = now -> next; //後続のデータもnewいれる //これがないと後続データをすてることになる
    now->next = new; //nweデータをnowに入れる(結合)

   // *node +number = data;
    
}

DATATYPE pop(ListNode *node) {
    // リストの末尾のdataを取得して削除

    //DATATYPE data
    ListNode *now = node;
    while (now->next != NULL) { //末尾をさがす(=NULLを探す)
        now = now->next; //先頭からアドレスを入れていくからどんどん奥のアドレスが入っていき末尾まで移動できる？
    }
    
    ListNode *syutoku = now -> data; //値取得   
    now -= 2; //値削除 アドレスを2つ遡ってNULLを入れて消している 毎回これでいけるのかは不明
    now->next = NULL; //これは後ろの要素は全部消えているはず

    return syutoku; //値を渡す
    
}

DATATYPE dequeue(ListNode *node) {
    // リストの先頭のdataを取得して削除
    // 2番目を先頭にする

    ListNode *now = node;
    now = now->next; //アドレスを1つ進む
    ListNode *syutoku = now -> data; //値取得 

    ListNode *hozon; //一時保存
    //now = now->next;
    hozon = now -> next;

    ListNode *new;
    new = (ListNode *)malloc(sizeof(ListNode)); 
    
    now = node; //1番最初のアドレスに戻る (アドレスを渡されているから当たり前ではある)

    new->next = NULL;
    //now->next = NULL;
    new->next = hozon; //後続のデータもnewいれる //これがないと後続データをすてることになる
    now->next = new -> next; //nweデータをnowに入れる(結合)

    return syutoku;

/*    ListNode *now = node;
    now = now->next;
    ListNode *syutoku = now -> data; //値取得 
    

    ListNode *hozon; //一時保存
    now = now->next;
    hozon = now -> next;
    //now  -= 5; 

    ListNode *new; 
    new = (ListNode *)malloc(sizeof(ListNode)); 
    //now -> next = NULL;
    new->next = hozon; //後続のデータもnewいれる //これがないと後続データをすてることになる
    now->next = new; //nweデータをnowに入れる(結合) 

    return syutoku; //値を渡す */
}

DATATYPE delete(ListNode *node, int number) {
    // リストのnumber番目のdataを取得して削除
    // number+1番目をnumber-1番目のnextにつなぐ

    ListNode *now = node;
    for(int i = 0;i < number /*&& 範囲外に出ないように*/ ;i++ ) { 
        now = now->next; //先頭からアドレスを入れていくからどんどん奥のアドレスが入っていきまで移動できる？
    }
    
    now = now->next; //アドレスを1つ進む
    ListNode *syutoku = now -> data; //値取得 

    ListNode *hozon; //一時保存
    //now = now->next;
    hozon = now -> next;

    ListNode *new;
    new = (ListNode *)malloc(sizeof(ListNode)); 
    
    new->next = NULL;
    
    now -= number - 6;
    now->next = NULL;
    new->next = hozon; //後続のデータもnewいれる //これがないと後続データをすてることになる
    now->next = new -> next; //nweデータをnowに入れる(結合)

    return syutoku;
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