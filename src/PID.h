#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error = 0;
  double i_error = 0;
  double d_error = 0;

  /*
  * Coefficients
  */
  double Kp = 0; // 0.34   0.34   0.34   0.31   0.31   0.27   0.22   0.27   0.22
  double Ki = 0; // 0.0003 0.0001 0.0001 0.0001 0.0001 0.0001 0.0001 0.0001 0.0001
  double Kd = 0; // 2.20   2.20   1.80   1.50   1.20   1.00   1.00   0.90   0.90
                 // 0.0236 0.0228 0.033  0.031  0.035  0.044  0.055  0.058  0.050
  double sum_cte = 0;
  double prev_cte = 0;
  double total_err = 0;
  int step_count = 0;

  long long prev_timestamp = 0;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
