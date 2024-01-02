#ifndef CALC_STACK_H
#define CALC_STACK_H

#define STACK_MAX_SIZE 128

struct stack {
    int top;
    int buf[STACK_MAX_SIZE];
};

static inline void stack_init(struct stack *s)
{
    s->top = -1;
}

static inline int stack_push(struct stack *s, int v)
{
    if (s->top >= STACK_MAX_SIZE)
        return -1;
    s->buf[++s->top] = v;
    return 0;
}

static inline int stack_pop(struct stack *s)
{
    return s->top <= -1 ? -1 : s->buf[s->top--];
}

static inline int stack_top(struct stack *s)
{
    return s->top <= -1 ? -1 : s->buf[s->top];
}

static inline int stack_empty(struct stack *s)
{
    return s->top == -1;
}

#endif  // CALC_STACK_H
