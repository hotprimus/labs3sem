#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProcess>
#include <iostream>
#include "shared_ptr.h"
#include "unique_ptr.h"
#include "weak_ptr.h"


struct TestObject {
    int id;
    TestObject(int i) : id(i) { std::cout << "TestObject(" << id << ") создан.\n"; }
    ~TestObject() { std::cout << "TestObject(" << id << ") уничтожен.\n"; }
    void greet() { std::cout << "Привет от TestObject(" << id << ")!\n"; }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCreateShared_clicked();
    void on_btnCreateUnique_clicked();
    void on_btnCreateWeak_clicked();
    void on_btnRunFunctionalTests_clicked();
    void on_btnRunStressTests_clicked();

    void functionalTestsFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void stressTestsFinished(int exitCode, QProcess::ExitStatus exitStatus);

private:

    QPushButton* btnCreateShared;
    QPushButton* btnCreateUnique;
    QPushButton* btnCreateWeak;
    QPushButton* btnRunFunctionalTests;
    QPushButton* btnRunStressTests;
    QTextEdit* textEditLog;

    shared_ptr<TestObject> sp;
    unique_ptr<TestObject> up;
    weak_ptr<TestObject> wp;

    
    QProcess *functionalTestProcess;
    QProcess *stressTestProcess;

    void logMessage(const QString &message);
};

#endif 
