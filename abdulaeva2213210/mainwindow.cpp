#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameboard.h"

#include <random>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->edtPin, &QLineEdit::returnPressed, this, &MainWindow::onLoginButtonClicked);
    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::onLoginButtonClicked);

    gameBoard = nullptr;
}



std::string MainWindow::generateRandomString(size_t length) {
    const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string randomString;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);

    for (size_t i = 0; i < length; ++i) {
        randomString += charset[dist(rng)];
    }

    return randomString;
}
void MainWindow::onLoginButtonClicked() {
    QString pinCode = ui->edtPin->text();
    if (pinCode == "1234") {
        if (!gameBoard) {
            gameBoard = new GameBoard(this);
            ui->stackedWidget->addWidget(gameBoard);
        }
        ui->stackedWidget->setCurrentWidget(gameBoard);
    } else {
        ui->lblLogin->setText("Неверный пинкод");
        ui->lblLogin->setStyleSheet("color:red;");

        ui->edtPin->clear();
        ui->edtPin->setFocus();
    }
}


MainWindow::~MainWindow() {
    delete ui;
    if (gameBoard) {
        delete gameBoard;
    }
}
