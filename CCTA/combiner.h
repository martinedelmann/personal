#ifndef COMBINER_H
#define COMBINER_H

#include <QSet>
#include <QString>
#include <QVector>

class Combiner
{
public:
    Combiner(int nElements_p);

    QSet<QString> combine(QVector<QString> input);

    long getNCombinatios();
    long getCount();
private:
    static long count;
    long nCombinations;
    int nElements;
    QVector<QString> input;
    long getNumberOfCombinations(int options);
};

#endif // COMBINER_H
