// Функция, возвращающая управление, в то время как в потоке 
// сохраняется обращение к локальным переменным
#include <thread>

struct func {
    int& i;
    func(int& i_):i(i_){}
    void operator()(){
        for(unsigned j=0;j<1000000;++j){
            ++i; //do_something(i);
        }
    }
};
void oops(){
    int some_local_state=0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
}