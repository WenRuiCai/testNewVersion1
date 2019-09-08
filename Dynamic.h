//
// Created by 84443 on 2019/9/7.
//

#ifndef TESTNEWVERSION_DYNAMIC_H
#define TESTNEWVERSION_DYNAMIC_H


class Dynamic {
private:
    int i;
public:
    int geti() {
        return this->i;
    }

    void seti(int num) {
        this->i = num;
    }

    Dynamic(int i) {
        this->i = i;
    }
};


#endif //TESTNEWVERSION_DYNAMIC_H
