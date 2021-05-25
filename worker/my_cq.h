/****************************\
 * (h) - head               *
 * (e) - element            *
 * (f) - field              *
 * (t) - type               *
 * (q) - queue              *
 ****************************/

/*
 * cq
 */
#define my_cq(qname)     \
  typedef struct qname { \
    struct qname *qnext; \
    struct qname *qprev; \
    void *baddr;         \
  }

/*
 * my_cq_init()
 */
#define my_cq_init(h)  \
  do {                 \
    (h)->qnext = (h);  \
    (h)->qprev = (h);  \
    (h)->baddr = NULL; \
  } while (0)

/*
 * my_cq_is_empty
 */
#define my_cq_is_empty(h) ((h)->qnext == (h))

/*
 * my_cq_ent_on_q
 */
#define my_cq_ent_on_q(e, f) ((e)->f.qnext != &(e)->f)

/*
 * my_cq_ent
 */
#define my_cq_ent(h, t, f) (t *)((char *)&((h)->qnext) - (char *)&((t *)0)->f)

/*
 * my_cq_first
 */
#define my_cq_first(h, t, f) (my_cq_ent((h)->qnext, t, f))

/*
 * my_cq_init_ent
 */
#define my_cq_init_ent(e, f)  \
  do {                        \
    (e)->f.qnext = &(e)->f;   \
    (e)->f.qprev = &(e)->f;   \
    (e)->f.baddr = (void *)e; \
  } while (0)

/*
 * my_cq_insert_head
 */
#define my_cq_insert_head(h, e, f) \
  do {                             \
    (e)->f.qnext = (h)->qnext;     \
    (e)->f.qprev = (h);            \
    (h)->qnext->qprev = &(e)->f;   \
    (h)->qnext = &(e)->f;          \
  } while (0)

/*
 * my_cq_insert_tail
 */
#define my_cq_insert_tail(h, e, f) \
  do {                             \
    (e)->f.qprev = (h)->qprev;     \
    (e)->f.qnext = (h);            \
    (h)->qprev->qnext = &(e)->f;   \
    (h)->qprev = &(e)->f;          \
  } while (0)

/*
 * my_cq_next
 */
#define my_cq_next(e, t, f) (my_cq_ent((e)->f.qnext, t, f))

/*
 * my_cq_walk
 */
#define my_cq_walk(q, h) \
  (q) = (h)->qnext;      \
  while ((q) != (h))

/*
 * my_cq_walk_body
 */
#define my_cq_walk_body(q, e, t, f) \
  (e) = my_cq_ent(q, t, f);         \
  (q) = (q)->qnext;

/*
 * my_cq_remove
 */
#define my_cq_remove(e, f)              \
  do {                                  \
    (e)->f.qprev->qnext = (e)->f.qnext; \
    (e)->f.qnext->qprev = (e)->f.qprev; \
    (e)->f.qnext = &(e)->f;             \
    (e)->f.qprev = &(e)->f;             \
  } while (0)

/*
 * my_cq_foreach
 */
#define my_cq_foreach(q, h) \
  for ((q) = ((h)->qnext); (q) != (h); (q) = ((q)->qnext))
