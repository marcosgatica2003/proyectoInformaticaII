#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);

    QLabel *titulo = new QLabel("Sistema de Seguridad para Cámaras Frigoríficas", this);
    titulo->setAlignment(Qt::AlignHCenter);

    QFont fuenteTitulo;
    fuenteTitulo.setPointSize(16);
    titulo->setFont(fuenteTitulo);
    titulo->setStyleSheet("QLabel { border: 2px solid black; padding: 5px; } " );

    QLabel *velocidadSerieLabel = new QLabel("Velocidad puerto serie:", this);
    QLabel *alarmaUnoLabel = new QLabel("Tiempo alarma 1:", this);
    QLabel *alarmaDosLabel = new QLabel("Tiempo alarma 2:", this);
    QLabel *temperaturaLabel = new QLabel("Temperatura de la cámara:", this);

    QString styleLabel = "QLabel { border: 2px solid black; padding: 5px; } ";
    velocidadSerieLabel->setStyleSheet(styleLabel);
    alarmaUnoLabel->setStyleSheet(styleLabel);
    alarmaDosLabel->setStyleSheet(styleLabel);
    temperaturaLabel->setStyleSheet(styleLabel);

    QFont fuente;
    fuente.setPointSize(12);
    velocidadSerieLabel->setFont(fuente);
    alarmaUnoLabel->setFont(fuente);
    alarmaDosLabel->setFont(fuente);
    temperaturaLabel->setFont(fuente);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(titulo);
    hLayout->addStretch();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(hLayout);
    layout->addStretch();
    layout->addWidget(velocidadSerieLabel);
    layout->addWidget(alarmaUnoLabel);
    layout->addWidget(alarmaDosLabel);
    layout->addWidget(temperaturaLabel);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    centralWidget->setStyleSheet("background-color: #ADD8E6;");
    setCentralWidget(centralWidget);
}

mainWindow::~mainWindow()
{
    delete ui;
}
