#ifndef SHAKERSORTOOP_SWAP_H
#define SHAKERSORTOOP_SWAP_H

class SwapInterface{
public:
    virtual void Swap(int &element1, int &element2) = 0;
};

class SwapToolTEST : public SwapInterface{
public:
    void Swap(int &element1, int &element2)
    {
        if (&element1 == &element2) {
            return;
        }
        element1 = element1 + element2;
        element2 = element1 - element2;
        element1 = element1 - element2;
    }
};

#endif //SHAKERSORTOOP_SWAP_H
