/***************************************************************************
                                labeldialog.h
                               ---------------
    begin                : Thu Dec 09 2004
    copyright            : (C) 2004 by Michael Margraf
    email                : michael.margraf@alumni.tu-berlin.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef LABELDIALOG_H
#define LABELDIALOG_H

#include <QDialog>
#include <QRegExp>
#include <QGridLayout>
#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

class QLabel;
class QLineEdit;
class QPushButton;
class QGridLayout;
class QRegularExpressionValidator;
class WireLabel;
class QRegularExpression;


class LabelDialog : public QDialog  {
Q_OBJECT
public:
  LabelDialog(WireLabel*, QWidget *parent=0);
 ~LabelDialog();

  QLineEdit  *NodeName, *InitValue;

private slots:
  void slotExtend();
  void slotOk();
  void slotCancel();

private:
  QPushButton *ButtonOk, *ButtonCancel, *ButtonMore;
  QGridLayout *gbox;
  QRegularExpressionValidator *Validator1, *Validator2;
  QRegularExpression      Expr1, Expr2;
  QLabel      *Label2;

  WireLabel *pLabel;
};

#endif
