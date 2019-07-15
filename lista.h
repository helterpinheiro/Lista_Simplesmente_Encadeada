#ifndef LISTA_H_
#define LISTA_H_
#define TRUE 0
#define FALSE 1

typedef struct _slnode_{
	struct _slnode_*next;
	void *data;
}Slnode;

typedef struct _sllist_{
	Slnode *first;
	Slnode *cur;
}Sllist;

#ifdef LISTA_C_
	Sllist* sllCreate();
	void* sllFirst(Sllist *l);
	void* sllGetNext(Sllist *l);
	int sllDestroy(Sllist *l);
	int sllInsertFirst(Sllist *l, void *data);
	void *sllRemoveSpec(Sllist *l, void* key, int (*comp)(void*,void*));
	void *sllQuery(Sllist *l, void *key, int(*comp)(void*,void*));
	int sllInsertAfterSpec(Sllist *l, void *key, int(*comp)(void*,void*), void*data);
#else
	extern Sllist* sllCreate();
	extern void* sllFirst(Sllist *l);
	extern void* sllGetNext(Sllist *l);
	extern int sllDestroy(Sllist *l);
	extern int sllInsertFirst(Sllist *l, void *data);
	extern void *sllRemoveSpec(Sllist *l, void* key, int (*comp)(void*,void*));
	extern void *sllQuery(Sllist *l, void *key, int(*comp)(void*,void*));
	extern int sllInsertAfterSpec(Sllist *l, void *key, int(*comp)(void*,void*), void*data);
#endif //LISTA_C_

#endif //LISTA_H_
