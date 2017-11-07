﻿#ifndef AGVLOGPROCESS_H
#define AGVLOGPROCESS_H

#include <QObject>
#include <QThread>
#include <list>
#include <mutex>


struct SubNode{
    bool trace = false;
    bool debug = false;
    bool info = false;
    bool warn = false;
    bool error = false;
    bool fatal = false;
};

class AgvLogProcess : public QThread
{
    Q_OBJECT
public:
    explicit AgvLogProcess(QObject *parent = nullptr);

    ~AgvLogProcess();
    void addSubscribe(int sock,SubNode node);
    void removeSubscribe(int sock);
    void run() override;

signals:

public slots:

private:
    std::list<std::pair<int,SubNode> > subscribers;//pair<sock,subNode>
    std::mutex mutex;
    volatile bool isQuit;
};

#endif // AGVLOGPROCESS_H