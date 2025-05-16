#include "kalman_filter.h"

void kalman_filter_init(KalmanFilter *kf) {
	kf->q_angle = 0.001f;
	kf->r_measure = 0.03f;
	kf->angle = 0.0f;

	kf->p[0][0] = 0.0f;
	kf->p[0][1] = 0.0f;
	kf->p[1][0] = 0.0f;
	kf->p[1][1] = 0.0f;
}

float kalman_filter_get_angle(KalmanFilter *kf, float new_angle, float dt) {
	kf->angle += 0.0f;

	kf->p[0][0] += dt * (dt * kf->p[1][1] - kf->p[0][1] - kf->p[1][0] + kf->q_angle);
	kf->p[0][1] -= dt * kf->p[1][1];
	kf->p[1][0] -= dt * kf->p[1][1];
	kf->p[1][1] += 0.0f;

	float s = kf->p[0][0] + kf->r_measure;
	float k0 = kf->p[0][0] / s;
	float k1 = kf->p[1][0] / s;

	float y = new_angle - kf->angle;
	kf->angle += k0 * y;

	float p00_temp = kf->p[0][0];
	float p01_temp = kf->p[0][1];

	kf->p[0][0] -= k0 * p00_temp;
	kf->p[0][1] -= k0 * p01_temp;
	kf->p[1][0] -= k1 * p00_temp;
	kf->p[1][1] -= k1 * p01_temp;

	return kf->angle;
}
