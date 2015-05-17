#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>

#include "starterform.h"
#include "ui_starterform.h"

//QTM_USE_NAMESPACE

#define MAX_LINES_LOGGER 4

StarterForm::StarterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StarterForm)
{
    ui->setupUi(this);
    //ui->widget->setVisible(false);

    ui->logger->setFont(QFont("Cantarell", 10));
    QFontMetrics m(ui->logger->font()) ;
    ui->logger->setFixedHeight(MAX_LINES_LOGGER * m.lineSpacing()+13) ;

    connect(this, SIGNAL(sendMessage(QString)),
            this, SLOT(log(QString)));

    log("Application started");
    log("Available positioning sources: "+QGeoPositionInfoSource::availableSources().join(" "));
    log("Starting location API");
    startLocationAPI();

}

StarterForm::~StarterForm()
{
    delete ui;
}

void StarterForm::on_startButton_clicked()
{
    qDebug() << "coucou";
    emit sendMessage(QString("message"));
    ui->topWidgets->removeWidget(ui->logger);
    ui->topWidgets->removeWidget(ui->startButton);
}

void StarterForm::log(const QString &message)
{
    ui->logger->append(message);

}

void StarterForm::startLocationAPI()
{
 // Obtain the location data source if it is not obtained already
 if (!m_pLocationInfo)
 {
 m_pLocationInfo =
 QGeoPositionInfoSource::createDefaultSource(this);

 //Select positioning method
 m_pLocationInfo->setPreferredPositioningMethods(QGeoPositionInfoSource::NonSatellitePositioningMethods);

 // When the position is changed the positionUpdated function is called
 connect(m_pLocationInfo, SIGNAL (positionUpdated(QGeoPositionInfo)),
 this, SLOT (positionUpdated(QGeoPositionInfo)));

 // Start listening for position updates
 m_pLocationInfo->startUpdates();
 }
}

void StarterForm::positionUpdated(QGeoPositionInfo geoPositionInfo)
{
 if (geoPositionInfo.isValid())
 {
 // Get the current location coordinates
 QGeoCoordinate geoCoordinate = geoPositionInfo.coordinate();
 qreal latitude = geoCoordinate.latitude();
 qreal longitude = geoCoordinate.longitude();

// m_pLabel->setText( QString("Latitude: %1 Longitude: %2").arg(latitude).arg(longitude) );
 log( QString("Latitude: %1 Longitude: %2").arg(latitude).arg(longitude) );
 }
}
