#include <iostream>
#include "BStree.h"
#include "AVLT.h"
#include <fstream>

template <typename T>
int init_dict(AVLT<T> *tree)
{
    ifstream dict("../../src/dictionary/dict.xdxf");
    if (!dict.is_open()) {
        cout << "Ошибка при открытиии файла словаря!" << endl;
        return 1;
    }

    cout << "Инициализация словаря...." << endl;
    string buff_key, buff_val, buff;
    char ch;
    for (;!dict.eof();) {
        dict.get(ch);
        if (ch == '<') {
            buff += ch;
            while (ch != '>') {
                dict.get(ch);
                buff += ch;
            }
            if (buff == "<ar>") {
                buff.clear();
                dict.get(ch);
                if (ch == '<') {
                    buff += ch;
                    while (ch != '>') {
                        dict.get(ch);
                        buff += ch;
                    }
                    if (buff == "<k>") {
                        dict.get(ch);
                        while (ch != '<') {
                            buff_key += ch;
                            dict.get(ch);
                        }
                        if (buff_key[0] == '-')
                            buff_key.erase(0, 1);
                        buff.clear();
                        if (ch == '<') {
                            buff += ch;
                            while (ch != '>') {
                                dict.get(ch);
                                buff += ch;
                            }
                            if (buff == "</k>") {
                                buff.clear();
                                dict.get(ch);
                                while (ch != '<') {
                                    buff_val += ch;
                                    dict.get(ch);
                                }
                                buff += ch;
                                if (ch == '<') {
                                    while (ch != '>') {
                                        dict.get(ch);
                                        buff += ch;
                                    }
                                    if (buff != "</ar>") {
                                        cout << "Некоректная разметка словаря";
                                        return -1;
                                    } else
                                        buff.clear();
                                }
                            } else {
                                cout << "Некоректная разметка словаря";
                                return -1;
                            }
                        }
                    } else {
                        cout << "Некоректная разметка словаря";
                        return -1;
                    }
                }
            } else {
                cout << "Некоректная разметка словаря";
                return -1;
            }
        }
        tree->Tadd(buff_key, buff_val);
        buff_key.clear();
        buff_val.clear();
    }
    dict.close();
    return 0;
}



int main()
{

    AVLT<AVLNode> *AVLtree = new AVLT<AVLNode>();
    int flg = init_dict(AVLtree);
    if (flg)
        return EXIT_FAILURE;
    //AVLtree->Tprint(AVLtree->TgetRoot());
    AVLNode *look;
    string word;
    string y_n;
    while (true) {
        cout << "Введите слово: ";
        cin >> word;
        look = AVLtree->Tlookup(word);
        if (look != NULL)
            cout << look->GetKey() << "\t" << look->GetValue() << endl;
        point:
        cout << "Хотте продолжить? (д/н): ";
        cin >> y_n;
        if (y_n == "н")
            break;
        if (y_n != "д")
            goto point;
    }

    return 0;
}