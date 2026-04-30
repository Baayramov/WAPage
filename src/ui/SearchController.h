#pragma once
#include <QObject>
#include <QString>

class SearchController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool   active    READ active    NOTIFY activeChanged)
    Q_PROPERTY(QString query    READ query     NOTIFY queryChanged)
    Q_PROPERTY(int    resultCount READ resultCount NOTIFY resultsChanged)
    Q_PROPERTY(int    currentResult READ currentResult NOTIFY resultsChanged)

public:
    explicit SearchController(QObject* parent = nullptr);

    bool    active()        const { return m_active; }
    QString query()         const { return m_query; }
    int     resultCount()   const { return m_resultCount; }
    int     currentResult() const { return m_currentResult; }

public slots:
    void open();
    void close();
    void setQuery(const QString& q);
    void nextResult();
    void prevResult();

    // From MainWindow
    void onResultReady(int firstIndex, int totalCount);
    void onScrollIndexReady(int messageIndex);

signals:
    void activeChanged();
    void queryChanged();
    void resultsChanged();
    void requestSearch(const QString& query);
    void requestClear();
    void requestScrollToResult(int resultNumber);
    void scrollToIndex(int index);

private:
    bool    m_active        = false;
    QString m_query;
    int     m_resultCount   = 0;
    int     m_currentResult = 0;
};
