#ifndef RULE_TRANSLATOR_H
#define RULE_TRANSLATOR_H

#include <QObject>

class RuleTranslator : public QObject
{
    Q_OBJECT
public:
    explicit RuleTranslator(QObject *parent = nullptr);

signals:

};

#endif // RULE_TRANSLATOR_H
