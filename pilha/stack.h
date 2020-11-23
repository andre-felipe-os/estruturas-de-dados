struct s_container {
  int value;
  struct s_container *next;
};

typedef struct s_container t_container;

struct s_stack {
  int containers_quantity;
  t_container *top_container;
};

typedef struct s_stack t_stack;

void stack(t_stack*, t_container*);
t_container* unstack(t_stack*);

t_container* create_container(int);
t_stack* create_empty_stack();
void delete_empty_stack(t_stack*);
