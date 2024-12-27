#ifndef TODOFILTERMODEL_H
#define TODOFILTERMODEL_H

#include <QSortFilterProxyModel>

class ToDoFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(bool showActive READ showActive WRITE setShowActive NOTIFY showActiveChanged)

public:
    explicit ToDoFilterModel(QObject *parent = nullptr);

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

#endif // TODOFILTERMODEL_H
