#ifndef USERINFO_H
#define USERINFO_H

#include <QObject>
#include <QDomDocument>

class userInfo : public QObject
{
    Q_OBJECT
public:
    explicit userInfo(QObject *parent = 0);

signals:

public slots:

private:
    QDomDocument userProfile;
    QString userName;
    QString password;
    QString email;
    QString brand;
    QString model;
    QString rom;

};

#endif // USERINFO_H
