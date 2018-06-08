#ifndef STR_QUEUE_H
#define STR_QUEUE_H

void init_queue(int capacity);
void free_queue();
void enqueue(const char *str);
char *dequeue();
int queue_len();

#endif
