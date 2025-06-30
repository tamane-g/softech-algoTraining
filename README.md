# C言語プログラミング演習

`list.c` について、以下の関数を実装してください。

* append
* insert
* pop
* dequeue
* delete

実装したら、ブランチ名を自分の学籍番号としたブランチを作成し、コミットとプッシュを行ってください。

pop, dequeueの名前からわかるように、これらの関数のうち、insertやdeleteを用いないで、データ挿入にappend、データ取得にpop及びdequeueを用いることで、スタックやキューとして扱うことができます（pushとenqueueはappendと同一）。

```bash
$ git checkout -b （自分の学籍番号）
$ git add .
$ git commit -m "（適当なコメント）"
$ git push -u origin （自分の学籍番号）
```

## 応用課題

余裕があったら、双方向リストも実装してみてください。
前の要素へのポインタ変数の名前はprevが最適だと思います。

* **双方向リスト** : 前の要素への参照を持つリスト