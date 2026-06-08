#include "SearchController.h"

SearchController::SearchController(QObject* parent)
    : QObject(parent)
{}

void SearchController::open()
{
    if (m_active) return;
    m_active = true;
    emit activeChanged();
}

void SearchController::close()
{
    if (!m_active) return;
    m_active        = false;
    m_query         = {};
    m_resultCount   = 0;
    m_currentResult = 0;
    emit activeChanged();
    emit queryChanged();
    emit resultsChanged();
    emit requestClear();
}

void SearchController::setQuery(const QString& q)
{
    if (m_query == q) return;
    m_query         = q;
    m_currentResult = 0;
    m_resultCount   = 0;
    emit queryChanged();
    emit requestSearch(q);
}

void SearchController::nextResult()
{
    if (m_resultCount <= 0) return;
    m_currentResult = (m_currentResult + 1) % m_resultCount;
    emit resultsChanged();
    emit requestScrollToResult(m_currentResult);
}

void SearchController::prevResult()
{
    if (m_resultCount <= 0) return;
    m_currentResult = (m_currentResult - 1 + m_resultCount) % m_resultCount;
    emit resultsChanged();
    emit requestScrollToResult(m_currentResult);
}

void SearchController::onResultReady(int firstIndex, int totalCount)
{
    m_resultCount   = totalCount;
    m_currentResult = 0;
    emit resultsChanged();
    if (firstIndex >= 0)
        emit scrollToIndex(firstIndex);
}

void SearchController::onScrollIndexReady(int messageIndex)
{
    if (messageIndex >= 0)
        emit scrollToIndex(messageIndex);
}
