#include "mainwindow.h"

#include <QPixmap>

#include "ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  deleteError();
  connect(ui->pushButton_0, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_1, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_2, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_3, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_4, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_5, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_6, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_7, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_8, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_9, &QPushButton::clicked, this,
          &MainWindow::numToText);
  connect(ui->pushButton_equal, &QPushButton::clicked, this,
          &MainWindow::is_result);

  ui->comboBox_type->addItem("annuity");
  ui->comboBox_type->addItem("differentiated");
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::is_result() {
  QString exprassion_result = ui->result_show->text();
  QByteArray exprassionByteArray = exprassion_result.toUtf8();
  char *exprassionPtr = exprassionByteArray.data();

  if (strchr(exprassionPtr, 'x') != NULL)
    ui->result_show->setText("ERROR");
  else if (!validator(exprassionPtr))
    ui->result_show->setText("ERROR");
  else {
    OBJ *top = NULL;
    double result = 0;

    if (!combo_calc(&top, exprassionPtr, 0, &result))
      ui->result_show->setText("ERROR");
    else {
      QString toStr = QString::number(result, 'g', 15);
      ui->result_show->setText(toStr);
    }
  }
}

void MainWindow::on_pushButton_dot_clicked() {
  deleteError();
  if (ui->result_show->text() == "\0") ui->result_show->setText("0");
  ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::on_pushButton_AC_clicked() { ui->result_show->setText("\0"); }

void MainWindow::on_pushButton_plus_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "+");
}

void MainWindow::on_pushButton_open_bracket_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "(");
}

void MainWindow::on_pushButton_close_bracket_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + ")");
}

void MainWindow::on_pushButton_mod_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "mod");
}

void MainWindow::on_pushButton_div_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "/");
}

void MainWindow::on_pushButton_mul_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "*");
}

void MainWindow::on_pushButton_minus_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "-");
}

void MainWindow::numToText() {
  deleteError();
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::deleteError() {
  if (ui->result_show->text() == "ERROR") ui->result_show->setText("\0");
}

void MainWindow::on_pushButton_pow_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "^");
}

void MainWindow::on_pushButton_sqrt_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "sqrt(");
}

void MainWindow::on_pushButton_asin_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "asin(");
}

void MainWindow::on_pushButton_sin_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "sin(");
}

void MainWindow::on_pushButton_cos_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "cos(");
}

void MainWindow::on_pushButton_acos_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "acos(");
}

void MainWindow::on_pushButton_tan_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "tan(");
}

void MainWindow::on_pushButton_atan_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "atan(");
}

void MainWindow::on_pushButton_log_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "log(");
}

void MainWindow::on_pushButton_ln_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "ln(");
}

void MainWindow::on_pushButton_show_graph_clicked() {
  QString exprassion_result = ui->result_show->text();
  QByteArray exprassionByteArray = exprassion_result.toUtf8();
  char *exprassionPtr = exprassionByteArray.data();

  ui->customPlot->addGraph();
  ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
  ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
  ui->customPlot->xAxis->setLabel("X");
  ui->customPlot->yAxis->setLabel("Y");

  QVector<double> x, y;

  for (double i = -50; i < 50 && ui->result_show->text() != "ERROR"; i += 0.5) {
    if (!validator(exprassionPtr))
      ui->result_show->setText("ERROR");
    else {
      OBJ *top = NULL;
      double result = 0;
      top = parser_str(exprassionPtr, top, i);
      top = revers(top);
      top = polish_notation(top);
      top = revers(top);
      if (calculator(&top, &result)) {
        x.push_back(i);
        y.push_back(result);
      }
    }

    ui->customPlot->xAxis->setRange(-10, 10);
    ui->customPlot->yAxis->setRange(-4, 4);
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->replot();
    ui->customPlot->update();

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom |
                                    QCP::iSelectPlottables);
  }
}

void MainWindow::on_pushButton_x_clicked() {
  deleteError();
  ui->result_show->setText(ui->result_show->text() + "x");
}

void MainWindow::on_pushButton_back_clicked() {
  QString text = ui->result_show->text();
  text.chop(1);
  ui->result_show->setText(text);
}

void MainWindow::on_pushButton_show_credit_clicked() {
  QString type_credit = ui->comboBox_type->currentText();

  double number_credit_amount = ui->input_total_credit_amount->value();
  int number_term = ui->input_term->value();
  double interest_rate = ui->input_interes_rate->value();
  double balance_owed = number_credit_amount;

  if (!data_checking(number_credit_amount, number_term, interest_rate))
    ui->status_credit->setText("status: incorrect data");
  else {
    if (type_credit == "annuity")
      annuity_credit(number_credit_amount, number_term, interest_rate,
                     balance_owed);
    else
      differentiated_credit(number_credit_amount, number_term, interest_rate,
                            balance_owed);
    ui->status_credit->setText("status: OK");
  }
}

int MainWindow::data_checking(double number_credit_amount, int number_term,
                              double interest_rate) {
  int code = CODE_TRUE;
  if (number_credit_amount <= 0 || number_term <= 0 || interest_rate <= 0)
    code = CODE_FALSE;

  return code;
}

void MainWindow::annuity_credit(double number_credit_amount, int number_term,
                                double interest_rate, double balance_owed) {
  double sum_interest_payment = 0;
  double monthly_interest_rate = interest_rate / 12 / 100;
  double monthly_fee = number_credit_amount *
                       (monthly_interest_rate +
                        (monthly_interest_rate /
                         (pow(1 + monthly_interest_rate, number_term) - 1)));
  ui->table_credit->setRowCount(number_term);

  for (int i = 0; i < number_term; i++) {
    double interest_payment = balance_owed * monthly_interest_rate;
    sum_interest_payment += interest_payment;
    balance_owed -= monthly_fee - interest_payment;

    ui->table_credit->setItem(
        i, 0, new QTableWidgetItem(QString::number(monthly_fee)));
    ui->table_credit->setItem(
        i, 1,
        new QTableWidgetItem(QString::number(monthly_fee - interest_payment)));
    ui->table_credit->setItem(
        i, 2, new QTableWidgetItem(QString::number(interest_payment)));
    ui->table_credit->setItem(
        i, 3, new QTableWidgetItem(QString::number(balance_owed)));
  }

  ui->output_monthly_payment->setText(QString::number(monthly_fee));
  ui->output_overpayment_on_credit->setText(
      QString::number(sum_interest_payment));
  ui->output_total_payment->setText(QString::number(monthly_fee * number_term));
}

void MainWindow::differentiated_credit(double number_credit_amount,
                                       int number_term, double interest_rate,
                                       double balance_owed) {
  double sum_interest_payment = 0;
  double principal_payment = number_credit_amount / number_term;
  double monthly_interest_rate = interest_rate / 12 / 100;
  double total_payment = 0;
  ui->table_credit->setRowCount(number_term);

  for (int i = 0; i < number_term; i++) {
    double interest_payment = balance_owed * monthly_interest_rate;
    sum_interest_payment += interest_payment;
    balance_owed -= principal_payment;
    total_payment += principal_payment + interest_payment;

    ui->table_credit->setItem(i, 0,
                              new QTableWidgetItem(QString::number(
                                  principal_payment + interest_payment)));
    ui->table_credit->setItem(
        i, 1, new QTableWidgetItem(QString::number(principal_payment)));
    ui->table_credit->setItem(
        i, 2, new QTableWidgetItem(QString::number(interest_payment)));
    ui->table_credit->setItem(
        i, 3, new QTableWidgetItem(QString::number(balance_owed)));

    if (i == 0)
      ui->output_monthly_payment->setText(
          QString::number(principal_payment + interest_payment));
    if (i == number_term - 1)
      ui->output_monthly_payment->setText(
          ui->output_monthly_payment->text() + " ... " +
          QString::number(principal_payment + interest_payment));
  }

  ui->output_overpayment_on_credit->setText(
      QString::number(sum_interest_payment));
  ui->output_total_payment->setText(QString::number(total_payment));
}
