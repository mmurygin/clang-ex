INSERTION_ARGS=src/array.c src/insertion-sort.c -o bin/insertion
insertion:
	gcc $(INSERTION_ARGS)

insertion-debug:
	gcc -o0 -g3 $(INSERTION_ARGS)


MERGE_ARGS=src/array.c src/merge-sort.c -o bin/merge-sort
merge-sort:
	gcc $(MERGE_ARGS)

merge-sort-debug:
	gcc -o0 -g3 $(MERGE_ARGS)


QUICK_SORT_ARGS=src/array.c src/quick-sort.c -o bin/quick-sort
quick-sort:
	gcc $(QUICK_SORT_ARGS)

quick-sort-debug:
	gcc -o0 -g3 $(QUICK_SORT_ARGS)


TAIL_ARGS=src/tail.c src/str-queue.c -o bin/tail
tail:
	gcc $(TAIL_ARGS)

tail-debug:
	gcc -o0 -g3 $(TAIL_ARGS)


WC_ARGS=src/word-count.c -o bin/wc
word-count:
	gcc $(WC_ARGS)

word-count-debug:
	gcc -o0 -g3 $(WC_ARGS)

BTREE_ARGS=src/binary-tree.c src/test-binary-tree.c -o bin/btree
btree:
	gcc $(BTREE_ARGS)

btree-debug:
	gcc -o0 -g3 $(BTREE_ARGS)

WORDS_BTREE_ARGS=src/test-words-btree.c src/words-binary-tree.c -o bin/wc-btree
wc-btree:
	gcc $(WORDS_BTREE_ARGS)

wc-btree-debug:
	gcc -o0 -g3 $(WORDS_BTREE_ARGS)
