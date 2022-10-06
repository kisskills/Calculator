#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->button_0, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_1, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_3, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_4, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_5, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_6, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_7, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_8, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_9, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_acos, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_asin, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_atan, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_cos, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sin, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_tan, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_ln, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_log, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sqrt, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_mod, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sum, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sub, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_mul, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_div, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_lbracket, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_rbracket, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_dot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_pow, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_x, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_clear, SIGNAL(pressed()), this,
          SLOT(clear_button_pressed()));
  connect(ui->button_clear_all, SIGNAL(pressed()), this,
          SLOT(clear_all_button_pressed()));
  connect(ui->button_equal, SIGNAL(released()), this,
          SLOT(equal_button_pressed()));

  connect(ui->button_0_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_1_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_2_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_3_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_4_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_5_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_6_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_7_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_8_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_9_plot, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_acos_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_asin_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_atan_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_cos_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sin_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_tan_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_ln_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_log_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sqrt_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_mod_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sum_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_sub_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_mul_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_div_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_lbracket_2, SIGNAL(released()), this,
          SLOT(digit_pressed()));
  connect(ui->button_rbracket_2, SIGNAL(released()), this,
          SLOT(digit_pressed()));
  connect(ui->button_dot_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_pow_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_x_2, SIGNAL(released()), this, SLOT(digit_pressed()));
  connect(ui->button_clear_2, SIGNAL(pressed()), this,
          SLOT(clear_button_pressed()));
  connect(ui->button_clear_all_2, SIGNAL(pressed()), this,
          SLOT(clear_all_button_pressed()));
  connect(ui->button_equal_2, SIGNAL(released()), this,
          SLOT(equal_button_plot_pressed()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digit_pressed() {
  QPushButton *button = qobject_cast<QPushButton *>(QObject::sender());
  ui->input_string_all->setText(ui->input_string_all->text() + button->text());
  ui->input_string_plot->setText(ui->input_string_plot->text() +
                                 button->text());
}

void MainWindow::equal_button_pressed() {
  QString string_calc = ui->input_string_all->text();
  QByteArray str_bit = string_calc.toLocal8Bit();
  char *input_string = str_bit.data();
  if (strcmp(input_string, "")) {
    char buffer_string[INPUT_MAX] = {0};
    mod_to_percent(input_string, buffer_string);
    if (check_string(buffer_string)) {
      ui->input_string_all->setText("INPUT_ERROR");
    } else {
      char output_string[PARSER_MAX] = {0};
      double x = 0.0;
      QString x_val = ui->x_value->text();
      QByteArray x_val_bit = x_val.toLocal8Bit();
      char *x_val_char = x_val_bit.data();

      if (check_x_value(x_val_char)) {
        ui->input_string_all->setText("INPUT ERROR: SET X VALUE");
      } else {
        x = atof(x_val_char);
        djkstra_algorithm(input_string, output_string);
        double res = calculation_algorithm(output_string, x);
        QString res_str = QString::number(res, 'g', 7);
        ui->input_string_all->setText(res_str);
      }
    }
  }
}

void MainWindow::equal_button_plot_pressed() {
  QVector<double> x, y;
  QString string_calc = ui->input_string_plot->text();
  QByteArray str_bit = string_calc.toLocal8Bit();
  char *input_string = str_bit.data();
  if (strcmp(input_string, "")) {
    char buffer_string[INPUT_MAX] = {0};
    mod_to_percent(input_string, buffer_string);
    if (check_string(buffer_string)) {
      ui->input_string_plot->setText("INPUT_ERROR");
    } else {
      char output_string[PARSER_MAX] = {0};
      QString x_range = ui->x_max->text();
      QByteArray x_range_bit = x_range.toLocal8Bit();
      char *x_range_char = x_range_bit.data();
      QString y_range = ui->y_max->text();
      QByteArray y_range_bit = y_range.toLocal8Bit();
      char *y_range_char = y_range_bit.data();

      if (check_x_value(x_range_char) || check_x_value(y_range_char)) {
        ui->input_string_plot->setText("INPUT ERROR: x or y range");
      } else {
        djkstra_algorithm(input_string, output_string);
        x_end = abs(atof(x_range_char));
        x_begin = -x_end;
        y_end = abs(atof(y_range_char));
        y_begin = -y_end;
        h = 0.1;
        ui->plot_graph->xAxis->setRange(x_begin - 1, x_end + 1);
        ui->plot_graph->yAxis->setRange(y_begin - 1, y_end + 1);
        N = (x_end - x_begin) / h + 2;
        for (X = x_begin; X <= x_end; X += h) {
          x.push_back(X);
          y.push_back(calculation_algorithm(output_string, X));
        }
        ui->plot_graph->addGraph();
        ui->plot_graph->graph(0)->addData(x, y);
        ui->plot_graph->replot();
        ui->plot_graph->graph(0)->data()->clear();
      }
    }
  }
}

void MainWindow::clear_button_pressed() {
  ui->input_string_all->backspace();
  ui->input_string_plot->backspace();
}

void MainWindow::clear_all_button_pressed() {
  ui->input_string_all->setText("");
  ui->input_string_plot->setText("");
}
