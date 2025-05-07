class Foo {
public:
    counting_semaphore<1> secondReady {0};
    counting_semaphore<1> thirdReady {0};
    Foo() {}

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        secondReady.release();
    }

    void second(function<void()> printSecond) {
        secondReady.acquire();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        thirdReady.release();
    }

    void third(function<void()> printThird) {
        thirdReady.acquire();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
