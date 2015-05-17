#ifndef STARTERFORM_H
#define STARTERFORM_H

#include <QWidget>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>

namespace Ui {
class StarterForm;
}

class StarterForm : public QWidget
{
    Q_OBJECT

public:
    explicit StarterForm(QWidget *parent = 0);
    ~StarterForm();

signals:
    void sendMessage(const QString &message);

public slots:
    void on_startButton_clicked();
    void log(const QString &message);
    void positionUpdated(QGeoPositionInfo geoPositionInfo);

private:
    Ui::StarterForm *ui;
    QGeoPositionInfoSource *m_pLocationInfo;
    void startLocationAPI();
};

#endif // STARTERFORM_H
