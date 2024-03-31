#ifndef TRAFFIC_LIGHTS_H
#define TRAFFIC_LIGHTS_H

void init(unsigned char *light);
void turn_on(unsigned char *light, unsigned char light_num);
void turn_off(unsigned char *light, unsigned char light_num);
void next_step(unsigned char *light);
void reverse(unsigned char *light);
void swap(unsigned char *l1, unsigned char *l2);

#endif /* !TRAFFIC_LIGHTS_H */
