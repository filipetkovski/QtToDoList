#ifndef LISTFILTERMODEL_H
#define LISTFILTERMODEL_H

#include <QSortFilterProxyModel>

class ListFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool showActive READ showActive WRITE setShowActive NOTIFY showActiveChanged)

public:
    explicit ListFilterModel(QObject *parent = nullptr);

    bool showActive() const;
    void setShowActive(bool active);
    Q_INVOKABLE int sourceIndex(int indX);

signals:
    void showActiveChanged();

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    bool m_showActive;
};

#endif // LISTFILTERMODEL_H
