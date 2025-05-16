#ifndef INC_KALMAN_FILTER_H_
#define INC_KALMAN_FILTER_H_

typedef struct {
	float q_angle;
	float r_measure;
	float angle;
	float p[2][2];
} KalmanFilter;

void kalman_filter_init(KalmanFilter*);
float kalman_filter_get_angle(KalmanFilter*, float, float);

#endif // INC_KALMAN_FILTER_H_
