/*************************************************************************
	> File Name: 20.yfz.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  2/27 20:44:28 2020
 ************************************************************************/
bool isValid(char * s){
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    int top = -1, flag = 1;
    int i = 0;
    while (s[i]) {
        switch (s[i]) {
            case '(':
            case '[':
            case '{': {
                stack[++top] = s[i];
            } break;
            case ')': flag = (top != -1 && stack[top--] == '('); break;
            case ']': flag = (top != -1 && stack[top--] == '['); break;
            case '}': flag = (top != -1 && stack[top--] == '{'); break;
        }
        if (!flag) break;
        ++i;
    }
    free(stack);
    return (flag == 1 && top == -1);
}
