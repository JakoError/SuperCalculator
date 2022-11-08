//
// Created by JakoError on 2020/12/17.
//
#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hashMap.h"
#include "matrix_c.h"

#pragma warning(disable:4996)
#pragma warning (disable:4819)

Matrix emptyMatrix;
HashMap *space;

/*
 * #mode for read matrix and save it to parameters
 */
void matrixMain() {
    printf("\nWelcome to Matrix calculation\npowered by JakoError\n------use \"help\" command to get help------\n");
    space = createHashMap(NULL, NULL, 0);
    emptyMatrix = createMatrix(0, 0, NULL);
    for (;;) {
        printf(">>");
        //read line
        char c, line[100] = {'\0'};
        int i = 0;
        while ((c = (char) getchar()) != '\n') line[i++] = c;

        int ei = equal(line);//是否为赋值语句
        char *operation = operate(line);//判断符号

        if (ei != -1) {//等式

            //获取名称
            char name[50] = {'\0'};
            sscanf(line, "%s", name);
            if (equal(name) != -1)
                name[equal(name)] = '\0';
            if (!strcmp(name, "exit")) {
                printf("别吧~，真的有人会干这种事啊~");
                continue;
            }

            //移动到=后边第一个不为空
            ei++;
            while (line[ei] == ' ') ei++;

            //判断是[]还是函数
            Matrix new = emptyMatrix;
            if (line[ei] == '[') {
                ei++;//跳过[
                new = readMatrix(&line[ei]);

            } else if (operation[0] != '\0') {//后面跟着一个计算式

                char s1[50], s2[50];

                sscanf(&line[ei], "%s%s", s1, s2);
                Matrix *m1 = getValue(space, s1), *m2 = getValue(space, s2);
                if (m1 == NULL || m2 == NULL) {
                    printf("Matrix not found!\n");
                    continue;
                }

                if (!strcmp(operation, "+"))
                    new = addM(m1, m2);
                else if (!strcmp(operation, "-"))
                    new = minusM(m1, m2);
                else if (!strcmp(operation, "*"))
                    new = mulM(m1, m2);

            } else {//开始判断函数名称
                char funcName[10] = {'\0'};
                sscanf(&line[ei], "%s", funcName);
                int funcLiter = 0;
                //循环到消除括号
                while (funcName[funcLiter] != '\0') {
                    if (funcName[funcLiter] == '(') {
                        funcName[funcLiter] = '\0';
                        break;
                    }
                    funcLiter++;
                }
                funcLiter++;//跳过空字符
                //循环到第一个数
                while ((funcName[funcLiter] < '0' || funcName[funcLiter] > '9')
                       && funcName[funcLiter] != '\0' && funcName[funcLiter] != ')')
                    funcLiter++;

                //获取完毕开始判断
                if (strcmp(funcName, "eye") == 0) {
                    int m = 0;
                    sscanf(&funcName[funcLiter], "%d", &m);
                    new = eye(m);
                } else if (strcmp(funcName, "fill") == 0) {
                    int num = 0, m = 0, n = 0;

                    sscanf(&funcName[funcLiter], "%d", &num);
                    funcLiter = nextIndex(funcName, funcLiter);
                    sscanf(&funcName[funcLiter], "%d", &m);
                    funcLiter = nextIndex(funcName, funcLiter);
                    sscanf(&funcName[funcLiter], "%d", &n);

                    new = fill(num, m, n);
                } else if (strcmp(funcName, "diag") == 0) {
                    double nums[100];
                    int length = 0, np = 0;
                    //获取括号内容
                    while (funcName[funcLiter] != ')') {
                        if (np == 100) {
                            printf("不支持100以上的矩阵\n");
                            np = -1;
                            break;
                        }
                        sscanf_s(&funcName[funcLiter], "%lf", &nums[np++]);
                        funcLiter = nextIndex(funcName, funcLiter);
                    }
                    new = diag(nums, np);
                } else if (strcmp(funcName, "randi") == 0) {
                    int Maxi = 0, m = 0, n = 0;

                    sscanf(&funcName[funcLiter], "%d", &Maxi);
                    funcLiter = nextIndex(funcName, funcLiter);
                    sscanf(&funcName[funcLiter], "%d", &m);
                    funcLiter = nextIndex(funcName, funcLiter);
                    sscanf(&funcName[funcLiter], "%d", &n);

                    new = randi(Maxi, m, n);
                } else {
                    printf("未找到该函数。。\n");
                    continue;
                }
            }

            //存储入空间
            if (!new.m || !new.n) {
                printf("empty Matrix\n");
                continue;
            } else {
                new.name = (char *) malloc(sizeof(char) * 100);
                strcpy(new.name, name);
                putData(space, name, new);
            }
            printMatrix(new);

        } else if (strcmp(line, "exit") == 0) {//退出
            break;
        } else if (strcmp(line, "help") == 0) {
            printf("==》构建矩阵： 矩阵名称 = [1,2,3;4,5,6] 逗号和空格可用于间隔行内数字，分号用于间隔行\n"
                   "==》同时可用函数创建矩阵 如 eye(m)(单位)  fill(num,m,n)(全为num的m*n矩阵) \n"
                   "\trandi(Max,m,n)(全为大于0小于等于max的m*n矩阵) diag(num[])(对角元为num中的元素)\n"
                   "==》矩阵运算 + - *(暂时只能支持两个矩阵进行运算sorry)(可用把结果放在另一个矩阵否则默认为ans且不存储在数据空间中)\n"
                   "--后续功能待进一步完善\n");
        } else if (!strlen(line)) {//换行
            continue;
        } else if (operation[0] != '\0') {//单纯运算
            char s1[50], s2[50];

            sscanf(line, "%s%s", s1, s2);
            Matrix *m1 = getValue(space, s1), *m2 = getValue(space, s2);
            if (m1 == NULL || m2 == NULL) {
                printf("Matrix not found!\n");
                continue;
            }

            if (!strcmp(operation, "+"))
                printMatrix(addM(m1, m2));
            else if (!strcmp(operation, "-"))
                printMatrix(minusM(m1, m2));
            else if (!strcmp(operation, "*"))
                printMatrix(mulM(m1, m2));

        } else {
            char name[100];
            sscanf(line, "%s", name);
            Matrix *m = getValue(space, name);
            if (m == NULL)
                printf("Matrix not found\n");
            else
                printMatrix(*m);
        }
    }
}

Matrix readMatrix(const char *line) {
    int n = 0, m = 0, i = 0;

    while (line[i] == ' ') i++;
    if (line[i] == ']')
        return emptyMatrix;
    m = n = 1;
    while (line[i] != ';' && line[i] != ']') {
        if (line[i] == ' ' || line[i] == ',')
            n++;
        i++;
    }
    int num = 0;
    while (line[i] != ']') {
        i++;
        m++;
        num = 1;
        while (line[i] != ';' && line[i] != ']') {
            if (line[i] == ' ' || line[i] == ',')
                num++;
            i++;
        }
        if (num != n) {
            printf("读取不了，有请下一位选手\n");
            return emptyMatrix;
        }
    }

    if (n > 100 || m > 100) {
        printf("不支持100以上的矩阵\n");
        return emptyMatrix;
    }


    double **table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        table[j] = malloc(sizeof(double) * n);

    int lp = 0;
    for (i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            sscanf(&line[lp], "%lf", &table[i][j]);
            lp = nextIndex(line, lp);
        }
    }
    return createMatrix(m, n, table);
}

int equal(const char *line) {
    for (int i = 0; i < 100; ++i) {
        if (line[i] == '=')
            return i;
        if (line[i] == '\0')
            return -1;
    }
    return -1;
}

char *operate(char *line) {
    for (int i = 0; line[i] != '\0'; ++i) {
        if (line[i] == '+') {
            line[i] = ' ';
            return "+";
        }
        if (line[i] == '-') {
            line[i] = ' ';
            return "-";
        }
        if (line[i] == '*') {
            line[i] = ' ';
            if (line[i - 1] == '.') {
                line[i - 1] = ' ';
                return ".*";
            }
            return "*";
        }
    }
    return "\0";
}

int nextIndex(const char *line, int i) {
    while ((('0' <= line[i] && line[i] <= '9') || line[i] == '.')
           && line[i] != '\0' && line[i] != ')' && line[i] != ']')
        i++;
    while (('0' > line[i] || line[i] > '9') && line[i] != ']' && line[i] != ')' && line[i] != '\0')
        i++;
    return i;
}

Matrix createMatrix(int m, int n, double **table) {
    if (!m || !n || table == NULL)
        return emptyMatrix;

    Matrix *temp = malloc(sizeof(Matrix));
    temp->name = "ans";
    temp->m = m;
    temp->n = n;
    temp->table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        temp->table[j] = malloc(sizeof(double) * n);

    if (table != NULL)
        cpyArray(temp->table, table, m, n);
    return *temp;
}

/*
 * #add function
 */
Matrix addM(Matrix *a, Matrix *b) {

    if (a->m != b->m || a->n != b->n) {
        printf("\nError:不同型加啥呢？\n");
        return emptyMatrix;
    }
    int m = a->m, n = a->n;

    double **table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        table[j] = malloc(sizeof(double) * n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            table[i][j] = a->table[i][j] + b->table[i][j];
    return createMatrix(m, n, table);
}

/*
 * #minus function
 */
Matrix minusM(Matrix *a, Matrix *b) {
    Matrix _b = createMatrix(b->m, b->n, b->table);
    Matrix *_pb = &_b;
    for (int i = 0; i < b->m; ++i)
        for (int j = 0; j < b->n; ++j)
            _pb->table[i][j] = -_pb->table[i][j];
    return addM(a, _pb);
}

/*
 * #multiple function
 */
Matrix mulM(Matrix *a, Matrix *b) {
    if (a->n != b->m) {
        printf("矩阵乘法不是这样打的,小伙子不讲武德\n");
        return emptyMatrix;
    }
    int m = a->m, n = b->n, q = a->n;

    double **table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        table[j] = malloc(sizeof(double) * n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            table[i][j] = 0;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < q; ++k)
                table[i][j] += a->table[i][k] * b->table[k][j];
    return createMatrix(m, n, table);
}

Matrix eye(int m) {
    if (m > 100) {
        printf("不支持100以上的矩阵\n");
        return emptyMatrix;
    }
    if (m <= 0) {
        printf("??????你在干什么???????\n");
        return emptyMatrix;
    }

    double **table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        table[j] = malloc(sizeof(double) * m);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j)
                table[i][j] = 1;
            else
                table[i][j] = 0;
        }
    }
    return createMatrix(m, m, table);
}

Matrix fill(double num, int m, int n) {
    if (m > 100 || n > 100) {
        printf("不支持100以上的矩阵\n");
        return emptyMatrix;
    }
    if (m <= 0 || n <= 0) {
        printf("??????你在干什么???????\n");
        return emptyMatrix;
    }

    double **table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        table[j] = malloc(sizeof(double) * n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            table[i][j] = num;

    return createMatrix(m, n, table);
}

Matrix randi(int Maxi, int m, int n) {
    if (Maxi < 1) {
        printf("最大值不能小于1啊哥\n");
        return emptyMatrix;
    }
    if (m > 100 || n > 100) {
        printf("不支持100以上的矩阵\n");
        return emptyMatrix;
    }
    if (m <= 0 || n <= 0) {
        printf("??????你在干什么???????\n");
        return emptyMatrix;
    }

    srand(time(NULL));

    double **table = malloc(sizeof(double *) * m);
    for (int j = 0; j < m; ++j)
        table[j] = malloc(sizeof(double) * n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            table[i][j] = rand() % Maxi + 1;

    return createMatrix(m, n, table);
}

Matrix diag(double *nums, int length) {
    if (nums == NULL || length <= 0)
        return emptyMatrix;
    if (length > 100) {
        printf("不支持100以上的矩阵\n");
        return emptyMatrix;
    }

    double **table = malloc(sizeof(double *) * length);
    for (int j = 0; j < length; ++j)
        table[j] = malloc(sizeof(double) * length);

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (i == j)
                table[i][j] = nums[i];
            else
                table[i][j] = 0;
        }
    }

    return createMatrix(length, length, table);
}


void printMatrix(Matrix m) {
    if (m.table == NULL)
        printf("table NULL\n");

    printf("%s = \n\n", m.name);
    for (int i = 0; i < m.m; ++i) {
        for (int j = 0; j < m.n; ++j) {
            printf("\t%0.3lf", m.table[i][j]);
        }
        printf("\n");
    }
}