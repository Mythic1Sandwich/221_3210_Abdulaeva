#include "gameboard.h"
#include "mainwindow.h"
#include <QRandomGenerator>

GameBoard::GameBoard(QWidget *parent) : QWidget(parent), gridLayout(new QGridLayout(this)) {
    for (int i = 0; i < 3; ++i) {
        QLineEdit *newPromoCard = new QLineEdit(this);
        newPromoCard->setEchoMode(QLineEdit::Password);
        newPromoCard->setReadOnly(true);
        gridLayout->addWidget(newPromoCard, i / 3, i % 3);

        std::string promoCode = MainWindow::generateRandomString(4);
        promoCodes.push_back(promoCode);
        newPromoCard->setText(QString::fromStdString(promoCode));
        promoCards.push_back(newPromoCard);
    }

    revealButton = new QPushButton("Открыть промокод", this);
    connect(revealButton, &QPushButton::clicked, this, &GameBoard::onRevealButtonClicked);
    gridLayout->addWidget(revealButton, 3, 1);
}

void GameBoard::onRevealButtonClicked() {

    if (!promoCards.empty()) {
        int randomIndex = QRandomGenerator::global()->bounded(promoCards.size());
        promoCards[randomIndex]->setEchoMode(QLineEdit::Normal);
        promoCards[randomIndex]->setText(QString::fromStdString(promoCodes[randomIndex]));
    }

    if (promoCards.size() < 9) {
        addNewPromoCard();
    }
}

void GameBoard::addNewPromoCard() {
    QLineEdit *newPromoCard = new QLineEdit(this);
    newPromoCard->setEchoMode(QLineEdit::Password);
    newPromoCard->setReadOnly(true);

    std::string promoCode = MainWindow::generateRandomString(4);
    promoCodes.push_back(promoCode);
    newPromoCard->setText(QString::fromStdString(promoCode));

    int newCardIndex = promoCards.size();
    gridLayout->addWidget(newPromoCard, newCardIndex / 3, newCardIndex % 3);
    promoCards.push_back(newPromoCard);
}

GameBoard::~GameBoard() {

}
