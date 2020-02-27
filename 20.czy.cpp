/*************************************************************************
	> File Name: 20.czy.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/27 20:44:49 2020
 ************************************************************************/
typedef struct Stack {
    char *str;
    int top, size;
} Stack;

Stack *init_Stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->str = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    s->size = n;
    return s;
}

void clear_Stack(Stack *s) {
    if (!s) return;
    free(s->str);
    free(s);
    return;
}

int empty(Stack *s) {
    return s->top == -1;
}

char top(Stack *s) {
    return s->str[s->top];
}

int push(Stack *s, char x) {
    if (!s) return 0;
    if (s->top + 1 == s->size) return 0;
    s->str[++s->top] = x;
    return 1;
}

int pop(Stack *s) {
    if (!s) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 0;
}

bool isValid(char * s){
    int len = strlen(s);
    Stack *stack = init_Stack(len);
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{': {
                push(stack, s[i]);
            } break;
            case ')': {
                if (empty(stack) || top(stack) != '(') return false;
                pop(stack);
            } break;
            case ']': {
                if (empty(stack) || top(stack) != '[') return false;
                pop(stack);
            } break;
            case '}': {
                if (empty(stack) || top(stack) != '{') return false;
                pop(stack);
            } break;
        }
    }
    int flag = empty(stack);
    clear_Stack(stack);
    return flag;
}
