#include "combiner.h"

long Combiner::count = 0;

Combiner::Combiner(int nElements_p)
{
    nElements = nElements_p;
    nCombinations = getNumberOfCombinations(nElements_p);
}

QSet<QString> Combiner::combine(QVector<QString> input)
{
    QSet<QString> ret;
    int len = input.count();

    if (len == 1)
    {
        ret.insert(input.first());
        return ret;
    }

    for(int i = 0; i < len; i++)
    {
        if ((count/(nElements - 1)) > (nCombinations / 2))
        {
            qDebug("count mayor a (nCombinations / 2)");
            break;
        }

        QString aux = input.first();
        input.remove(0);

        QSet<QString> temp = combine(input);

        QSetIterator<QString> itr(temp);
        while (itr.hasNext()) {
            QString itrString = itr.next();
            ret.insert(itrString.append(aux));
            count++;
        }

        input.append(aux);
    }

    return ret;
}

long Combiner::getNCombinatios()
{
    return nCombinations;
}

long Combiner::getCount()
{
    return count;
}

long Combiner::getNumberOfCombinations(int options)
{
    long ret = 1;

    for(int i = 1; i <= options; i++)
    {
        ret *= i;
    }

    return ret;
}
