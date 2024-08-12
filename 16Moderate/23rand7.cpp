

#include <cstdlib> // 包含 rand() 函数的头文件

// 模拟 rand5()，生成 0 到 4 之间的随机整数
int rand5() {
    return rand() % 5;
}

// 生成 0 到 6 之间的随机整数
int rand7() {
    int num;
    do {
        // 生成一个 0 到 24 之间的数
        num = 5 * rand5() + rand5();
    } while (num > 20); // 丢弃大于 20 的数，确保均匀分布

    // 将数映射到 0-6 的范围
    return num % 7;
}
