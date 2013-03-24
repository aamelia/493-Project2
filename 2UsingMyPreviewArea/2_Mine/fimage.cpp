#include "fimage.h"
#include <QtGui>
#include <QWidget>
#include <QLayout>
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>

fimage::fimage(int setIndex, QWidget *parent) : QLabel(parent)
{
    index = setIndex;
}
