
#include <iostream>
//#include <conio.h>
using namespace std;

// рисует линию в терминале
void draw_line(int size = 20) {
    for (int i = 0; i < size; i++)
        cout << '-';
    cout << endl;
}

// класс реализующий работу процессороа и его логику
class Processors {
public:
    int tick_num = 0;

    // 1 процессор
    Task buf1 = { 0, 0, 0 };
    int durationTime1 = 0;

    // 2 процессор
    Task buf2 = { 0, 0, 0 };
    int durationTime2 = 0;

    // 3 процессор
    Task buf3 = { 0, 0, 0 };
    int durationTime3 = 0;

    // bool run_processor = false;
    bool last_sended = false;

    MYList* stack;
    int size_stack;

    int size_queue;
    MYList* queue;
    Task buf_queue = { 0, 0, 0 };

    Generator* generator;

    bool run = true;
    bool run1 = false;
    bool run2 = false;
    bool run3 = false;

    Processors(MYList* stack1, int _size_stack, MYList* _queue, int _size_queue, Generator* generator1);
    void tick();
    void loop();
};

// конструктор
Processors::Processors(MYList* stack1, int _size_stack, MYList* _queue, int _size_queue, Generator* generator1) {
    stack = stack1;
    size_stack = _size_stack;

    queue = _queue;
    size_queue = _size_queue;

    generator = generator1;

    Task buf;
    int count_tasks = (size_queue > generator->get_size()) ? generator->get_size() : size_queue;
    for (int i = 0; i < count_tasks; i++) {
        buf = generator->get();
        queue->append(
            buf.priority,
            buf.taskTime,
            buf.durationTime
        );
    }

    run = true;
}

// цикл процессора
void Processors::loop() {
    char c;
    while (run) {
        draw_line();
        tick();

        cout << "Процессор1: ";
        if (durationTime1 > 0)
            draw_task(buf1, durationTime1);
        else
            cout << "пусто" << endl;

        cout << "Процессор2: ";
        if (durationTime2 > 0)
            draw_task(buf2, durationTime2);
        else
            cout << "пусто" << endl;

        cout << "Процессор3: ";
        if (durationTime3 > 0)
            draw_task(buf3, durationTime3);
        else
            cout << "пусто" << endl;

        cout << "Генератор[" << generator->get_size() << "]:" << endl;
        draw_stack(generator->list->get_all(), generator->get_size());

        cout << "Стек[" << stack->get_size() << "/" << size_stack << "]:" << endl;
        draw_stack(stack->get_all(), stack->get_size());

        cout << "Очередь[" << queue->get_size() << "/" << size_queue << "]:" << endl;
        draw_stack(queue->get_all(), queue->get_size());

        // 13 Enter
        // 27 escape
        // 8 backspace
        // 32 space
        c = getchar(); //getch();
        if (c == 8) run = false;

        if (!run) break;
    }
}

// итерция процессора
void Processors::tick() {
    tick_num++;
    cout << tick_num << " такт" << endl;

    Task buf_stack;
    Task buf_generator;

    // добавление задач из генератора в очередь (если есть место)
    if (generator->get_size() > 0 && queue->get_size() < size_queue) {
        buf_generator = generator->get();
        queue->append(
            buf_generator.priority,
            buf_generator.taskTime,
            buf_generator.durationTime
        );
    }

    // работа 1 процессора
    if (durationTime1 > 0) {
        durationTime1 -= 1;
        if (!(durationTime1 > 0))
            run1 = false;
        else
            run1 = true;
    }
    else {
        run1 = false;
    }

    // работа 2 процессора
    if (durationTime2 > 0) {
        durationTime2 -= 1;
        if (!(durationTime2 > 0))
            run2 = false;
        else
            run2 = true;
    }
    else {
        run2 = false;
    }

    // работа 3 процессора
    if (durationTime3 > 0) {
        durationTime3 -= 1;
        if (!(durationTime3 > 0))
            run3 = false;
        else
            run3 = true;
    }
    else {
        run3 = false;
    }

    // логика распределителя
    if (queue->get_size() > 0) { // если в очереди есть задачи
      // распределение задач по процессорам
        if (durationTime1 < 1) {
            buf1 = queue->pop(0);
            durationTime1 = buf1.durationTime;
        }
        else if (durationTime2 < 1) {
            buf2 = queue->pop(0);
            durationTime2 = buf2.durationTime;
        }
        else if (durationTime3 < 1) {
            buf3 = queue->pop(0);
            durationTime3 = buf3.durationTime;
        }
        else if (stack->get_size() < size_stack) {
            // если процессоры заняты и есть место в стеке,
            // то закидываем задачу в стек
            buf_stack = queue->pop(0);
            stack->append(
                buf_stack.priority,
                buf_stack.taskTime,
                buf_stack.durationTime
            );
        }
    }
    else {
        // если очередь пуста, то распределяем по процессорам задачи из стека
        if (stack->get_size() > 0) {
            if (durationTime1 < 1) {
                buf1 = stack->pop((stack->get_size()) - 1);
                durationTime1 = buf1.durationTime;
            }
            else if (durationTime2 < 1) {
                buf2 = stack->pop((stack->get_size()) - 1);
                durationTime2 = buf2.durationTime;
            }
            else if (durationTime3 < 1) {
                buf3 = stack->pop((stack->get_size()) - 1);
                durationTime3 = buf3.durationTime;
            }
        }
    }

    // останавливаем работу когда все процессоры свободны
    if (!run1 && !run2 && !run3 && (stack->get_size() < 1) && (queue->get_size() < 1))
        run = false;

}
