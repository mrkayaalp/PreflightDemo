#ifndef SIMPLEKALMAN_H_
#define SIMPLEKALMAN_H_

typedef struct yrt_simpleKalman_t {
    float err_measure;
    float err_estimate;
    float q;
    float current_estimate;
    float last_estimate;
    float kalman_gain;
} yrt_simpleKalman_t;

void yrt_simpleKalman_init(yrt_simpleKalman_t *kalman, float mea_e, float est_e,
                           float q);
float yrt_simpleKalman_updateEstimate(yrt_simpleKalman_t *kalman, float mea);
float yrt_simpleKalman_getEstimate(yrt_simpleKalman_t *kalman);

#endif /* SIMPLEKALMAN_H_ */
