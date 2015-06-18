#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_LEVEL 10

typedef struct skiplistNode
{
	int value;
	struct skiplistNode* forward[];
}	skiplistNode;

typedef struct skiplist
{
	skiplistNode* header;
	int level;
}	skiplist;

skiplistNode* createNode(int level, int value)
{
	skiplistNode* sn = (skiplistNode*)malloc(sizeof(skiplistNode) + level * sizeof(skiplistNode*));
	sn->value = value;
	return sn;
}

skiplist* creatList()
{
	int j;
	skiplist* sl = (skiplist*) malloc(sizeof(skiplist));
	sl->level = 0;
	sl->header = createNode(MAX_LEVEL, 0);
	for (j = 0; j < MAX_LEVEL; j++){
		sl->header->forward[j] = NULL;
	}
	return sl;
}

int randomLevel()
{
	int k = 1;
	while (rand() % 2)
		k++;
	k = (k < MAX_LEVEL) ? k : MAX_LEVEL;
	return k;
}

int insertList(skiplist* sl, int value)
{
	skiplistNode* update[MAX_LEVEL];
	skiplistNode *cur, *next = NULL;
	cur = sl->header;
	int k = sl->level;
	int i;
	for (i = k - 1; i >=0; i--){
		while ((next = cur->forward[i]) && (next->value < value))
			cur = next;
		update[i] = cur;
	}
	if (next && next->value == value)
		return 0;
	k = randomLevel();
	if (k > (sl->level)){
		for (i = sl->level; i < k; i++)
			update[i] = sl->header;
		sl->level = k;
	}
	next = createNode(k, value);
	for (i = 0; i< k; i++){
		next->forward[i] = update[i]->forward[i];
		update[i]->forward[i] = next;
	}
	
	return 1;
}

int deleteList(skiplist* sl, int value){
	skiplistNode* update[MAX_LEVEL];
	skiplistNode *cur, *next = NULL;
	cur = sl->header;
	int k = sl->level;
	int i;
	for (i = k - 1; i >= 0; i--){
		while((next = cur->forward[i]) && (next->value < value))
			cur = next;
		update[i] = cur;
	}
	if (next && next->value == value){
		for (i = 0; i < k; i++){
			if (update[i]->forward[i] == next)
				update[i]->forward[i] = next->forward[i];
		}
		free(next);
		for (i = sl->level -1; i >=0; i--){
			if (sl->header->forward[i] == NULL)
				sl->level--;
		}
		return 1;
	}
	
	return 0;
}

int searchList(const skiplist* sl, int value)
{
	skiplistNode *cur, *next = NULL;
	cur = sl->header;
	int k = sl->level;
	int i;
	for (i = k -1; i >= 0; i--){
		while((next=cur->forward[i]) && (next->value <= value)){
			if (next->value == value)
				return 1;
			cur = next;
		}
	}
	return 0;
}

void printList(const skiplist* sl)
{
	skiplistNode *cur = sl->header;
	int k = sl->level;
	int i;
	for (i = k-1; i>=0; i--){
		cur = sl->header->forward[i];
		while(cur){
			printf("%d->", cur->value);
			cur = cur->forward[i];
		}
		printf("NULL\n");
	}
}

void destoryList(skiplist *sl)
{
	skiplistNode* cur, *next;
	int k = sl->level;
	int i;
	next = sl->header->forward[0];
	while(next){
		cur = next;
		next = cur->forward[0];
		free(cur);
	}
	sl->level = 0;
	free(sl);
}

int main()
{
	skiplist *sl = creatList();
	/*int choice, tmp;
	printf("------------\n\tenter your choice:\n\t1:add\n\t2:delete\n\t3:search\n\t0:stop\n--------\n");
	scanf("%d", &choice);
	while(choice){
		switch (choice){
			case 1:
				 printf("input add num\n");
     			 scanf("%d", &tmp);
        		 if (insertList(sl, tmp))
            		printf("add ok--------\n");
        		 else
            		printf("add failed------\n");
				break;
			case 2:
				 printf("input delete num\n");
     			 scanf("%d", &tmp);
        		 if (deleteList(sl, tmp))
            		printf("delete ok--------\n");
        		 else
            		printf("delete failed------\n");
				break;
			case 3:
				 printf("input search num\n");
     			 scanf("%d", &tmp);
        		 if (searchList(sl, tmp))
            		printf("search ok--------\n");
        		 else
            		printf("search failed------\n");
				break;
			default:
				break;
		}
		printf("------------\n\tenter your choice:\n\t1:add\n\t2:delete\n\t3:search\n\t0:stop\n--------\n");
		scanf("%d", &choice);
	}*/
	int i;
	/***test for insertList***/
	for(i = 0; i < 10; i++)
		assert(insertList(sl,i*2));
	printList(sl);
	assert(!insertList(sl,2));
	assert(!insertList(sl,4));
	assert(!insertList(sl,6));
	
	/***test for deleteList***/
	assert(deleteList(sl,2));
	assert(deleteList(sl,4));
	assert(!deleteList(sl,1));
	assert(!deleteList(sl,2));
	/***test for searchList***/
	assert(searchList(sl,0));
	assert(searchList(sl,6));
	assert(!searchList(sl,1));
	assert(!searchList(sl,3));
	assert(!searchList(sl,5));
	
	assert(deleteList(sl,6));
	assert(!searchList(sl,6));

	printList(sl);

	destoryList(sl);

	return 0;
}
