/* Name: Tareq Tayeh
 * Student Number: 250725776
 * Course: CS3388A Computer Graphics
 * Assignment Number: Assignment #1
 * Date: 23 September 2017
 * Program purpose: The purpose of this program is to open a window of a specific size and address
 *                  pixels within it, drawing lines using Bresenham's integer line drawing algorithm.
 * File: dialog.cpp
 */

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


/* Author: Tareq Tayeh
 * Date of creation: 20 September 2017
 *
 * Function: keyPressEvent()
 * Parameter:
 *  In: QKeyEvent *event - Any key event when the dialog is open
 *  Out: None
 * Returns: None
 * Desc: Quits the program when the key "q" is pressed
 */
void Dialog::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Q:
        close();
        break;
    default:
        QDialog::keyPressEvent(event);
    }
}

/* Author: Tareq Tayeh
 * Date of creation: 20 September 2017
 *
 * Function: paintEvent()
 * Parameter:
 *  In: QPaintEvent - A paint event when the dialog is open
 *  Out: None
 * Returns: None
 * Desc: Dialog's painter function with the algorithms that then calls the Bresenham function and "paints" the dots
 */
void Dialog::paintEvent(QPaintEvent *e)
{
    double dt, t;
    int x1, y1, x2, y2;

    dt = 2.0*M_PI/200.0 ;
    for (t = 0.0 ; t < 2.0*M_PI;) {
      x1 = 256 + (int)100.0*(1.5*cos(t) - cos(13.0*t)) ;
      y1 = 256 + (int)100.0*(1.5*sin(t) - sin(13.0*t)) ;
      t += dt ;
      x2 = 256 + (int)100.0*(1.5*cos(t) - cos(13.0*t)) ;
      y2 = 256 + (int)100.0*(1.5*sin(t) - sin(13.0*t)) ;
      Bresenham(x1, y1, x2, y2);
    }
}

/* Author: Tareq Tayeh
 * Date of creation: 21 September 2017
 *
 * Function: Bresenham()
 * Parameter:
 *  In: int x1 - coordinate x1 as an integer
 *      int y1 - coordinate y1 as an integer
 *      int x2 - coordinate x2 as an integer
 *      int y2 - coordinate y2 as an integer
 *  Out: None
 * Returns: None
 * Desc: Bresenham's line algorithm, and where the dots are "painted" on the dialog
 */
void Dialog::Bresenham(int x1, int y1, int x2, int y2)
{
  QPainter painter(this);
  int dx, dy, error, ystep, y, maxX;

  const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
  if(steep)
  {
    std::swap(x1, y1);
    std::swap(x2, y2);
  }

  if(x1 > x2)
  {
    std::swap(x1, x2);
    std::swap(y1, y2);
  }

  dx = x2 - x1;
  dy = fabs(y2 - y1);

  error = dx / 2.0f;
  ystep = (y1 < y2) ? 1 : -1;
  y = y1;

  maxX = x2;

  for(int x=x1; x<maxX; x++)
  {
    if(steep)
    {
        painter.drawPoint(y,x);
    }
    else
    {
        painter.drawPoint(x,y);
    }

    error -= dy;
    if(error < 0)
    {
        y += ystep;
        error += dx;
    }
  }
}
