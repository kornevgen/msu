
char *join(char *begin, char *lines[]) {
    if (!lines || !lines[0]) {
        return begin;
    }
    begin = realloc(begin, strlen(begin) + strlen(lines[0]));
    return join(strcat(begin, lines[0]), &lines[1]);
}

char *pretty_print(int n) {
    char **buf = malloc(n);
    for (int i = 0; i < n; i++) {
        buf[i] = malloc(100);
        sprintf(buf[i], "%d ", i);
    }
    return join("", buf);
}

int main(void) {
    puts(pretty_print(207 * 208));
}
