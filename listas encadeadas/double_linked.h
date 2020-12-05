struct s_node {
  int value;
  struct s_node* previous;
  struct s_node* next;
};

typedef struct s_node t_node;

struct s_dl_list {
  t_node* first;
  t_node* last;
  int size;
};

typedef struct s_dl_list t_dl_list;

void insert_head(t_dl_list*, int);
void insert_tail(t_dl_list*, int);
t_node* remove_head(t_dl_list*);
t_node* remove_head(t_dl_list*);
void delete_head(t_dl_list*);
void delete_head(t_dl_list*);
void show(t_dl_list*);

t_node* create_node(int);
t_dl_list* create_empty_list();
