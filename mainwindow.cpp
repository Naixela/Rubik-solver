#include "mainwindow.h"

MainWindow::MainWindow()
{
    // G�n�ration des widgets de la fen�tre principale
    creerActions();
    creerMenus();
    creerBarresOutils();
    creerBarreEtat();

    //D�finition de la fenetre principale
    setMaximumSize(400,240);
    setMinimumSize(400,240);
    setWindowTitle("Projet SDD: R�solution Rubik's cube");


}
MainWindow::~MainWindow()
{

}

/* M�thodes d'initialisation de la GUI */
void MainWindow::creerActions()
{
    actionOuvrirFichier = new QAction(tr("&Ouvrir Fichier"), this);
    actionOuvrirFichier->setShortcut(tr("Ctrl+T"));
    //connect(actionOuvrirFichier, SIGNAL(triggered()), this, SLOT(ouvrirFichier()));

    actionLancer = new QAction(tr("&Lancer"), this);
    actionLancer->setShortcut(tr("Ctrl+N"));
    //connect(actionLancer, SIGNAL(triggered()), this, SLOT(lancer()));

    actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut((tr("Ctrl+Q")));
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    actionOptions = new QAction("&Options", this);
    //connect(actionOptions, SIGNAL(triggered()), this, SLOT(ouvrirOptions()));

    actionPropos = new QAction("&� propos du projet", this);
    //connect(actionPropos, SIGNAL(triggered()), this, SLOT(ouvrirPropos()));



}
void MainWindow::creerMenus()
{
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
        menuFichier->addAction(actionOuvrirFichier);
        menuFichier->addAction(actionLancer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
          menuEdition->addAction(actionOptions);

    QMenu *menuAPropos = menuBar()->addMenu("&?");
           menuAPropos->addAction(actionPropos);
}
void MainWindow::creerBarresOutils()
{
    QToolBar *toolBarNavigation = addToolBar(tr("Navigation"));

        toolBarNavigation->addAction(actionOuvrirFichier);
        toolBarNavigation->addAction(actionOptions);
        toolBarNavigation->addAction(actionLancer);
        toolBarNavigation->addAction(actionQuitter);
}
void MainWindow::creerBarreEtat()
{
  /*  barreEtat = statusBar();//D�finition de la barre d'�tat
    messageStatus = new QLabel;//D�finition du message d'�tat
    barreEtat->addWidget(messageStatus);

    progression = new QProgressBar(this);
    progression->setAlignment(Qt::AlignRight);
    progression->setVisible(false);
    progression->setMaximumHeight(14);
    statusBar()->addWidget(progression, 1);*/
}
