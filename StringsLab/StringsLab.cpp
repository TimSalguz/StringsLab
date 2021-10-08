//Вариант-1. Дана строка длиной не более 100 символов. Сделать все гласные буквы в ней заглавными.

#include <iostream>
const int N = 100;

void GlasnyeKapsom(char charray[N], int i)
{
    //НАЧАЛО ГЛАСНЫЕ ВСЕ КАПСОМ!
    if (charray[i] == -96 ||//а //128 //96
        charray[i] == -82 ||//о //114 //82
        charray[i] == -88 ||//и //120 //88
        charray[i] == -91)  //е //123 //91
    {
        charray[i] -= 32;
    }
    else if (charray[i] == -29 ||//у //109 //29
             charray[i] == -21 ||//ы //101 //21
             charray[i] == -19 ||//э //99  //19
             charray[i] == -18 ||//ю //98  //18
             charray[i] == -17)  //я //97  //17
    {
        charray[i] -= 80;
    }
    else if (charray[i] == -15)
    {
        charray[i] -= 1;
    }
    //КОНЕЦ ГЛАСНЫЕ ВСЕ КАПСОМ
}


int main()
{
    char charray[N];
    char c = 0;

    //Посимвольное заполнение массива сперва текстом, потом пустыми символами
    for (int i = 0; i < N; i++)
    {
        if (std::cin.rdbuf()->in_avail() != 1)
        {
            std::cin.get(charray[i]);
            GlasnyeKapsom(charray, i);
        }
        else
        {
            //Заполяю все пустое место в массиве пустым символом
            charray[i] = '\0';
        }
    }
    //Вывод текста
    for (int i = 0; i < N; i++)
    {
        std::cout << charray[i];
    }
}