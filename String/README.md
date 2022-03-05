> 在当前目录下使用命令进行测试
1. make test 编译。
2. ./test 运行。
3. make clean 清除可执行文件，更改代码后需要先 make clean 再 make test 重新编译。

因为字符串的首位保存着字符串的长度，所以原字符串的长度需要小于 10，不然会有 bug。
可以自行修改 KMP_algorithm.cpp 中的 main 函数中的 s1，s2 进行进一步的测试。