#include "PID.h"
#include <iostream>
#include <math.h>
#include <chrono>


using namespace std;
long long now() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
  Kp = _Kp;
  Ki = _Ki;
  Kd = _Kd;
  prev_timestamp = now();
}

void PID::UpdateError(double cte) {
  if (step_count >= 400) {
    total_err += fabs(cte);
  }
  step_count++;
  long long t = now();
  double dt = double(t - prev_timestamp) / 1000.0;
  prev_timestamp = t;
  d_error = (cte - p_error) / dt;
  p_error = cte;
  i_error += cte;
  std::cout << t << ", " << (step_count-1) << ", " << p_error << ", " << i_error << ", " << d_error << ", ";
}

double PID::TotalError() {
  double p = -Kp * p_error;
  double i = -Ki * i_error;
  double d = -Kd * d_error;
  double avg_err = total_err/(double)(step_count - 400);
  double total = p + i + d;
  std::cout << p << ", " << i << ", " << d << ", " << total << ", " << avg_err << ", ";

  return total;
}

