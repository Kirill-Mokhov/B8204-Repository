#ifndef SHAKERSORTOOP_COMPARE_H
#define SHAKERSORTOOP_COMPARE_H

class CompareInterface{
public:
    virtual int Compare(int leftSubj, int rightSubj) = 0;
};

class CompareTool: public CompareInterface{
public:
    int Compare(int Subj1, int Subj2) override{
        if (Subj2 > Subj1) return 1;
        if (Subj2 < Subj1) return -1;
        if (Subj2 == Subj1) return 0;
    }
};

class CompareToolReverse: public CompareInterface{
public:
    int Compare(int Subj1, int Subj2) override{
        if (Subj2 > Subj1) return -1;
        if (Subj2 < Subj1) return 1;
        if (Subj2 == Subj1) return 0;
    }
};

#endif //SHAKERSORTOOP_COMPARE_H
