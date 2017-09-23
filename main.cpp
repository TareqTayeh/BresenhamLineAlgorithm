/* Name: Tareq Tayeh
 * Student Number: 250725776
 * Course: CS3388A Computer Graphics
 * Assignment Number: Assignment #1
 * Date: 23 September 2017
 * Program purpose: The purpose of this program is to open a window of a specific size and address
 *                  pixels within it, drawing lines using Bresenham's integer line drawing algorithm.
 * File: main.cpp
 */

#include "dialog.h"
#include <QApplication>

/* Author: Tareq Tayeh
 * Date of creation: 20 September 2017
 *
 * Function: main()
 * Purpose: Instantiates an instance of Dialog, and sets its size, background and shows it.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    w.setFixedSize(512, 512); //Opening a window of size 512 by 512 pixels
    w.setStyleSheet("QWidget { background-color: white; }"); //Setting the window background color to white
    w.show(); //Show dialog

    return a.exec();
}
