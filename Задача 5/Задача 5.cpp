#include <iostream>
using namespace std;

class stack {
public:


    typedef struct object {
        int number;
        struct object* next; // Укаатель на след переменную,типа такой же структуры
    } OBJ;

    OBJ* top = NULL;

    OBJ* push(int number) {
        OBJ* item = new OBJ; // Создаем новый объект со структорой, на который указывает item
        item->number = number; // Записываем данные в структуру 
        item->next = top;   // Записываем в некст прошлую вершину

        top = item;   // Теперт это вершиа
        return item; // Возвращает адрес нового объекта
    }



    void pop() {    // Удаляет объект из стека
        if (top == NULL) return; // Проверка на пустоту
        OBJ* tmp = top->next; // Создаем временный указатель, который будет указывать на след объект стека

        /*cout << "Объект " << top->number << " удален" << endl;*/
        delete top;
        top = tmp; // Вершина теперь след объект
    }

    void show() {
        OBJ* c = top;
        while (c != NULL) {
            cout << c->number << endl;
            c = c->next;
        }
    }

    int count() {
        OBJ* c = top;
        int k = 0;
        while (c != NULL) {
            k = k + 1;
            c = c->next;
        }
        return k;
    }

    void NOT_A_JOKE(stack* PB, stack* PC) {
        string map[] = { "     |     ",  "    ___    ", "   _____   ", "  _______  " };

        int q = 5; //Макстмальное количество дисков нужно еще поменять в проверке на макс число 

        OBJ* ca = top;
        OBJ* cb = (*PB).top;
        OBJ* cc = (*PC).top;

        int am = count();
        int bm = (*PB).count();
        int cm = (*PC).count();

        int am_negative = q - am;
        int bm_negative = q - bm;
        int cm_negative = q - cm;

        cout << "----------------------------------" << endl << endl;

        for (int i = 0; i < q; i++) {

            if (am_negative != 0) {
                cout << map[0];
                am_negative--;
            }
            else if (am > 1) {
                cout << map[ca->number];
                //cout << ca << " " << am;
                ca = ca->next;
                am--;
            }
            else if (am == 1) {
                cout << map[ca->number];
                //cout << ca << " " << am;
                am--;
            }

            if (bm_negative != 0) {
                cout << map[0];
                bm_negative--;
            }
            else  if (bm > 1) {
                cout << map[cb->number];
                cb = cb->next;
                bm--;
            }
            else if (bm == 1) {
                cout << map[cb->number];
                //cout << ca << " " << am;
                bm--;
            }

            if (cm_negative != 0) {
                cout << map[0];
                cm_negative--;
            }
            else  if (cm > 1) {
                cout << map[cc->number];
                cc = cc->next;
                cm--;
            }
            else if (cm == 1) {
                cout << map[cc->number];
                //cout << ca << " " << am;
                cm--;
            }
            cout << endl;
            
           
        }
        cout << endl << "----------------------------------" << endl << endl;
    }



};

void gift(stack* PA, stack* PB) {
    if ((*PA).top == NULL) cout << "Стержень пуст! Стоит попробывать другой." << endl << endl;
    else {
        if ((*PB).top == NULL) {
            (*PB).push((*PA).top->number);
            (*PA).pop();
        }
        else if ((*PB).top->number < (*PA).top->number) {
        cout << "Диск нельзя перемещать на диск меньшего размера. Надо было читать правила!" << endl << endl;
        }
        else if ((*PB).count() == 5) {
            cout << "Максимальное количество дисков на стержне. Ему хватит!" << endl << endl;
        }
        else {
            (*PB).push((*PA).top->number);
            (*PA).pop();
        }

    }

};



bool normal() {
    stack A;
    stack B;
    stack C;
    A.push(3);
    A.push(2);
    A.push(1);
    B.push(2);
    C.push(3);

    bool z = true;

    cout << endl << "Стандартный режим" << endl << endl;

    while (z) {


        A.NOT_A_JOKE(&B, &C);


        int choice_1;
        int choice_2;


        cout << endl << endl;;
        cout << "1) Переместить c A" << endl;
        cout << "2) Переместить c B" << endl;
        cout << "2) Переместить c C" << endl;
        cout << "Ваш выбор: ";
        cin >> choice_1;

        cout << endl << endl;;
        cout << "1) Переместить на A" << endl;
        cout << "2) Переместить на B" << endl;
        cout << "2) Переместить на C" << endl;
        cout << "Ваш выбор: ";
        cin >> choice_2;

        cout << endl << endl;
        if (choice_1 == choice_2) {
            cout << "Какой смысл? Даже не буду двигать этот диск!" << endl << endl;
        }

        if (choice_1 == 1) {
            if (choice_2 == 2)
                gift(&A, &B);
            if (choice_2 == 3)
                gift(&A, &C);
        }

        if (choice_1 == 2) {
            if (choice_2 == 1)
                gift(&B, &A);
            if (choice_2 == 3)
                gift(&B, &C);
        }

        if (choice_1 == 3) {
            if (choice_2 == 1)
                gift(&C, &A);
            if (choice_2 == 2)
                gift(&C, &B);
        }

        if (C.count() == 5) {
            cout << "-----------------" << endl
                << "   ПОБЕДА!!!     " << endl
                << "-----------------" << endl << endl;
            A.NOT_A_JOKE(&B, &C);
            z = false;
            return z;
        }


    }


    return 0;
}

int creative() {
    return 0;
}

bool menu(int choice) {
    if (choice == 1) {
        bool z = normal();
        return z;
    }

    /*else if (choice == 2) {

    }*/

    else {
        cout << "Неверный ввод!" << endl << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int choice; // Переменная выбора в меню

    stack B;
    stack C;
    int n;

    bool z = true;

    cout << "Даны три стержня: A B C" << endl;
    cout << "На стержни можно надевать диски размеров: 1 2 3" << endl << endl;
    cout << "На каждом шаге можно переносить только один диск." << endl;
    cout << "Диск нельзя перемещать на диск меньшего размера." << endl;
    cout << "Для промежуточного хранения можно использовать стрежень B" << endl << endl;
    cout << "Задача: Перенести диски со стержня A на стержень C " << endl << endl;

    while (z) {
        cout << "Выберете режим игры:" << endl
            << "1) Стандартный (заранее заданные условия)" << endl
            << "2) Креатив (задать условия самому)" << endl
            << endl << "Ваш выбор: ";
        cin >> choice;
        if (choice == 0) break;
        else  z = menu(choice);
    }

}

