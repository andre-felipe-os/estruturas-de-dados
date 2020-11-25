struct s_container {
  int value;
  struct s_container *next;
};

typedef struct s_container t_container;

struct s_queue {
  int containers_quantity;
  t_container *first_container;
  t_container *last_container;
};

typedef struct s_queue t_queue;

void append(t_queue*, t_container*);
t_container* get_next(t_queue*);

t_container* create_container(int);
t_queue* create_empty_queue();
void delete_empty_queue(t_queue*);
