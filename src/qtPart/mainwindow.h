#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../s21_smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  QObject QObject::*sender() const;
 private slots:
  void digit_pressed();

  void equal_button_pressed();

  void equal_button_plot_pressed();

  void clear_button_pressed();

  void clear_all_button_pressed();

 private:
  Ui::MainWindow *ui;
  //    QString string_print;
  //    QString string_calc;
  double y_begin, y_end, x_begin, x_end, h, X;
  int N;

  //    QVector<double> x,y;
};
#endif  // MAINWINDOW_H
