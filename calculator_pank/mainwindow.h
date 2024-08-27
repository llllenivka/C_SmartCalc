#ifndef MAINWINDOW_H
#define MAINWINDOW_H

extern "C" {
#include "../s21_smart_calc.h"
}

#include <QMainWindow>
#include <QVector>

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

 private:
  Ui::MainWindow *ui;

 private slots:
  void on_pushButton_dot_clicked();
  void on_pushButton_AC_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_open_bracket_clicked();
  void on_pushButton_close_bracket_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_mul_clicked();
  void on_pushButton_minus_clicked();
  void numToText();
  void is_result();
  void deleteError();
  void on_pushButton_pow_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_show_graph_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_back_clicked();
  void on_pushButton_show_credit_clicked();
  void annuity_credit(double number_credit_amount, int number_term,
                      double interest_rate, double balance_owed);
  int data_checking(double number_credit_amount, int number_term,
                    double interest_rate);
  void differentiated_credit(double number_credit_amount, int number_term,
                             double interest_rate, double balance_owed);
};
#endif  // MAINWINDOW_H
