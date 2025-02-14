g++ -pthread -o main /home/home/aproj/threads/src/main.cpp
./main


# Теория
Команда g++
Команда g++ предназначена для компиляции с помощью компилятора GCC кода на языке C++. Данная команда похожа на команду gcc, используемую для компиляции кода на языке C.

Базовый синтаксис команды выглядит следующим образом:

$ g++ [параметры] имена файлов

В качестве имен файлов могут использоваться как имена файлов исходного кода на языке C++ с расширениями .cpp и .cxx, так и имена файлов объектного кода с расширением .o. Компилятор поддерживает поистине огромное количество параметров, но наиболее важными из них являются такие параметры, как параметр -o, позволяющий задать имя результирующего исполняемого файла, параметр -c, позволяющий лишь скомпилировать файл без связывания (то есть, создать файл объектного кода, а не исполняемый файл), параметр -O, позволяющий задать уровень оптимизации и параметр -l, позволяющий указать библиотеку, которая должна быть связана с результирующим исполняемым файлом.

## Примеры использования
### Компиляция программы из одного файла исходного кода
Для компиляции простейшей программы из одного файла исходного кода достаточно передать компилятору имя файла исходного кода, а также имя результирующего исполняемого файла.

Это содержимое файла исходного кода test.cxx:


#include <iostream>
 
void print_hello(void)
{
        std::cout << &quot;Hello world&quot; << std::endl;     
}
 
int main(int argc, char **argv)
{
        print_hello();
       
        return 0;
}
Для его компиляции может использоваться следующая простая команда:

$ g++ test.cxx -o test

В результате будет создан исполняемый файл test:

$ ./test
Hello world

### Компиляция программы из нескольких файлов исходного кода
Компиляция программы из нескольких файлов исходного кода может осуществляться также, как и программы из одного файла исходного кода путем перечисления всех файлов исходного кода вместо одного, но лучшим решением является компиляция файлов исходного кода по очереди с последующим связыванием.

Это содержимое файла исходного кода test.cxx:


#include <iostream>
 
void print_hello(void)
{
        std::cout << &quot;Hello world&quot; << std::endl;
}
Это содержимое заголовочного файла test.hxx с прототипом функции:


#pragma once
 
void print_hello(void);
А это — содержимое файла исходного кода main.cxx:


#include <iostream>
#include "test.hxx"
 
int main(int argc, char **argv)
{
        print_hello();
       
        return 0;
}
Для компиляции программы может использоваться следующая последовательность команд:

$ g++ -c test.cxx -o test.o
$ g++ -c main.cxx -o main.o
$ g++ test.o main.o -o test

В результате также будет создан исполняемый файл test:

$ ./test
Hello world
