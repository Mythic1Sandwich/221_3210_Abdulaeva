// gameboard.h
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <vector>
#include <string>
class GameBoard : public QWidget {
    Q_OBJECT

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();
    void generatePromoCodes(int count);
    void addNewPromoCard();
private slots:
    void onRevealButtonClicked();


private:
    QGridLayout *gridLayout;
    std::vector<QLineEdit*> promoCards;
    std::vector<std::string> promoCodes;
    QPushButton *revealButton;
};


#endif // GAMEBOARD_H
