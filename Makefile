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
