#ifndef RULE_PARSER_H
#define RULE_PARSER_H

#include <QObject>

class RuleParser : public QObject
{
    Q_OBJECT
public:
    explicit RuleParser(QObject *parent = nullptr);

signals:

};

#endif // RULE_PARSER_H
