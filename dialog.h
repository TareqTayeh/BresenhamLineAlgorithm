/* Name: Tareq Tayeh
 * Student Number: 250725776
 * Course: CS3388A Computer Graphics
 * Assignment Number: Assignment #1
 * Date: 23 September 2017
 * Program purpose: The purpose of this program is to open a window of a specific size and address
 *                  pixels within it, drawing lines using Bresenham's integer line drawing algorithm.
 * File: dialog.h
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QKeyEvent>
#include <QtGui>
#include <QtCore>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void keyPressEvent(QKeyEvent *event);

protected:
    void paintEvent(QPaintEvent *e);
    void Bresenham( int x1, int y1, int x2, int y2);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
