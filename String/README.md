1. KMP 是一种字符串模式匹配算法，可以找到子串在主串中的位置。
2. permutation 是获得一个字符串的全排列，如 abc 的全排列是 abc acb bac bca cab cba。

> 在当前目录下使用命令进行测试。
1. make kmp 编译 kmp。
2. ./kmp 运行 kmp。
3. make permutation 编译 permutation。
4. ./permutation 运行 permutation。
5. make all 同时编译所有。
6. make clean 清除可执行文件，更改代码后需要先 make clean 再 make test 重新编译。

因为字符串的首位保存着字符串的长度，所以原字符串的长度需要小于 10，不然会有 bug。可以将首位改为任意一个字符，这样子原字符串长度就可以没有限制了。
可以自行修改 KMP_algorithm.cpp 中的 main 函数中的 s1，s2 进行进一步的测试。