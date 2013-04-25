#include <QStringListIterator>

#include "parser.h"

Parser::Parser(QString url, QString rawData, int page) :
    QThread()
{
    this->page = page;
    this->url = url;
    this->rawData = rawData;
}

void Parser::parse()
{
    numberOfPages = getNumberOfPages();
    parseItems();

    emit parseDone(url);
}

QVector<Item> Parser::getItems()
{
    return items;
}

int Parser::getNumberOfPages()
{
    int startIndex = 0;
    int endIndex = 0;
    int lenght = 0;
    startIndex = rawData.indexOf("<div class=\"pagination\">");
    endIndex = rawData.indexOf("</div>",startIndex);
    lenght = endIndex - startIndex;
    QString tempDataA(rawData.mid(startIndex,lenght));
    QStringList paginas;

    QRegExp exp(">[1-9]+<");

    int count = tempDataA.count(exp);
    int from = 0;
    int in = 0;

    for (int i = 0; i<count;i++)
    {
        in=exp.indexIn(tempDataA,from);
        paginas.append(exp.cap(0));
        from=in+paginas.value(i).size();
    }

    QString pagina = paginas.last();
    pagina = pagina.left(pagina.length() - 1);
    pagina = pagina.right(pagina.length() - 1);

    return pagina.toInt();
}

void Parser::parseItems()
{
    int startIndex = 0;

    startIndex = rawData.indexOf("<div id=\"menu_detalle_buscador\">");
    QString tempDataA(rawData.right(rawData.length() - startIndex));

    int index = tempDataA.indexOf("<div class=\"pagination\">");
    QString tempDataB(tempDataA.left(index));

    QStringList stringItems = tempDataB.split("<div id=\"menu_detalle_buscador\">");
    QStringListIterator itr(stringItems);
    while (itr.hasNext()) {
        QString text = itr.next();
        if (!text.isNull() && text.length())
        {
            items.append(getItem(text));
        }
    }
}

Item Parser::getItem(QString param)
{
    Item aux;

    QString startToken(".html\">");
    QString endToken("</a>");
    int startIndex = param.indexOf(startToken) + startToken.length();
    int endIndex = param.indexOf(endToken);
    aux.setTittle(param.mid(startIndex, endIndex - startIndex));

    startToken = "id=";
    endToken = "&";
    startIndex = param.lastIndexOf(startToken) + startToken.length();
    endIndex = param.indexOf(endToken);
    aux.setId(param.mid(startIndex, endIndex - startIndex).toInt());

    startToken = "href=\"";
    startIndex = param.lastIndexOf(startToken) + startToken.length();
    QString auxString(param.mid(startIndex,param.length()-startIndex));

    endToken = "\">";
    endIndex = auxString.indexOf(endToken);
    aux.setDownloadUrl(auxString.left(endIndex));

    return aux;
}

QString Parser::getUrl()
{
    return url;
}

int Parser::getPage()
{
    return page;
}
