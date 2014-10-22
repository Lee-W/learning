#include <stdio.h>

int add(int a, int b) {
    if (!((a&b)|0))
        return a^b;

    int a1 = a&1, b1 = b&1;
    int sum = a1^b1;
    int carry = a1&b1;

    return add(add(add(a>>1 ,b>>1), carry) << 1, sum);
}

int main(int argc, char* argv[]) {
    int a, b, c;
    printf("Please input two integer:\n");
    scanf("%d %d",&a ,&b);
    printf("%d + %d = %d", a, b, add(a,b));
}

