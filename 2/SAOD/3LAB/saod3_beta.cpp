#include <iostream>
using namespace std;
struct task
{
    int proc;
    int value;
    int moment;
};
task* gener(int n, int handl, task*& mas)
{
    int k = 1;
    cout << "Введите ваши задачи: номер процессора от 1 до 3 и количество тактов для задачи" << endl;
    for (int i = 0; i < handl; i++)
    {
        cout << "Номер процессора:";
        cin >> mas[i].proc;
        cout << "Количество тактов:";
        cin >> mas[i].value;
        mas[i].moment = k;
        k++;
    }
    srand(time(0));
    for (int i = handl; i < n; i++)
    {
        mas[i].proc = rand() % 3 + 1;
        mas[i].value = rand() % 5 + 1;
        mas[i].moment = k;
        k++;
    }
    cout << "Задачи" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Номер процессора: " << mas[i].proc << " ";
        cout << "Количество тактов: " << mas[i].value << " ";
        cout << "Номер поступления: " << mas[i].moment << endl;
    }
    cout << "НАЧАЛО" << endl;
    return mas;
}

struct queue
{
    int proc;
    int value;
    int count;
    int moment;
};
queue* form(queue*& mas, task massiv[], int n)
{
    if (n > 10)
    {
        cout << "Очередь переполнена";
        std::exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        mas[i].proc = massiv[i].proc;
        mas[i].value = massiv[i].value;
        mas[i].moment = massiv[i].moment;
    }
    return mas;
}
queue* deletik(queue*& mas, int& w)
{
    queue* mas1 = new queue[w - 1];
    for (int i = 0; i < w - 1; i++)
    {
        mas1[i].proc = mas[i + 1].proc;
        mas1[i].value = mas[i + 1].value;
        mas1[i].moment = mas[i + 1].moment;
    }
    delete mas;
    w--;
    mas = mas1;
    return mas;
}

struct stek
{
    int proc;
    int value;
    int moment;
};
void incl(stek mas[], int& k, int pr, int val, int mom)
{
    if (k == 5)
    {
        cout << "Стек переполнен";
        std::exit(1);
    }
    mas[k].proc = pr;
    mas[k].value = val;
    mas[k].moment = mom;
    k++;
}
void del(stek mas[], int& k)
{
    mas[k].proc = 0;
    mas[k].value = 0;
    mas[k].moment = 0;
    k--;
}
struct raspred
{
    int proc;
    int value;
    int moment;
};


struct procces
{
    bool proc1;
    int zn1;
    int mom1;
    bool proc2;
    int zn2;
    int mom2;
    bool proc3;
    int zn3;
    int mom3;
    procces();
};
procces::procces()
{
    this->proc1 = 0;
    this->proc2 = 0;
    this->proc3 = 0;
    this->zn1 = 0;
    this->zn2 = 0;
    this->zn3 = 0;
    this->mom1 = 0;
    this->mom2 = 0;
    this->mom3 = 0;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int w;
    cout << "Введите количество задач: ";
    cin >> w;
    cout << "Сколько задач вы хотите ввести вручную: ";
    int hand;
    cin >> hand;
    task* mas = new task[w];
    mas = gener(w, hand, mas);
    queue* mass = new queue[w];
    queue que;
    que.count = w;
    mass = form(mass, mas, w);
    raspred rasp;
    procces procc;
    int k = 0;
    int takt = 1;
    stek masiv[5];
    while (que.count)
    {
        rasp.proc = mass[0].proc;
        rasp.value = mass[0].value;
        rasp.moment = mass[0].moment;
        if (rasp.proc == 1)
        {
            if (!procc.proc1)
            {
                procc.zn1 = rasp.value;
                procc.mom1 = rasp.moment;
                procc.proc1 = 1;
            }
            else
            {
                incl(masiv, k, rasp.proc, rasp.value, rasp.moment);
            }
        }
        if (rasp.proc == 2)
        {
            if (!procc.proc2)
            {
                procc.zn2 = rasp.value;
                procc.mom2 = rasp.moment;
                procc.proc2 = 1;
            }
            else
            {
                incl(masiv, k, rasp.proc, rasp.value, rasp.moment);
            }
        }
        if (rasp.proc == 3)
        {
            if (!procc.proc3)
            {
                procc.zn3 = rasp.value;
                procc.mom3 = rasp.moment;
                procc.proc3 = 1;
            }
            else
            {
                incl(masiv, k, rasp.proc, rasp.value, rasp.moment);
            }
        }
        cout << "Прошёл такт номер " << takt << endl;
        takt++;
        cout << "В очереди находится" << endl;
        for (int i = 1; i < que.count; i++)
        {
            cout << "Номер процессора " << mass[i].proc << " ";
            cout << "Количество тактов " << mass[i].value << " ";
            cout << "Номер поступления " << mass[i].moment << endl;
        }
        cout << "В процессере 1 находится:";
        if (procc.zn1 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn1 << " С номером поступления " << procc.mom1 << endl;
        cout << "В процессере 2 находится:";
        if (procc.zn2 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn2 << " С номером поступления " << procc.mom2 << endl;
        cout << "В процессере 3 находится:";
        if (procc.zn3 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn3 << " С номером поступления " << procc.mom3 << endl;
        cout << "В стеке содержится:" << endl;
        if (k > 0)
            for (int i = 0; i < k; i++)
            {
                cout << "Номер процессора: " << masiv[i].proc << " ";
                cout << "Количество тактов: " << masiv[i].value << " ";
                cout << "Номер поступления: " << masiv[i].moment << endl;
            }
        else cout << "ПУСТОТА" << endl;
        cout << "______________" << endl;
        procc.zn1--;
        if (procc.zn1 <= 0) procc.proc1 = false;
        procc.zn2--;
        if (procc.zn2 <= 0) procc.proc2 = false;
        procc.zn3--;
        if (procc.zn3 <= 0) procc.proc3 = false;
        mass = deletik(mass, que.count);
    }
    cout << "ОЧЕРЕДЬ ПУСТА" << endl;
    while (k != 0)
    {
        rasp.proc = masiv[k - 1].proc;
        rasp.value = masiv[k - 1].value;
        rasp.moment = masiv[k - 1].moment;
        if (rasp.proc == 1)
        {
            if (!procc.proc1)
            {
                procc.zn1 = rasp.value;
                procc.mom1 = rasp.moment;
                procc.proc1 = 1;
                del(masiv, k);
            }
        }
        if (rasp.proc == 2)
        {
            if (!procc.proc2)
            {
                procc.zn2 = rasp.value;
                procc.mom2 = rasp.moment;
                procc.proc2 = 1;
                del(masiv, k);
            }
        }
        if (rasp.proc == 3)
        {
            if (!procc.proc3)
            {
                procc.zn3 = rasp.value;
                procc.mom3 = rasp.moment;
                procc.proc3 = 1;
                del(masiv, k);
            }
        }
        cout << "Прошёл такт номер " << takt << endl;
        takt++;
        cout << "В процессере 1 находится:";
        if (procc.zn1 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn1 << " С номером поступления " << procc.mom1 << endl;
        cout << "В процессере 2 находится:";
        if (procc.zn2 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn2 << " С номером поступления " << procc.mom2 << endl;
        cout << "В процессере 3 находится:";
        if (procc.zn3 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn3 << " С номером поступления " << procc.mom3 << endl;
        {
            cout << "В стеке содержится:" << endl;
            for (int i = 0; i < k; i++)
            {
                cout << "Номер процессора: " << masiv[i].proc << " ";
                cout << "Количество тактов: " << masiv[i].value << " ";
                cout << "Номер поступления: " << masiv[i].moment << endl;
            }
        }
        procc.zn1--;
        if (procc.zn1 <= 0) procc.proc1 = false;
        procc.zn2--;
        if (procc.zn2 <= 0) procc.proc2 = false;
        procc.zn3--;
        if (procc.zn3 <= 0) procc.proc3 = false;
    }
    cout << "В СТЭКЕ НИЧЕГО НЕТ" << endl;
    while ((procc.zn1 >= 0) || (procc.zn2 >= 0) || (procc.zn3 >= 0))
    {
        cout << "Прошёл такт номер " << takt << endl;
        takt++;
        cout << "В процессере 1 находится:";
        if (procc.zn1 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn1 << " С номером поступления " << procc.mom1 << endl;
        cout << "В процессере 2 находится:";
        if (procc.zn2 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn2 << " С номером поступления " << procc.mom2 << endl;
        cout << "В процессере 3 находится:";
        if (procc.zn3 <= 0) cout << "НИЧЕГО" << endl;
        else cout << procc.zn3 << " С номером поступления " << procc.mom3 << endl;
        procc.zn1--;
        if (procc.zn1 <= 0) procc.proc1 = false;
        procc.zn2--;
        if (procc.zn2 <= 0) procc.proc2 = false;
        procc.zn3--;
        if (procc.zn3 <= 0) procc.proc3 = false;
    }
    cout << "ПРОГРАММА ДОРАБОТАЛА" << endl;
    delete[] mas;
    delete[] mass;
    return 0;
}
